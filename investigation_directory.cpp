#include "investigation_directory.h"
#include "ui_investigation_directory.h"
#include <QMessageBox>
#include "DataService.h"
#include "investigation_table_model.h"
#include <QFileDialog>
#include <QMenu>
#include <QToolButton>
#include <QInputDialog>
#include "show_table_view.h"
#include "window_show_structures.h"
#include "input_investigation_dialog.h"
#include "filter_dialog.h"

InvestigationDirectory::InvestigationDirectory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InvestigationDirectoryWindow)
{
    ui->setupUi(this);

    DataService& data_service = DataService::get_instance();

    table_view_model = new InvestigationTableModel(data_service.get_investigations_storage(), this);
    ui->InvestigationsDirectoryTable->setModel(table_view_model); //Привязываем таблицу к  ui
    ui->InvestigationsDirectoryTable->verticalHeader()->setVisible(false);
     ui->InvestigationsDirectoryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->InvestigationsDirectoryTable->setColumnWidth(0, 120);
    ui->InvestigationsDirectoryTable->setColumnWidth(1, 200);
    ui->InvestigationsDirectoryTable->setColumnWidth(2, 150);
    ui->InvestigationsDirectoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->InvestigationsDirectoryTable->horizontalHeader()->setStretchLastSection(true);

    ui->InvestigationsDirectoryTable->viewport()->installEventFilter(this);

    ui->SelectRowText->setText("Строка не выбрана");
    connect(ui->InvestigationsDirectoryTable, &QTableView::clicked, this, [this](const QModelIndex &index) {
        if (index.isValid()) {
            // Строка выделена
            int rowIndex = index.row();
            ui->SelectRowText->setText(QString("Выбрана строка № %1").arg(rowIndex + 1));
        } else {
            // Кликнули внутрь таблицы, но мимо строк (на белое поле)
            ui->InvestigationsDirectoryTable->clearSelection();
            ui->SelectRowText->setText("Строка не выбрана");
        }
    });
}

InvestigationDirectory::~InvestigationDirectory()
{
    delete ui;
    delete table_view_model;
}

void InvestigationDirectory::closeEvent(QCloseEvent *event)
{
    if (qApp->property("isShuttingDown").toBool()) {
        event->accept();
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Подтверждение",
                                                              "Вы уверены, что хотите закрыть программу?\n"
                                                              "Оба справочника будут закрыты.\n"
                                                              "Все несохранённые данные в справочниках будут стёрты.\n",
                                                              QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No){
        // 2. Явно говорим Qt отменить закрытие окна
        event->ignore();
        return;
    }

    qApp->setProperty("isShuttingDown", true);
    event->accept();

    QApplication::quit();
}

void InvestigationDirectory::mousePressEvent(QMouseEvent *event) {
    // Вызываем базовый класс, чтобы кнопки продолжали нажиматься
    QMainWindow::mousePressEvent(event);

    // Проверяем, куда попал клик. Если кликнули мимо таблицы:
    QPoint childPos = ui->InvestigationsDirectoryTable->mapFrom(this, event->pos());
    if (!ui->InvestigationsDirectoryTable->rect().contains(childPos)) {
        ui->InvestigationsDirectoryTable->clearSelection();
        ui->InvestigationsDirectoryTable->setCurrentIndex(QModelIndex());
        ui->SelectRowText->setText("Строка не выбрана");
    }
}

void InvestigationDirectory::on_actionLoadDirectoryInvestigation_triggered()
{
    DataService& data_service = DataService::get_instance();


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл с следствиями",
                                                    "",
                                                    "Текстовые файлы (*.txt);;Все файлы (*.*)");

    if (filePath.isEmpty()) {
        return;
    }
    if(!data_service.get_investigations_storage().empty()){
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                                  "Подтверждение",
                                                                  "Вы уверены, что хотите загрузить новый справочник?\n"
                                                                  "Все несохранённые данные в текущем справочнике будут стёрты.\n",
                                                                  QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::No){
            return;
        }
        data_service.clear_investigations_directory();
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    std::string stdPath = filePath.toLocal8Bit().constData();
    try{
        data_service.load_investigations_from_file(stdPath);
    }
    catch(std::runtime_error& error){
        data_service.clear_investigations_directory();
        table_view_model->updateData();

        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Невозможно загрузить данные",
                              QString("%1").arg(error.what()));
        return;
    }
    catch(...){
        data_service.clear_investigations_directory();
        table_view_model->updateData();

        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Ошибка при отчистке справочника",
                              QString("Произошла ошибка при отчистке справочника."));
        return;
    }

    table_view_model->updateData();
    QApplication::restoreOverrideCursor();
    QMessageBox::information(this, "Успех", (QString::number(data_service.get_investigations_storage().get_size()) + " следствий успешно загружено."));
}


