#include "input_report_dialog.h"
#include "ui_input_report_dialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

InputReportDialog::InputReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputReportDialog)
{
    ui->setupUi(this);
    QRegularExpression russianRegex("^[а-яА-ЯёЁ-]+$");
    QIntValidator *numberValidator = new QIntValidator(1, 1000, this);
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(russianRegex, this);
    ui->NumberReportEditLine->setValidator(numberValidator);
    ui->SurnameEditLine->setValidator(nameValidator);
    ui->NameEditLine->setValidator(nameValidator);
    ui->PatronymicEditLine->setValidator(nameValidator);

    ui->NumberReportEditLine->setMaxLength(4);
    ui->SurnameEditLine->setMaxLength(50);
    ui->NameEditLine->setMaxLength(50);
    ui->PatronymicEditLine->setMaxLength(50);
    ui->NumberReportEditLine->setMaxLength(4);

    connect(ui->AddReportButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CanelButton, &QPushButton::clicked, this, &QDialog::reject);
}

InputReportDialog::~InputReportDialog()
{
    delete ui;
}

void InputReportDialog::on_DescriptionTextEdit_textChanged()
{
    const int MAX_LENGTH = 100; // Твой лимит символов

    // 1. Проверяем, превысил ли пользователь лимит
    if (ui->DescriptionTextEdit->toPlainText().length() > MAX_LENGTH) {

        // 2.временно отключаем сигналы виджета.
        ui->DescriptionTextEdit->blockSignals(true);

        // 3. Забираем текст, обрезаем ровно до лимита
        QString text = ui->DescriptionTextEdit->toPlainText();
        text.truncate(MAX_LENGTH);

        ui->DescriptionTextEdit->setPlainText(text);

        QTextCursor cursor = ui->DescriptionTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->DescriptionTextEdit->setTextCursor(cursor);

        ui->DescriptionTextEdit->blockSignals(false);
    }
}

int InputReportDialog::getNumberReport() const {
    return ui->NumberReportEditLine->text().toInt();
}

QString InputReportDialog::getSurname() const {
    return ui->SurnameEditLine->text().trimmed();
}

QString InputReportDialog::getName() const {
    return ui->NameEditLine->text().trimmed();
}

QString InputReportDialog::getPatronymic() const {
    return ui->PatronymicEditLine->text().trimmed();
}

QString InputReportDialog::getDescription() const {
    return ui->DescriptionTextEdit->toPlainText().trimmed();
}
