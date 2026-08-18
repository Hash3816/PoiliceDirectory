#pragma once
#include <QMainWindow>
#include "report_table_model.h"
#include <QCloseEvent>
#include "investigation_directory.h"

namespace Ui {
class ReportDirectoryWindow;
}

class ReportDirectory : public QMainWindow
{
    Q_OBJECT

public:
     InvestigationDirectory* ptr_investigation_directory;
    explicit ReportDirectory(QWidget *parent = nullptr);
    ~ReportDirectory();


protected:
     void closeEvent(QCloseEvent *event) override;




private:
    Ui::ReportDirectoryWindow* ui;
    ReportTableModel* table_view_model; // Указатель на модель таблицы



private slots:
    void on_actionLoadDirectoryReport_triggered();
    void on_actionSaveDirectoryReport_triggered();
    void on_actionAddReport_triggered();

    void on_actionEraseDirectory_triggered();

    void on_actionFindReportByNumber_triggered();

    void on_actionPrintStructures_triggered();
    void on_actionPrintHashTable_triggered();
    void on_actionPrintReports_triggered();

    void on_actionFilter_triggered();

    void on_actionDeleteReport_triggered();

    void on_actionEditCapacity_triggered();

    void mousePressEvent(QMouseEvent *event) override;
};