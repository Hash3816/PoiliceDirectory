#include "input_investigation_dialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

InputInvestigationDialog::InputInvestigationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputInvestigationDialog)
{
    ui->setupUi(this);

    QRegularExpression russianRegex("^[а-яА-ЯёЁ-]+$");
    QIntValidator *numberValidator = new QIntValidator(1, 9999, this);
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(russianRegex, this);

    ui->NumberReportEditLine->setValidator(numberValidator);
    ui->SurnameEditLine->setValidator(nameValidator);
    ui->NameEditLine->setValidator(nameValidator);
    ui->PatronymicEditLine->setValidator(nameValidator);

    connect(ui->AddInvestigationButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CanelButton, &QPushButton::clicked, this, &QDialog::reject);
}

InputInvestigationDialog::~InputInvestigationDialog()
{
    delete ui;
}

int InputInvestigationDialog::getNumberReport() const {
    return ui->NumberReportEditLine->text().toInt();
}

QString InputInvestigationDialog::getSurname() const {
    return ui->SurnameEditLine->text().trimmed();
}

QString InputInvestigationDialog::getName() const {
    return ui->NameEditLine->text().trimmed();
}

QString InputInvestigationDialog::getPatronymic() const {
    return ui->PatronymicEditLine->text().trimmed();
}

QString InputInvestigationDialog::getStatus() const {
    return ui->StatusBox->currentText();
}

QString InputInvestigationDialog::getDateInitation() const {
    return ui->DateLineEdit->text().trimmed();
}


