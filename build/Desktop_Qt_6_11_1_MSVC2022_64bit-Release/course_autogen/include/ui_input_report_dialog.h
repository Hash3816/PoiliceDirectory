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
#include <QtWidgets/QFrame>
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
    QLabel *label_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame2;
    QVBoxLayout *verticalLayout;
    QLineEdit *NumberReportEditLine;
    QLineEdit *SurnameEditLine;
    QLineEdit *NameEditLine;
    QLineEdit *PatronymicEditLine;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QTextEdit *DescriptionTextEdit;
    QFrame *frame3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddReportButton;
    QPushButton *CanelButton;

    void setupUi(QDialog *InputReportDialog)
    {
        if (InputReportDialog->objectName().isEmpty())
            InputReportDialog->setObjectName("InputReportDialog");
        InputReportDialog->resize(568, 516);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InputReportDialog->sizePolicy().hasHeightForWidth());
        InputReportDialog->setSizePolicy(sizePolicy);
        InputReportDialog->setMaximumSize(QSize(16777215, 516));
        InputReportDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(InputReportDialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_6 = new QLabel(InputReportDialog);
        label_6->setObjectName("label_6");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout_4->addWidget(label_6);

        frame = new QFrame(InputReportDialog);
        frame->setObjectName("frame");
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        frame1 = new QFrame(frame);
        frame1->setObjectName("frame1");
        verticalLayout_3 = new QVBoxLayout(frame1);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, 5, -1);
        label = new QLabel(frame1);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(frame1);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(frame1);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(frame1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addWidget(frame1);

        frame2 = new QFrame(frame);
        frame2->setObjectName("frame2");
        verticalLayout = new QVBoxLayout(frame2);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName("verticalLayout");
        NumberReportEditLine = new QLineEdit(frame2);
        NumberReportEditLine->setObjectName("NumberReportEditLine");
        NumberReportEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"QLineEdit[text=\"\"] {\n"
"    /* \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\205\320\260\320\272 \320\264\320\273\321\217 \321\201\321\202\320\260\321\200\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271, \320\265\321\201\320\273\320\270 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\320\260\320\273\320\270\321\202\321\200\320\260 */\n"
"}\n"
"/* \320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271 Qt */\n"
"QLineEdit::placeholder {\n"
"    color: #888888; /* \320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\265\320\263\320\276 \321\217\320\262\320\275\320\276 \321\201\320\265\321\200\321\213\320\274/\320"
                        "\262\320\270\320\264\320\270\320\274\321\213\320\274 */\n"
"}"));
        NumberReportEditLine->setMaxLength(4);

        verticalLayout->addWidget(NumberReportEditLine);

        SurnameEditLine = new QLineEdit(frame2);
        SurnameEditLine->setObjectName("SurnameEditLine");
        SurnameEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"QLineEdit[text=\"\"] {\n"
"    /* \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\205\320\260\320\272 \320\264\320\273\321\217 \321\201\321\202\320\260\321\200\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271, \320\265\321\201\320\273\320\270 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\320\260\320\273\320\270\321\202\321\200\320\260 */\n"
"}\n"
"/* \320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271 Qt */\n"
"QLineEdit::placeholder {\n"
"    color: #888888; /* \320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\265\320\263\320\276 \321\217\320\262\320\275\320\276 \321\201\320\265\321\200\321\213\320\274/\320"
                        "\262\320\270\320\264\320\270\320\274\321\213\320\274 */\n"
"}"));
        SurnameEditLine->setMaxLength(50);
        SurnameEditLine->setClearButtonEnabled(false);

        verticalLayout->addWidget(SurnameEditLine);

        NameEditLine = new QLineEdit(frame2);
        NameEditLine->setObjectName("NameEditLine");
        NameEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"QLineEdit[text=\"\"] {\n"
"    /* \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\205\320\260\320\272 \320\264\320\273\321\217 \321\201\321\202\320\260\321\200\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271, \320\265\321\201\320\273\320\270 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\320\260\320\273\320\270\321\202\321\200\320\260 */\n"
"}\n"
"/* \320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271 Qt */\n"
"QLineEdit::placeholder {\n"
"    color: #888888; /* \320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\265\320\263\320\276 \321\217\320\262\320\275\320\276 \321\201\320\265\321\200\321\213\320\274/\320"
                        "\262\320\270\320\264\320\270\320\274\321\213\320\274 */\n"
