#include "showtableview.h"
#include "ui_showtableview.h"
#include "structures.h"

ShowTableView::ShowTableView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowTableView)
{
    ui->setupUi(this);

    model = new QStandardItemModel(0, 1, this);
    model->setHorizontalHeaderLabels({" "});
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

ShowTableView::~ShowTableView()
{
    delete ui;
}

// Реализация метода заливки данных
void ShowTableView::set_find_report(const std::reference_wrapper<const PoliceReport> data_find_report)
{
    ui->TextAboutTable->setText("Найденное заявление");
    model->setColumnCount(3);
    model->setRowCount(0);

    model->setHorizontalHeaderLabels({"Номер заявления", "ФИО", "Описание"});
    ui->tableView->setColumnWidth(0, 120);
    ui->tableView->setColumnWidth(1, 200);

    QString report_number = QString::number(data_find_report.get().report_number);
    QString full_name = QString::fromUtf8(full_name_to_string(data_find_report.get().applicant));
    QString description = QString::fromUtf8(data_find_report.get().description);

    QStandardItem *item_report_number = new QStandardItem(report_number);
    QStandardItem *item_full_name = new QStandardItem(full_name);
    QStandardItem *item_descripion = new QStandardItem(description);

    model->insertRow(0, {item_report_number, item_full_name, item_descripion});

}

void ShowTableView::set_find_investigations(const std::vector<std::reference_wrapper<const Investigation>>& data_find_investigations)
{
    model->setColumnCount(4);
    model->setRowCount(0);

    model->setHorizontalHeaderLabels({"Номер заявления", "ФИО следователя", "Статус", "Дата"});

    for(unsigned int i = 0; i < data_find_investigations.size(); i++){
        QString report_number = QString::number(data_find_investigations[i].get().report_number);
        QString full_name = QString::fromUtf8(full_name_to_string(data_find_investigations[i].get().investigator));
        QString status = QString::fromUtf8(status_to_string(data_find_investigations[i].get().investigation_status));
        QString initation_date = QString::fromUtf8(date_to_string(data_find_investigations[i].get().initiation_date));

        QStandardItem *item_report_number = new QStandardItem(report_number);
        QStandardItem *item_full_name = new QStandardItem(full_name);
         QStandardItem *item_status = new QStandardItem(status);
        QStandardItem *item_initation_date = new QStandardItem(initation_date);

         model->insertRow(i, {item_report_number, item_full_name, item_status, item_initation_date});
    }
}

void set_filtered_data(const std::vector<Pair<const PoliceReport&, const Investigation&>>&){};