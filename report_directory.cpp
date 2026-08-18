#include "report_directory.h"
#include "ui_report_directory.h"
#include "input_report_dialog.h"
#include "DataService.h"
#include "window_show_structures.h"
#include "structures.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QInputDialog>
#include <QToolButton>
#include "show_table_view.h"
#include <QCloseEvent>
#include "filter_dialog.h"

ReportDirectory::ReportDirectory(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ReportDirectoryWindow)
{
    ui->setupUi(this);
    ptr_investigation_directory = nullptr;

    DataService& data_service = DataService::get_instance();

    table_view_model = new ReportTableModel(data_service.get_reports_storage(), this);
    ui->ReportsDirectoryTable->setModel(table_view_model); //Привязываем таблицу к  ui
    ui->ReportsDirectoryTable->verticalHeader()->setVisible(false);
    ui->ReportsDirectoryTable->setColumnWidth(0, 120);
    ui->ReportsDirectoryTable->setColumnWidth(1, 200);
    ui->ReportsDirectoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ReportsDirectoryTable->horizontalHeader()->setStretchLastSection(true);
    ui->ReportsDirectoryTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->SelectRowText->setText("Строка не выбрана");
    connect(ui->ReportsDirectoryTable, &QTableView::clicked, this, [this](const QModelIndex &index) {
        if (index.isValid()) {
            // Строка выделена
            int rowIndex = index.row();
            ui->SelectRowText->setText(QString("Выбрана строка № %1").arg(rowIndex + 1));
        } else {
            // Кликнули внутрь таблицы, но мимо строк (на белое поле)
            ui->ReportsDirectoryTable->clearSelection();
            ui->SelectRowText->setText("Строка не выбрана");
        }
    });
}



ReportDirectory::~ReportDirectory()
{
    delete ui;
    delete table_view_model;
}

void ReportDirectory::closeEvent(QCloseEvent *event)
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
        event->ignore();
        return;
    }
    qApp->setProperty("isShuttingDown", true);
    event->accept();

    QApplication::quit();
}

void ReportDirectory::mousePressEvent(QMouseEvent *event) {
    // Вызываем базовый класс, чтобы кнопки продолжали нажиматься
    QMainWindow::mousePressEvent(event);

    // Проверяем, куда попал клик. Если кликнули мимо таблицы:
    QPoint childPos = ui->ReportsDirectoryTable->mapFrom(this, event->pos());
    if (!ui->ReportsDirectoryTable->rect().contains(childPos)) {
        ui->ReportsDirectoryTable->clearSelection();
        ui->ReportsDirectoryTable->setCurrentIndex(QModelIndex());
        ui->SelectRowText->setText("Строка не выбрана");
    }
}




void ReportDirectory::on_actionEraseDirectory_triggered(){
    DataService& data_service = DataService::get_instance();
    if(data_service.get_reports_storage().get_size() == 0){
         QMessageBox::information(this, "Сообщение", "Справочник пуст.");
        return;
    }

    if(data_service.get_investigations_storage().get_size() == 0){
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                                  "Подтверждение",
                                                                  "Вы уверены, что хотите отчистить справочник заявлений ?\n"
                                                                  "Все несохранённые данные в справочнике будут стёрты.\n",
                                                                  QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::No){
            return;
        }

        QApplication::setOverrideCursor(Qt::WaitCursor);

        data_service.clear_reports_directory();
        table_view_model->updateData();

        QApplication::restoreOverrideCursor();
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Подтверждение",
                                                              "Вы уверены, что хотите отчистить справочник заявлений ?\n"
                                                              "Все следствия по  заявлениям также будут стёрты из справочника следствий.\n",
                                                              QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No){
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    data_service.clear_reports_directory();
    data_service.clear_investigations_directory();

    table_view_model->updateData();
    ptr_investigation_directory->table_view_model->updateData();


    QApplication::restoreOverrideCursor();
}


