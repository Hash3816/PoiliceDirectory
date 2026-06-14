#ifndef INPUTREPORTDIALOG_H
#define INPUTREPORTDIALOG_H

#include <QDialog>
#include "ui_inputreportdialog.h"

class InputReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputReportDialog(QWidget *parent = nullptr);
    ~InputReportDialog();

    // Публичные геттеры для сбора данных с формы
    int getNumberReport() const;
    QString getSurname() const;
    QString getName() const;
    QString getPatronymic() const;
    QString getDescription() const;

private:
    Ui::InputReportDialog *ui;

private slots:
    void on_DescriptionTextEdit_textChanged();
};
#endif // INPUTREPORTDIALOG_H
