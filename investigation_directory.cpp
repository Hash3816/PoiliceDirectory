#include "investigation_directory.h"
#include "ui_investigation_directory.h"
#include <QMessageBox>
#include "DataService.h"
#include "investigation_table_model.h"
#include <QFileDialog>
#include <QMenu>
#include <QToolButton>
#include "window_show_structures.h"

InvestigationDirectory::InvestigationDirectory(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InvestigationDirectoryWindow)
{
    ui->setupUi(this);

    DataService& data_service = DataService::get_instance();

    table_view_model = new InvestigationTableModel(data_service.get_investigations_storage(), this);
    ui->InvestigationsDirectoryTable->setModel(table_view_model); //Привязываем таблицу к  ui
    ui->InvestigationsDirectoryTable->verticalHeader()->setVisible(true);
    ui->InvestigationsDirectoryTable->setColumnWidth(0, 120);
    ui->InvestigationsDirectoryTable->setColumnWidth(1, 200);
    ui->InvestigationsDirectoryTable->setColumnWidth(2, 150);
    ui->InvestigationsDirectoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->InvestigationsDirectoryTable->horizontalHeader()->setStretchLastSection(true);
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
    if(!data_service.get_reports_storage().empty()){
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

    try {
        std::string stdPath = filePath.toLocal8Bit().constData();

        data_service.load_investigations_from_file(stdPath);

        table_view_model->updateData();
        QApplication::restoreOverrideCursor();
        QMessageBox::information(this, "Успех", (QString::number(data_service.get_investigations_storage().get_size()) + " следствий успешно загружено."));
    }
    catch (const std::runtime_error& e) {
        QApplication::restoreOverrideCursor();

        QMessageBox::critical(this, "Ошибка загрузки файла",
                              QString("Некорректные данные:\n%1").arg(e.what()));
        data_service.clear_investigations_directory();
    }
    catch (...) {
        QApplication::restoreOverrideCursor();

        QMessageBox::critical(this, "Ошибка загрузки файла",
                              "Произошла ошибка при парсинге файла.");
        data_service.clear_investigations_directory();
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

void InvestigationDirectory::on_actionAddInvestigation_triggered(){};



void InvestigationDirectory::on_actionFindInvestigationsByNumber_triggered(){}







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
    dialog.setWindowTitle("Дерево дат возбуждения заявлений");
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