void ReportDirectory::on_actionLoadDirectoryReport_triggered()
{
    DataService& data_service = DataService::get_instance();

    if (!data_service.get_investigations_storage().empty()) {
        QMessageBox::critical(this, "Ошибка",
                              "Невозможно загрузить новый справочник заявлений.\n"
                              "Справочник следствий по предыдущим заявлениям не пуст. Сначала очистите его.");
        return;
    }


    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите файл с заявлениями",
                                                    "",
                                                    "Текстовые файлы (*.txt);;Все файлы (*.*)");

    if (filePath.isEmpty()) {
        return;
    }
    if(!data_service.get_reports_storage().empty()){
        QMessageBox::StandardButton reply = QMessageBox::question(this,
                                      "Подтверждение",
                                      "Вы уверены, что хотите загрузить новый справочник?\n"
                                      "Все несохранённые данные в текущем справочнике будут стёрты.\n",
                                      QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::No){
            return;
        }
        data_service.clear_reports_directory();
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    try {
        std::string stdPath = filePath.toLocal8Bit().constData();

        data_service.load_reports_from_file(stdPath);

        table_view_model->updateData();
        QApplication::restoreOverrideCursor();
        QMessageBox::information(this, "Успех", (QString::number(data_service.get_reports_storage().get_size()) + " заявлений успешно загружено!"));
    }
    catch (const std::runtime_error& e) {
        data_service.clear_reports_directory();
        table_view_model->updateData();

        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Невозможно загрузить данные.",
                              QString("%1").arg(e.what()));
    }
    catch (...) {
         data_service.clear_reports_directory();
         table_view_model->updateData();

        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Ошибка загрузки файла",
                              "Произошла ошибка при загрузке данных из файла.");
    }
}

void ReportDirectory::on_actionSaveDirectoryReport_triggered()
{
    DataService& data_service = DataService::get_instance();

    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Сохранить справочник заявлений", // Заголовок окна
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
        if(data_service.get_reports_storage().empty()){
             QMessageBox::information(this, "Сообщение", "Справочник пуст.");
            QApplication::restoreOverrideCursor();
             return;
        }

        data_service.save_report_directory(stdPath);

        QApplication::restoreOverrideCursor();

        QMessageBox::information(this, "Успех", "Справочник успешно сохранен!");
    }
    catch (const std::exception& error) {
        QApplication::restoreOverrideCursor();
        QMessageBox::critical(this, "Ошибка сохранения", QString("Не удалось сохранить файл:\n%1").arg(error.what()));
    }
}

void ReportDirectory::on_actionAddReport_triggered()
{
    // 1. Создаем объект диалогового окна
    InputReportDialog input_dialog(this);
    DataService& data_service = DataService::get_instance();

    input_dialog.setWindowTitle("Добавление нового заявления");

    // 2. Вызываем окно в модальном режиме и проверяем, нажал ли пользователь "Добавить"
    if (input_dialog.exec() == QDialog::Accepted) {

        // 3. Извлекаем данные из полей с помощью созданных геттеров
        int number = input_dialog.getNumberReport();
        std::string surname = input_dialog.getSurname().toStdString();
        std::string name = input_dialog.getName().toStdString();
        std::string patronymic = input_dialog.getPatronymic().toStdString();
        std::string description = input_dialog.getDescription().toStdString();

        // Простая валидация: проверим, что обязательные поля не пустые
        if (description.empty()) {
            QMessageBox::warning(this, "Ошибка", "Описание не может быть пустым.");
            return;
        }

        if(data_service.get_reports_storage().get_size() == 9999){
            QMessageBox::warning(this, "Ошибка", "Справочник переполнен. Добавить заявление невозможно.");
            return;
        }

        try{
        FullName applicant = FullName(surname, name, patronymic);
        PoliceReport report = PoliceReport(number, applicant, description);
        data_service.add_report(report);
        }
        catch(std::exception error){
            if(error.what() == std::runtime_error("Невозможно вставить дубликат.").what()){
                QMessageBox::critical(this, "Ошибка при добавлении",
                                      QString("%1").arg(error.what()));
                return;
            }
            QMessageBox::critical(this, "Ошибка при заполнении",
                                  QString("%1").arg(error.what()));
            return;
        }

        QMessageBox::information(this, "Сообщение", "Заявление успешно добавлено в справочник.");
        table_view_model->updateData();
    }
}