void InvestigationDirectory::on_actionEraseDirectory_triggered(){
    DataService& data_service = DataService::get_instance();
    if(data_service.get_investigations_storage().get_size() == 0){
        QMessageBox::information(this, "Сообщение", "Справочник пуст.");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Подтверждение",
                                                              "Вы уверены, что хотите отчистить справочник следствий?\n"
                                                              "Все несохранённые данные в справочнике также будут стёрты.\n",
                                                              QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No){
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);


    data_service.clear_investigations_directory();

    table_view_model->updateData();

    QApplication::restoreOverrideCursor();
}

void InvestigationDirectory::on_actionFilter_triggered(){
    // 1. Создаем объект диалогового окна
    FilterDialog input_dialog(this);
    DataService& data_service = DataService::get_instance();

    input_dialog.setWindowTitle("Формирование отчёта");

    // 2. Вызываем окно в модальном режиме и проверяем, нажал ли пользователь "Добавить"
    if (input_dialog.exec() == QDialog::Accepted) {
        std::string surname_applicant = input_dialog.getSurnameApplicant().toStdString();
        std::string name_applicant = input_dialog.getNameApplicant().toStdString();
        std::string patronymic_applicant = input_dialog.getPatronymicApplicant().toStdString();
        std::string s_status = input_dialog.getStatus().toStdString();
        QString date_initation = input_dialog.getDateInitation();




        try{
            FullName applicant = FullName(surname_applicant, name_applicant, patronymic_applicant);
            validate_full_name(applicant);
            Status status = string_to_status(s_status);
            Date date = validate_date_string(date_initation);

            auto find_data = data_service.filter_directories(date, status, applicant);
            if(find_data.size() == 0){
                QMessageBox::information(this, "Информация", "Не найдено информации соответствующей фильтрам.");
                return;
            }

            ShowTableView view_filtered_data;
            view_filtered_data.setWindowTitle("Отчёт");
            view_filtered_data.set_filtered_data(find_data);
            QMessageBox::information(this, "Информация", "Отчёт сформирован.");

            view_filtered_data.exec();
        }
        catch(std::exception error){
            QMessageBox::critical(this, "Ошибка при заполении",
                                  QString("%1").arg(error.what()));
            return;
        }
    }
}


void InvestigationDirectory::on_actionSaveDirectoryInvestigation_triggered()
{
    DataService& data_service = DataService::get_instance();

    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Сохранить справочник следствий", // Заголовок окна
        "",
        "Текстовые файлы (*.txt);;Все файлы (*.*)" // Фильтр расширений
        );


    if (filePath.isEmpty()) {
        return;
    }

    if (!filePath.endsWith(".txt", Qt::CaseInsensitive)) {
        filePath += ".txt";
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    try {
        std::string stdPath = filePath.toLocal8Bit().constData();


        DataService& data_service = DataService::get_instance();
        if(data_service.get_investigations_storage().empty()){
            QMessageBox::information(this, "Сообщение", "Справочник пуст.");
            QApplication::restoreOverrideCursor();
            return;
        }

        data_service.save_investigation_directory_in_file(stdPath);

        QApplication::restoreOverrideCursor();

        QMessageBox::information(this, "Успех", "Справочник успешно сохранен!");
    }
    catch (const std::exception& error) {
        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Ошибка сохранения", QString("Не удалось сохранить файл:\n%1").arg(error.what()));
    }
}

