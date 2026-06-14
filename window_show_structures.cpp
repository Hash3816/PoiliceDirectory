#include "window_show_structures.h"
#include "ui_window_show_structures.h"
#include <QFont>

WindowShowStructures::WindowShowStructures(const QString &text, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowShowStructures)
{
    ui->setupUi(this);

    QFont monoFont("Courier New", 10);
    ui->PrintTextLine->setFont(monoFont);

    ui->PrintTextLine->setPlainText(text);

    unsigned int lineCount = ui->PrintTextLine->document()->blockCount();
    ui->LableInfo->setText(QString("Количество строк: " + QString::number(lineCount - 1)));
}

WindowShowStructures::~WindowShowStructures()
{
    delete ui;
}