void ReportDirectory::on_actionDeleteReport_triggered(){
    DataService& data_service = DataService::get_instance();
    if(data_service.get_reports_storage().empty()){
        QMessageBox::information(this, "Сообщение", "Справочник пуст.");
        return;
    }

    QModelIndexList selectedIndexes = ui->ReportsDirectoryTable->selectionModel()->selectedRows();

    if (!selectedIndexes.isEmpty()) {
        QModelIndex selectedRowIndex = selectedIndexes.first();

        int row_index = selectedRowIndex.row();
        const QVariant& variant_report_number = ui->ReportsDirectoryTable->model()->index(row_index, 0).data();
        const QVariant& variant_full_name = ui->ReportsDirectoryTable->model()->index(row_index, 1).data();
        const QVariant& variant_description = ui->ReportsDirectoryTable->model()->index(row_index, 2).data();

        unsigned int report_number = variant_report_number.toInt();
        if(report_number < 1 || report_number > 9999){
            QApplication::restoreOverrideCursor();
            QMessageBox::critical(this, "Ошибка при заполнении", "Некорректный номер заявления.");
            return;
        }


        QString q_full_name = variant_full_name.toString();
        QString q_description = variant_description.toString();
        FullName applicant;
        if (q_description.size() == 0) {
            QMessageBox::warning(this, "Ошибка", "Описание не может быть пустым.");
            return;
        }
        try{
         applicant = validate_full_name(q_full_name);
        }
        catch(std::runtime_error error){
            QMessageBox::critical(this, "Ошибка при заполнении",
                                  QString("%1").arg(error.what()));
            return;
        }

        PoliceReport report = PoliceReport(report_number, applicant, q_description.toStdString());

        QApplication::setOverrideCursor(Qt::WaitCursor);
        Pair<unsigned int, const List<unsigned int>&> find_steps_and_indicies = data_service.find_indicies_investigations_by_report_number(report_number);
        if(find_steps_and_indicies.first != 0){
            QApplication::restoreOverrideCursor();
            QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                                      "Внимание",
                                                                      "Обнаружены следствия по данному зявлению, удаление заявления приведёт к удалению следствий.\n"
                                                                      "Вы уверены что хотите удалить заявление ?\n",
                                                                      QMessageBox::Yes | QMessageBox::No);

            if(reply == QMessageBox::No){
                return;
            }


            QApplication::setOverrideCursor(Qt::WaitCursor);
            try{
                data_service.del_report(report, row_index);
                //Так как лист будет изменяться в процессе удаления, нужно откопировать его элементы чтобы сохранить к ним доступ
                std::vector<unsigned int> temp_vector;
                for(unsigned int index: find_steps_and_indicies.second){
                    temp_vector.push_back(index);
                }

                for(int i = temp_vector.size() - 1; i >= 0; i --){
                    const Investigation& investigation = data_service.get_investigations_storage().get_element(temp_vector[i]);
                    data_service.del_investigation(investigation, temp_vector[i]);
                }
            }
            catch(std::runtime_error error){
                QApplication::restoreOverrideCursor();
                QMessageBox::critical(this, "Ошибка при удалении",
                                      QString("%1").arg(error.what()));
                return;
            }


            table_view_model->updateData();
            ptr_investigation_directory->table_view_model->updateData();


            QApplication::restoreOverrideCursor();
            QMessageBox::information(this, "Сообщение", "Заявление успешно удалено из справочника.");
            return;
        }

        //Если следствий не найдено на заявление
        data_service.del_report(report, row_index);
        table_view_model->updateData();
        QApplication::restoreOverrideCursor();
        QMessageBox::information(this, "Сообщение", "Заявление успешно удалено из справочника.");

    }
    else{
        QMessageBox::warning(this, "Внимание", "Не выделена удаляемая строка таблицы.\n"
                                               "Для удаления сначала нужно выделить строку.");
        return;
    }
}



