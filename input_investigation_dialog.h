#ifndef INPUT_INVESTIGATION_DIALOG_H
#define INPUT_INVESTIGATION_DIALOG_H

#include <QDialog>
#include "ui_input_investigation_dialog.h"

class InputInvestigationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputInvestigationDialog(QWidget *parent = nullptr);
    ~InputInvestigationDialog();

    // Публичные геттеры для сбора данных с формы
    int getNumberReport() const;
    QString getSurname() const;
    QString getName() const;
    QString getPatronymic() const;
    QString getStatus() const;
    QString getDateInitation() const;

private:
    Ui::InputInvestigationDialog *ui;

};

#endif // INPUT_INVESTIGATION_DIALOG_H