"}"));
        NameEditLine->setMaxLength(50);

        verticalLayout->addWidget(NameEditLine);

        PatronymicEditLine = new QLineEdit(frame2);
        PatronymicEditLine->setObjectName("PatronymicEditLine");
        PatronymicEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"QLineEdit[text=\"\"] {\n"
"    /* \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\205\320\260\320\272 \320\264\320\273\321\217 \321\201\321\202\320\260\321\200\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271, \320\265\321\201\320\273\320\270 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\320\260\320\273\320\270\321\202\321\200\320\260 */\n"
"}\n"
"/* \320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271 Qt */\n"
"QLineEdit::placeholder {\n"
"    color: #888888; /* \320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\265\320\263\320\276 \321\217\320\262\320\275\320\276 \321\201\320\265\321\200\321\213\320\274/\320"
                        "\262\320\270\320\264\320\270\320\274\321\213\320\274 */\n"
"}"));
        PatronymicEditLine->setMaxLength(50);

        verticalLayout->addWidget(PatronymicEditLine);


        horizontalLayout->addWidget(frame2);


        verticalLayout_4->addWidget(frame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(5, 9, 8, -1);
        label_5 = new QLabel(InputReportDialog);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        DescriptionTextEdit = new QTextEdit(InputReportDialog);
        DescriptionTextEdit->setObjectName("DescriptionTextEdit");
        DescriptionTextEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #000000; /* \320\246\320\262\320\265\321\202 \320\276\320\261\321\213\321\207\320\275\320\276\320\263\320\276 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"}\n"
"QLineEdit[text=\"\"] {\n"
"    /* \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\205\320\260\320\272 \320\264\320\273\321\217 \321\201\321\202\320\260\321\200\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271, \320\265\321\201\320\273\320\270 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\277\320\260\320\273\320\270\321\202\321\200\320\260 */\n"
"}\n"
"/* \320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\262\320\265\321\200\321\201\320\270\320\271 Qt */\n"
"QLineEdit::placeholder {\n"
"    color: #888888; /* \320\241\320\264\320\265\320\273\320\260\320\271\321\202\320\265 \320\265\320\263\320\276 \321\217\320\262\320\275\320\276 \321\201\320\265\321\200\321\213\320\274/\320"
                        "\262\320\270\320\264\320\270\320\274\321\213\320\274 */\n"
"}"));

        verticalLayout_2->addWidget(DescriptionTextEdit);


        verticalLayout_4->addLayout(verticalLayout_2);

        frame3 = new QFrame(InputReportDialog);
        frame3->setObjectName("frame3");
        sizePolicy1.setHeightForWidth(frame3->sizePolicy().hasHeightForWidth());
        frame3->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(frame3);
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(15, 15, 15, 15);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AddReportButton = new QPushButton(frame3);
        AddReportButton->setObjectName("AddReportButton");

        horizontalLayout_5->addWidget(AddReportButton);

        CanelButton = new QPushButton(frame3);
        CanelButton->setObjectName("CanelButton");

        horizontalLayout_5->addWidget(CanelButton);


        verticalLayout_4->addWidget(frame3);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(InputReportDialog);

        QMetaObject::connectSlotsByName(InputReportDialog);
    } // setupUi

    void retranslateUi(QDialog *InputReportDialog)
    {
        InputReportDialog->setWindowTitle(QCoreApplication::translate("InputReportDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("InputReportDialog", "\320\227\320\260\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("InputReportDialog", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("InputReportDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("InputReportDialog", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("InputReportDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        NumberReportEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\247\320\270\321\201\320\273\320\276 \320\276\321\202 1-9999", "1-1000"));
        SurnameEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275\320\276\320\262", "\320\230\320\262\320\260\320\275\320\276\320\262"));
        NameEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275", "\320\230\320\262\320\260\320\275"));
        PatronymicEditLine->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", nullptr));
        label_5->setText(QCoreApplication::translate("InputReportDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        DescriptionTextEdit->setPlaceholderText(QCoreApplication::translate("InputReportDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 100 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262.", nullptr));
        AddReportButton->setText(QCoreApplication::translate("InputReportDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        CanelButton->setText(QCoreApplication::translate("InputReportDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputReportDialog: public Ui_InputReportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_REPORT_DIALOG_H