void ReportDirectory::on_actionFilter_triggered(){
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
            QMessageBox::critical(this, "Ошибка при заполнении",
                                  QString("%1").arg(error.what()));
            setMinimumWidth(350);
            return;
        }
    }
}
void ReportDirectory::on_actionPrintStructures_triggered()
{
    // 1. Создаем меню динамически прямо в момент клика
    QMenu printMenu(this);

    printMenu.addAction(ui->actionPrintHashTable);
    printMenu.addAction(ui->actionPrintReports);

    QToolButton *printBtn = qobject_cast<QToolButton*>(ui->toolBar->widgetForAction(ui->actionPrintStructures));

    if (printBtn) {
        QPoint bottomPos = printBtn->rect().bottomLeft();
        QPoint globalPos = printBtn->mapToGlobal(bottomPos);

        printMenu.exec(globalPos);
    } else {
        printMenu.exec(QCursor::pos());
    }
}

void ReportDirectory::on_actionPrintHashTable_triggered()
{
    DataService& data_service = DataService::get_instance();
    std::string str_hash_table = data_service.hash_table_reports_to_string();
    QString qt_hash_string = QString::fromStdString(str_hash_table);

    WindowShowStructures dialog(qt_hash_string, this);
    dialog.setWindowTitle("Хеш-таблица");
    dialog.exec();
}

void ReportDirectory::on_actionPrintReports_triggered()
{
    DataService& data_service = DataService::get_instance();
    std::string str_array_reports = data_service.storage_reports_to_string();
    QString qt_array_string = QString::fromStdString(str_array_reports);

    WindowShowStructures dialog(qt_array_string, this);
    dialog.setWindowTitle("Массив заявлений");
    dialog.exec();
}

void ReportDirectory::on_actionEditCapacity_triggered(){
    bool ok; // Флаг, который покажет, нажал ли пользователь «ОК» или «Отмена»

    // Получаем текущую вместимость (если у твоего data_service есть геттер, укажи его вместо 10)

    // Вызываем модальное окно для ввода целого числа
    unsigned int new_capacity = QInputDialog::getInt(
        this,
        "Размер хеш-таблицы",
        "Введите новую вместимость таблицы:",
        4,                                  //Значение по умолчанию
        4,                                  // Минимально возможное значение
        39800,                             // Маx при размере 9999 заполненость ~25,6...%
        1,                                 // Шаг ползунка
        &ok                                 // Ссылка на флаг нажатия кнопки
        );

    // Если пользователь ввел число и нажал кнопку «ОК»
    if (ok) {
        try{
        DataService::get_instance().set_capacity_hash_table_reports_directory(new_capacity);
        }
        catch(std::runtime_error error){
            QMessageBox::critical(
                this,
                "Ошибка изменения вместимости хеш-таблицы",
                QString("%1").arg(error.what()));
                return;
            }
        QMessageBox::information(this, "Успех", "Вместимость успешно изменена.");
    }
}

void ReportDirectory::on_actionFindReportByNumber_triggered(){
    bool ok;
    unsigned int report_number = QInputDialog::getInt(
        this,
        "Поиск заявления",
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
            auto find_report = DataService::get_instance().find_report_data(report_number);
            const unsigned int hash = DataService::get_instance().get_hash(report_number);

            if(find_report.first == 0){
                QMessageBox::information(this, "Информация", "Заявление не было найдено.");
                return;
            }

            ShowTableView dialog(this);
            dialog.setWindowTitle("Поиск заявления");
            dialog.set_find_report(find_report.second[0]);
            QMessageBox::information(this, "Заявление найдено", "Заявление найдено.\n"
                                             "Количество шагов поиска: " +QString::number(find_report.first) + "\n" +
                                     "Первичный хеш: " + QString::number(hash));


            // 3. Открываем окно в модальном режиме (пока пользователь его не закроет, код дальше не пойдет)
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