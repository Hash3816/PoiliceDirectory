#include "reportdirectory.h"
#include "ui_reportdirectory.h"
#include "inputreportdialog.h"
#include "DataService.h"
#include "windowshowstructures.h"
#include "structures.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>
#include <QInputDialog>
#include <QToolButton>
#include "showtableview.h"


ReportDirectory::ReportDirectory(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ReportDirectoryWindow)
{
    ui->setupUi(this);

    DataService& data_service = DataService::get_instance();
    table_view_model = new ReportTableModel(data_service.get_reports_storage(), this);
    ui->ReportsDirectoryTable->setModel(table_view_model);
    ui->ReportsDirectoryTable->setColumnWidth(0, 50);
    ui->ReportsDirectoryTable->setColumnWidth(1, 120);
    ui->ReportsDirectoryTable->setColumnWidth(2, 200);
    ui->ReportsDirectoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->ReportsDirectoryTable->horizontalHeader()->setStretchLastSection(true);

    // ui->ReportsDirectoryTable->setWordWrap(true);
    // ui->ReportsDirectoryTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

ReportDirectory::~ReportDirectory()
{
    delete ui;
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
        QApplication::restoreOverrideCursor();

        QMessageBox::critical(this, "Ошибка загрузки файла",
                              QString("Произошла ошибка при чтении данных:\n%1").arg(e.what()));
        data_service.clear_reports_directory();
    }
    catch (...) {
        QApplication::restoreOverrideCursor();

        QMessageBox::critical(this, "Ошибка загрузки файла",
                              "Произошла ошибка при парсинге файла.");
         data_service.clear_reports_directory();
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

    input_dialog.setWindowTitle("Добавление новой заявки");

    // 2. Вызываем окно в модальном режиме и проверяем, нажал ли пользователь "Добавить"
    if (input_dialog.exec() == QDialog::Accepted) {

        // 3. Извлекаем данные из полей с помощью созданных геттеров
        int number = input_dialog.getNumberReport();
        std::string surname = input_dialog.getSurname().toStdString();
        std::string name = input_dialog.getName().toStdString();
        std::string patronymic = input_dialog.getPatronymic().toStdString();
        std::string description = input_dialog.getDescription().toStdString();

        // Простая валидация: проверим, что обязательные поля не пустые
        if (surname.empty() || name.empty() || description.empty()) {
            QMessageBox::warning(this, "Ошибка", "Попытка отправки пустой строки");
            return;
        }

        if(data_service.get_reports_storage().get_size() == 9999){
            QMessageBox::warning(this, "Ошибка", "Справочник переполнен. Добавить заявление невозможно");
            return;
        }

        try{
        FullName applicant = FullName(surname, name, patronymic);
        PoliceReport report = PoliceReport(number, applicant, description);
        data_service.add_report(report);
        }
        catch(std::exception error){
            QMessageBox::critical(this, "Неверное заполнение полей",
                                  QString("Обнаружена ошибка в заполнении полей:\n%1").arg(error.what()));
            return;
        }

        QMessageBox::information(this, "Сообщение", "Заявление успешно добавлено в справочник.");
        table_view_model->updateData();
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
    dialog.setWindowTitle("Массив заявок");
    dialog.exec();
}

void ReportDirectory::on_actionEditCapacity_triggered(){
    bool ok; // Флаг, который покажет, нажал ли пользователь «ОК» или «Отмена»

    // Получаем текущую вместимость (если у твоего data_service есть геттер, укажи его вместо 10)

    // Вызываем модальное окно для ввода целого числа
    unsigned int new_capacity = QInputDialog::getInt(
        this,
        "Изменение вместимости хеш-таблицы",
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
                QString("Введена некорректная вместимость:\n%1").arg(error.what()));
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

            if(find_report.first == 0){
                QMessageBox::information(this, "Информация", "Заявление не было найдено.");
                return;
            }

            ShowTableView dialog(this);
            dialog.setWindowTitle("Поиск заявлений");
            dialog.set_find_report(find_report.second[0]);

            // 3. Открываем окно в модальном режиме (пока пользователь его не закроет, код дальше не пойдет)
            dialog.exec();


        }
        catch(std::runtime_error error){
            QMessageBox::critical(
                this,
                "Ошибка во время поиска завяления",
                QString("Введенн некорректный номер заявления:\n%1").arg(error.what()));
            return;
        }

    }
}