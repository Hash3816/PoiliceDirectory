#ifndef INVESTIGATIONSWINDOW_H
#define INVESTIGATIONSWINDOW_H

#include <QMainWindow>
#include "DataService.h"
namespace Ui {
class InvestigationsWindow;
}

class InvestigationsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InvestigationsWindow(DataService& data_service, QWidget *parent = nullptr);
    ~InvestigationsWindow();

private:
    DataService& data_service;
    Ui::InvestigationsWindow *ui;
};

#endif // INVESTIGATIONSWINDOW_H
