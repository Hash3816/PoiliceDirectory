#include "input_report_dialog.h"
#include "ui_input_report_dialog.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

InputReportDialog::InputReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputReportDialog)
{
    ui->setupUi(this);
    ui->DescriptionTextEdit->installEventFilter(this);

    QRegularExpression russianRegex("^[а-яА-ЯёЁ-]+$");
    QIntValidator* numberValidator = new QIntValidator(1, 9999, this);
    QRegularExpressionValidator* nameValidator = new QRegularExpressionValidator(russianRegex, this);

    ui->NumberReportEditLine->setValidator(numberValidator);
    ui->SurnameEditLine->setValidator(nameValidator);
    ui->NameEditLine->setValidator(nameValidator);
    ui->PatronymicEditLine->setValidator(nameValidator);

    connect(ui->AddReportButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CanelButton, &QPushButton::clicked, this, &QDialog::reject);
}

InputReportDialog::~InputReportDialog()
{
    delete ui;
}

void InputReportDialog::on_DescriptionTextEdit_textChanged()
{
    const int MAX_LENGTH = 100;
    QString currentText = ui->DescriptionTextEdit->toPlainText();

    // 1. Проверяем, если текст превысил лимит
    if (currentText.length() > MAX_LENGTH) {
        ui->DescriptionTextEdit->blockSignals(true);

        // Получаем активный курсор
        QTextCursor cursor = ui->DescriptionTextEdit->textCursor();

        // Вычисляем, сколько символов нужно удалить (если скопировали и вставили сразу много)
        int extraChars = currentText.length() - MAX_LENGTH;

        // Удаляем ровно лишнее количество символов перед курсором
        for (int i = 0; i < extraChars; ++i) {
            cursor.deletePreviousChar();
        }

        ui->DescriptionTextEdit->blockSignals(false);
    }

    // 2. Отдельно проверяем запрет на перевод строки (если он все еще нужен)
    // Обновляем строку, так как она могла измениться выше
    currentText = ui->DescriptionTextEdit->toPlainText();
    if (!currentText.isEmpty() && currentText.endsWith('\n')) {
        ui->DescriptionTextEdit->blockSignals(true);

        QTextCursor cursor = ui->DescriptionTextEdit->textCursor();
        cursor.deletePreviousChar(); // Просто стираем нажатый Enter

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