void InvestigationDirectory::on_actionAddInvestigation_triggered(){
    // 1. Создаем объект диалогового окна
    InputInvestigationDialog input_dialog(this);
    DataService& data_service = DataService::get_instance();

    input_dialog.setWindowTitle("Добавление нового следствия");

    // 2. Вызываем окно в модальном режиме и проверяем, нажал ли пользователь "Добавить"
    if (input_dialog.exec() == QDialog::Accepted) {

        // 3. Извлекаем данные из полей с помощью созданных геттеров
        int number = input_dialog.getNumberReport();
        std::string s_surname = input_dialog.getSurname().toStdString();
        std::string s_name = input_dialog.getName().toStdString();
        std::string s_patronymic = input_dialog.getPatronymic().toStdString();
        std::string s_status = input_dialog.getStatus().toStdString();
        QString q_date_initation = input_dialog.getDateInitation();



        if(data_service.get_investigations_storage().get_size() == 9999){
            QMessageBox::warning(this, "Ошибка", "Справочник переполнен. Добавить следствие невозможно");
            return;
        }

        try{
            FullName investigator = FullName(s_surname, s_name, s_patronymic);
            Status status = string_to_status(s_status);
            validate_full_name(investigator);
            Date date = validate_date_string(q_date_initation);
            Investigation investigation = Investigation(number, investigator, status, date);
            data_service.add_investigation(investigation);
        }
        catch(std::exception error){
            QMessageBox::critical(this, "Ошибка при заполении",
                                  QString("%1").arg(error.what()));
            return;
        }

        QMessageBox::information(this, "Сообщение", "Следствие успешно добавлено в справочник.");
        table_view_model->updateData();
    }
}

void InvestigationDirectory::on_actionDeleteInvestigation_triggered(){
    DataService& data_service = DataService::get_instance();
    if(data_service.get_investigations_storage().empty()){
        QMessageBox::information(this, "Сообщение", "Справочник пуст.");
        return;
    }

    QModelIndexList selectedIndexes = ui->InvestigationsDirectoryTable->selectionModel()->selectedRows();

    if (!selectedIndexes.isEmpty()) {
        QModelIndex selectedRowIndex = selectedIndexes.first();

        int row_index = selectedRowIndex.row();

        const QVariant& variant_report_number = ui->InvestigationsDirectoryTable->model()->index(row_index, 0).data();
        const QVariant& variant_full_name = ui->InvestigationsDirectoryTable->model()->index(row_index, 1).data();
        const QVariant& variant_status = ui->InvestigationsDirectoryTable->model()->index(row_index, 2).data();
        const QVariant& variant_date = ui->InvestigationsDirectoryTable->model()->index(row_index, 3).data();

        unsigned int report_number = variant_report_number.toInt();
        if(report_number < 0 || report_number > 9999){
             QMessageBox::critical(this, "Ошибка", "Некорректный номер заявления.");
            return;
        }

        QString q_full_name = variant_full_name.toString();
        QString q_status = variant_status.toString();
        QString q_variant_date = variant_date.toString();

        FullName full_name;
        Status status;
        Date date;
        try{
            full_name = validate_full_name(q_full_name);
            status = string_to_status(q_status.toStdString());
            date = validate_date_string(q_variant_date);
        }
        catch(std::runtime_error error){
            QMessageBox::critical(this, "Ошибка при заполении",
                                  QString("%1").arg(error.what()));
            return;
        }

        Investigation investigator = Investigation(report_number, full_name, status, date);

        QApplication::setOverrideCursor(Qt::WaitCursor);
        Pair<unsigned int, const List<unsigned int>&> find_steps_and_investigation = data_service.find_indicies_investigations_by_report_number(report_number);
        if(find_steps_and_investigation.first == 0){
             QApplication::restoreOverrideCursor();
            QMessageBox::critical(this, "Ошибка при удалении", "Следствие не найдено.");
             return;
        }

        bool is_find_ivestigation = false;
        try{
        for(unsigned int index: find_steps_and_investigation.second){
            const Investigation& find_investigator = data_service.get_investigations_storage().get_element(index);
            if(find_investigator == investigator){
                data_service.del_investigation(find_investigator, index);
                is_find_ivestigation = true;
                break;
            }
        }
        }
        catch(std::runtime_error error){
            QApplication::restoreOverrideCursor();
            QMessageBox::critical(this, "Ошибка при удалении", QString("%1").arg(error.what()));
            return;
        }
        catch(...){
             QApplication::restoreOverrideCursor();
             QMessageBox::critical(this, "Ошибка при удалении", "Обнаружена системная ошибка при поиске следствия.");
            return;
        }

        if(is_find_ivestigation == false){
            QApplication::restoreOverrideCursor();
             QMessageBox::critical(this, "Ошибка при удалении", "Следствие не найдено в списке узла дерева\n с ключом номер заявления.");
            return;
        }

        table_view_model->updateData();
        QApplication::restoreOverrideCursor();
        QMessageBox::information(this, "Сообщение", "Следствие успешно удалено из справочника.");

    }
    else{
        QMessageBox::warning(this, "Внимание", "Не выделена удаляемая строка таблицы.\n"
                                               "Для удаления сначала нужно выделить строку.");
        return;
    }
}



