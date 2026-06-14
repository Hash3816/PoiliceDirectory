#pragma once

#include <QMainWindow>

#include <QMainWindow>
#include "reporttablemodel.h" // Подключаем модель

namespace Ui {
class ReportDirectoryWindow;
}

class ReportDirectory : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportDirectory(QWidget *parent = nullptr);
    ~ReportDirectory();

private:
    Ui::ReportDirectoryWindow* ui;
    ReportTableModel* table_view_model; // Указатель на модель таблицы

private slots:
    void on_actionLoadDirectoryReport_triggered();
    void on_actionSaveDirectoryReport_triggered();
    void on_actionAddReport_triggered();

    void on_actionFindReportByNumber_triggered();

    void on_actionPrintStructures_triggered();
    void on_actionPrintHashTable_triggered();
    void on_actionPrintReports_triggered();

    void on_actionEditCapacity_triggered();
};