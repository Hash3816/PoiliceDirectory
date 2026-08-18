#ifndef INVESTIGATION_DIRECTORY_H
#define INVESTIGATION_DIRECTORY_H

#include <QMainWindow>
#include <QCloseEvent>
#include "investigation_table_model.h"

namespace Ui {
class InvestigationDirectoryWindow;
}

class InvestigationDirectory : public QMainWindow
{
    Q_OBJECT
    friend class ReportDirectory;

public:
    explicit InvestigationDirectory(QWidget *parent = nullptr);
    ~InvestigationDirectory();


protected:
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::InvestigationDirectoryWindow *ui;
    InvestigationTableModel* table_view_model;

private slots:
    void on_actionLoadDirectoryInvestigation_triggered();
    void on_actionSaveDirectoryInvestigation_triggered();
    void on_actionAddInvestigation_triggered();
    void on_actionDeleteInvestigation_triggered();

    void on_actionFindInvestigationsByNumber_triggered();

    void on_actionEraseDirectory_triggered();
    //Удалить следствие
    void on_actionFilter_triggered();
    void on_actionPrintStructures_triggered();
    void on_actionPrintRBTreeReportsNumbers_triggered();
    void on_actionPrintRBTreeDates_triggered();
    void on_actionPrintInvestigations_triggered();

    void mousePressEvent(QMouseEvent *event) override;

};

#endif // INVESTIGATION_DIRECTORY_H