void InvestigationDirectory::on_actionFindInvestigationsByNumber_triggered(){
    bool ok;
    unsigned int report_number = QInputDialog::getInt(
        this,
        "Поиск следствий",
        "Введите номер заявления:",
        1,                                  //Значение по умолчанию
        1,                                  // Минимально возможное значение
        9999,                             // Максимально возможный номер заявки
        1,                                 // Шаг ползунка
        &ok                                 // Ссылка на флаг нажатия кнопки
        );

    // Если пользователь ввел число и нажал кнопку «ОК»
    if (ok) {
        try{
            auto find_investigatons = DataService::get_instance().find_investigations_by_number(report_number);

            if(find_investigatons.first == 0){
                QMessageBox::information(this, "Информация", "Следствий не было найдено.");
                return;
            }

            ShowTableView dialog(this);
            dialog.setWindowTitle("Поиск следствий");
            dialog.set_find_investigations(find_investigatons.second);
            QMessageBox::information(this, "Информация найдена",
                                    "Количество шагов поиска: " + QString::number(find_investigatons.first));

            dialog.exec();

        }
        catch(std::runtime_error error){
            QMessageBox::critical(
                this,
                "Ошибка во время поиска",
                QString("%1").arg(error.what()));
            return;
        }
    }
}




void InvestigationDirectory::on_actionPrintStructures_triggered()
{
    QMenu printMenu(this);

    printMenu.addAction(ui->actionPrintInvestigations);
    printMenu.addAction(ui->actionPrintRBTreeReportsNumbers);
    printMenu.addAction(ui->actionPrintRBTreeDates);

    QToolButton *printBtn = qobject_cast<QToolButton*>(ui->toolBar->widgetForAction(ui->actionPrintStructures));

    if (printBtn) {
        QPoint bottomPos = printBtn->rect().bottomLeft();
        QPoint globalPos = printBtn->mapToGlobal(bottomPos);

        printMenu.exec(globalPos);
    } else {
        printMenu.exec(QCursor::pos());
    }
}

void InvestigationDirectory::on_actionPrintRBTreeReportsNumbers_triggered()
{
    DataService& data_service = DataService::get_instance();
    std::string str_rb_tree = data_service.tree_investigations_to_string();
    QString qt_rb_tree_string = QString::fromStdString(str_rb_tree);

    WindowShowStructures dialog(qt_rb_tree_string, this);
    dialog.setWindowTitle("Дерево номеров заявлений справочника ''следствия''");
    dialog.exec();
}

void InvestigationDirectory::on_actionPrintRBTreeDates_triggered()
{
    DataService& data_service = DataService::get_instance();
    std::string str_rb_tree = data_service.tree_dates_to_string();
    QString qt_rb_tree_string = QString::fromStdString(str_rb_tree);

    WindowShowStructures dialog(qt_rb_tree_string, this);
    dialog.setWindowTitle("Дерево дат возбуждения следствия по заявлениям");
    dialog.exec();
}

void InvestigationDirectory::on_actionPrintInvestigations_triggered()
{
    DataService& data_service = DataService::get_instance();
    std::string str_array_investigations = data_service.storage_investigations_to_string();
    QString qt_array_string = QString::fromStdString(str_array_investigations);

    WindowShowStructures dialog(qt_array_string, this);
    dialog.setWindowTitle("Массив следствий");
    dialog.exec();
}

