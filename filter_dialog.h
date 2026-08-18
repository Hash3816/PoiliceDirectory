#ifndef FILTER_DIALOG_H
#define FILTER_DIALOG_H

#include <QDialog>

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

    QString getSurnameApplicant() const;
    QString getNameApplicant() const;
    QString getPatronymicApplicant() const;
    QString getStatus() const;
    QString getDateInitation() const;

private:
    Ui::FilterDialog *ui;
};

#endif // FILTER_DIALOG_H
