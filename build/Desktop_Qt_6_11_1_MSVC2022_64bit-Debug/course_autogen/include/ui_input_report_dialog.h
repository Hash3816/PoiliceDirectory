/********************************************************************************
** Form generated from reading UI file 'input_report_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_REPORT_DIALOG_H
#define UI_INPUT_REPORT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputReportDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *NumberReportEditLine;
    QLineEdit *SurnameEditLine;
    QLineEdit *NameEditLine;
    QLineEdit *PatronymicEditLine;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QTextEdit *DescriptionTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddReportButton;
    QPushButton *CanelButton;

    void setupUi(QDialog *InputReportDialog)
    {
        if (InputReportDialog->objectName().isEmpty())
            InputReportDialog->setObjectName("InputReportDialog");
        InputReportDialog->resize(697, 555);
        InputReportDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(InputReportDialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(InputReportDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(InputReportDialog);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(InputReportDialog);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setBold(true);
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(InputReportDialog);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        NumberReportEditLine = new QLineEdit(InputReportDialog);
        NumberReportEditLine->setObjectName("NumberReportEditLine");

        verticalLayout->addWidget(NumberReportEditLine);

        SurnameEditLine = new QLineEdit(InputReportDialog);
        SurnameEditLine->setObjectName("SurnameEditLine");
        SurnameEditLine->setClearButtonEnabled(false);

        verticalLayout->addWidget(SurnameEditLine);

        NameEditLine = new QLineEdit(InputReportDialog);
        NameEditLine->setObjectName("NameEditLine");

        verticalLayout->addWidget(NameEditLine);

        PatronymicEditLine = new QLineEdit(InputReportDialog);
        PatronymicEditLine->setObjectName("PatronymicEditLine");

        verticalLayout->addWidget(PatronymicEditLine);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, -1, 8, -1);
        label_5 = new QLabel(InputReportDialog);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        DescriptionTextEdit = new QTextEdit(InputReportDialog);
        DescriptionTextEdit->setObjectName("DescriptionTextEdit");

        verticalLayout_2->addWidget(DescriptionTextEdit);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(15, 15, 15, 15);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AddReportButton = new QPushButton(InputReportDialog);
        AddReportButton->setObjectName("AddReportButton");

        horizontalLayout_5->addWidget(AddReportButton);

        CanelButton = new QPushButton(InputReportDialog);
        CanelButton->setObjectName("CanelButton");

        horizontalLayout_5->addWidget(CanelButton);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(InputReportDialog);

        QMetaObject::connectSlotsByName(InputReportDialog);
    } // setupUi

    void retranslateUi(QDialog *InputReportDialog)
    {
        InputReportDialog->setWindowTitle(QCoreApplication::translate("InputReportDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("InputReportDialog", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("InputReportDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("InputReportDialog", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("InputReportDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        NumberReportEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\247\320\270\321\201\320\273\320\276 \320\276\321\202 1-9999", "1-1000"));
        SurnameEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275\320\276\320\262", "\320\230\320\262\320\260\320\275\320\276\320\262"));
        NameEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275", "\320\230\320\262\320\260\320\275"));
        PatronymicEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", nullptr));
        label_5->setText(QCoreApplication::translate("InputReportDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        DescriptionTextEdit->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\321\217 100 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262", nullptr));
        AddReportButton->setText(QCoreApplication::translate("InputReportDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        CanelButton->setText(QCoreApplication::translate("InputReportDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputReportDialog: public Ui_InputReportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_REPORT_DIALOG_H
