/********************************************************************************
** Form generated from reading UI file 'input_investigation_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_INVESTIGATION_DIALOG_H
#define UI_INPUT_INVESTIGATION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputInvestigationDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QFrame *frame2;
    QFormLayout *formLayout;
    QFrame *frame3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *frame4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *NumberReportEditLine;
    QLineEdit *SurnameEditLine;
    QLineEdit *NameEditLine;
    QLineEdit *PatronymicEditLine;
    QComboBox *StatusBox;
    QLineEdit *DateLineEdit;
    QFrame *frame5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddInvestigationButton;
    QPushButton *CanelButton;

    void setupUi(QDialog *InputInvestigationDialog)
    {
        if (InputInvestigationDialog->objectName().isEmpty())
            InputInvestigationDialog->setObjectName("InputInvestigationDialog");
        InputInvestigationDialog->setEnabled(true);
        InputInvestigationDialog->resize(599, 407);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(40);
        sizePolicy.setHeightForWidth(InputInvestigationDialog->sizePolicy().hasHeightForWidth());
        InputInvestigationDialog->setSizePolicy(sizePolicy);
        InputInvestigationDialog->setMinimumSize(QSize(400, 407));
        InputInvestigationDialog->setMaximumSize(QSize(776, 505));
        QFont font;
        font.setPointSize(10);
        InputInvestigationDialog->setFont(font);
        InputInvestigationDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(InputInvestigationDialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame = new QFrame(InputInvestigationDialog);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frame1 = new QFrame(frame);
        frame1->setObjectName("frame1");
        sizePolicy1.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(frame1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_7 = new QLabel(frame1);
        label_7->setObjectName("label_7");
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(698, 39));
        label_7->setMaximumSize(QSize(16777215, 40));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout_3->addWidget(label_7);

        frame2 = new QFrame(frame1);
        frame2->setObjectName("frame2");
        sizePolicy1.setHeightForWidth(frame2->sizePolicy().hasHeightForWidth());
        frame2->setSizePolicy(sizePolicy1);
        frame2->setMinimumSize(QSize(0, 252));
        formLayout = new QFormLayout(frame2);
        formLayout->setObjectName("formLayout");
        frame3 = new QFrame(frame2);
        frame3->setObjectName("frame3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame3->sizePolicy().hasHeightForWidth());
        frame3->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(frame3);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        label = new QLabel(frame3);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(frame3);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(frame3);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(frame3);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(frame3);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(frame3);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        verticalLayout->addWidget(label_6);


        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, frame3);

        frame4 = new QFrame(frame2);
        frame4->setObjectName("frame4");
        verticalLayout_2 = new QVBoxLayout(frame4);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        NumberReportEditLine = new QLineEdit(frame4);
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

        verticalLayout_2->addWidget(NumberReportEditLine);

        SurnameEditLine = new QLineEdit(frame4);
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

        verticalLayout_2->addWidget(SurnameEditLine);

        NameEditLine = new QLineEdit(frame4);
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

        verticalLayout_2->addWidget(NameEditLine);

        PatronymicEditLine = new QLineEdit(frame4);
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

        verticalLayout_2->addWidget(PatronymicEditLine);

        StatusBox = new QComboBox(frame4);
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->setObjectName("StatusBox");

        verticalLayout_2->addWidget(StatusBox);

        DateLineEdit = new QLineEdit(frame4);
        DateLineEdit->setObjectName("DateLineEdit");
        DateLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        DateLineEdit->setMaxLength(11);

        verticalLayout_2->addWidget(DateLineEdit);


        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, frame4);


        verticalLayout_3->addWidget(frame2);


        verticalLayout_4->addWidget(frame1);

        frame5 = new QFrame(frame);
        frame5->setObjectName("frame5");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(68);
        sizePolicy3.setHeightForWidth(frame5->sizePolicy().hasHeightForWidth());
        frame5->setSizePolicy(sizePolicy3);
        frame5->setMinimumSize(QSize(0, 68));
        frame5->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_5 = new QHBoxLayout(frame5);
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout_5->setContentsMargins(15, 15, 15, 15);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AddInvestigationButton = new QPushButton(frame5);
        AddInvestigationButton->setObjectName("AddInvestigationButton");

        horizontalLayout_5->addWidget(AddInvestigationButton);

        CanelButton = new QPushButton(frame5);
        CanelButton->setObjectName("CanelButton");

        horizontalLayout_5->addWidget(CanelButton);


        verticalLayout_4->addWidget(frame5);


        verticalLayout_5->addWidget(frame);


        retranslateUi(InputInvestigationDialog);

        QMetaObject::connectSlotsByName(InputInvestigationDialog);
    } // setupUi

    void retranslateUi(QDialog *InputInvestigationDialog)
    {
        InputInvestigationDialog->setWindowTitle(QCoreApplication::translate("InputInvestigationDialog", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\241\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_6->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\224\320\260\321\202\320\260 \320\262\320\276\320\267\320\261\321\203\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        NumberReportEditLine->setPlaceholderText(QCoreApplication::translate("InputInvestigationDialog", "\320\247\320\270\321\201\320\273\320\276 \320\276\321\202 1 \320\264\320\276 9999", "1-1000"));
        SurnameEditLine->setPlaceholderText(QCoreApplication::translate("InputInvestigationDialog", "\320\230\320\262\320\260\320\275\320\276\320\262", "\320\230\320\262\320\260\320\275\320\276\320\262"));
        NameEditLine->setPlaceholderText(QCoreApplication::translate("InputInvestigationDialog", "\320\230\320\262\320\260\320\275", "\320\230\320\262\320\260\320\275"));
        PatronymicEditLine->setPlaceholderText(QCoreApplication::translate("InputInvestigationDialog", "\320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", nullptr));
        StatusBox->setItemText(0, QCoreApplication::translate("InputInvestigationDialog", "\320\222\320\276\320\267\320\261\321\203\320\266\320\264\320\265\320\275\320\276", nullptr));
        StatusBox->setItemText(1, QCoreApplication::translate("InputInvestigationDialog", "\320\237\321\200\320\270\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        StatusBox->setItemText(2, QCoreApplication::translate("InputInvestigationDialog", "\320\235\320\260 \321\200\320\260\321\201\321\201\320\274\320\276\321\202\321\200\320\265\320\275\320\270\320\270", nullptr));
        StatusBox->setItemText(3, QCoreApplication::translate("InputInvestigationDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\320\276", nullptr));

        DateLineEdit->setPlaceholderText(QCoreApplication::translate("InputInvestigationDialog", "01 \321\217\320\275\320\262 2026", nullptr));
        AddInvestigationButton->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        CanelButton->setText(QCoreApplication::translate("InputInvestigationDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputInvestigationDialog: public Ui_InputInvestigationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_INVESTIGATION_DIALOG_H
