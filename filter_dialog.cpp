#include "filter_dialog.h"
#include "ui_filter_dialog.h"
#include "QRegularExpression"
#include "QIntValidator"


FilterDialog::FilterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FilterDialog)
{
    ui->setupUi(this);

    QRegularExpression russianRegex("^[а-яА-ЯёЁ-]+$");
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(russianRegex, this);

    ui->SurnameApplicantEditLine->setValidator(nameValidator);
    ui->NameApplicantEditLine->setValidator(nameValidator);
    ui->PatronymicApplicantEditLine->setValidator(nameValidator);

    connect(ui->AddFilterButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CanelButton, &QPushButton::clicked, this, &QDialog::reject);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}


QString FilterDialog::getSurnameApplicant() const {
    return ui->SurnameApplicantEditLine->text().trimmed();
}

QString FilterDialog::getNameApplicant() const {
    return ui->NameApplicantEditLine->text().trimmed();
}
QString FilterDialog::getPatronymicApplicant() const {
    return ui->PatronymicApplicantEditLine->text().trimmed();
}
QString FilterDialog::getStatus() const {
    return ui->StatusBox->currentText();
}
QString FilterDialog::getDateInitation() const {
    return ui->DateEditLine->text().trimmed();
}