/********************************************************************************
** Form generated from reading UI file 'filter_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_DIALOG_H
#define UI_FILTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QLineEdit *SurnameApplicantEditLine;
    QLineEdit *NameApplicantEditLine;
    QLineEdit *PatronymicApplicantEditLine;
    QComboBox *StatusBox;
    QLineEdit *DateEditLine;
    QFrame *frame3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddFilterButton;
    QPushButton *CanelButton;

    void setupUi(QDialog *FilterDialog)
    {
        if (FilterDialog->objectName().isEmpty())
            FilterDialog->setObjectName("FilterDialog");
        FilterDialog->resize(681, 352);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterDialog->sizePolicy().hasHeightForWidth());
        FilterDialog->setSizePolicy(sizePolicy);
        FilterDialog->setMinimumSize(QSize(0, 352));
        FilterDialog->setMaximumSize(QSize(16777215, 352));
        verticalLayout_5 = new QVBoxLayout(FilterDialog);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame = new QFrame(FilterDialog);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout_4->addWidget(label_6);

        frame1 = new QFrame(frame);
        frame1->setObjectName("frame1");
        sizePolicy.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(frame1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame2 = new QFrame(frame1);
        frame2->setObjectName("frame2");
        sizePolicy.setHeightForWidth(frame2->sizePolicy().hasHeightForWidth());
        frame2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(frame2);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(9);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, -1, 5, -1);
        label_2 = new QLabel(frame2);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(frame2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        label_4 = new QLabel(frame2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(frame2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        label_7 = new QLabel(frame2);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        SurnameApplicantEditLine = new QLineEdit(frame2);
        SurnameApplicantEditLine->setObjectName("SurnameApplicantEditLine");
        SurnameApplicantEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        SurnameApplicantEditLine->setMaxLength(50);

        verticalLayout->addWidget(SurnameApplicantEditLine);

        NameApplicantEditLine = new QLineEdit(frame2);
        NameApplicantEditLine->setObjectName("NameApplicantEditLine");
        NameApplicantEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        NameApplicantEditLine->setMaxLength(50);
        NameApplicantEditLine->setClearButtonEnabled(false);

        verticalLayout->addWidget(NameApplicantEditLine);

        PatronymicApplicantEditLine = new QLineEdit(frame2);
        PatronymicApplicantEditLine->setObjectName("PatronymicApplicantEditLine");
        PatronymicApplicantEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        PatronymicApplicantEditLine->setMaxLength(50);

        verticalLayout->addWidget(PatronymicApplicantEditLine);

        StatusBox = new QComboBox(frame2);
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->addItem(QString());
        StatusBox->setObjectName("StatusBox");

        verticalLayout->addWidget(StatusBox);

        DateEditLine = new QLineEdit(frame2);
        DateEditLine->setObjectName("DateEditLine");
        DateEditLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        DateEditLine->setMaxLength(11);

        verticalLayout->addWidget(DateEditLine);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addWidget(frame2);

        frame3 = new QFrame(frame1);
        frame3->setObjectName("frame3");
        sizePolicy.setHeightForWidth(frame3->sizePolicy().hasHeightForWidth());
        frame3->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(frame3);
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(15, 15, 15, 15);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        AddFilterButton = new QPushButton(frame3);
        AddFilterButton->setObjectName("AddFilterButton");

        horizontalLayout_5->addWidget(AddFilterButton);

        CanelButton = new QPushButton(frame3);
        CanelButton->setObjectName("CanelButton");

        horizontalLayout_5->addWidget(CanelButton);


        verticalLayout_2->addWidget(frame3);


        verticalLayout_4->addWidget(frame1);


        verticalLayout_5->addWidget(frame);


        retranslateUi(FilterDialog);

        QMetaObject::connectSlotsByName(FilterDialog);
    } // setupUi

    void retranslateUi(QDialog *FilterDialog)
    {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("FilterDialog", "\320\244\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\276\321\202\321\207\321\221\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("FilterDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217 \320\267\320\260\321\217\320\262\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("FilterDialog", "\320\230\320\274\321\217 \320\267\320\260\321\217\320\262\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("FilterDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\321\217\320\262\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("FilterDialog", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_7->setText(QCoreApplication::translate("FilterDialog", "\320\224\320\260\321\202\320\260 \320\262\320\276\320\267\320\261\321\203\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        SurnameApplicantEditLine->setText(QString());
        SurnameApplicantEditLine->setPlaceholderText(QCoreApplication::translate("FilterDialog", "\320\230\320\262\320\260\320\275\320\276\320\262", "1-1000"));
        NameApplicantEditLine->setText(QString());
        NameApplicantEditLine->setPlaceholderText(QCoreApplication::translate("FilterDialog", "\320\230\320\262\320\260\320\275", "\320\230\320\262\320\260\320\275\320\276\320\262"));
        PatronymicApplicantEditLine->setText(QString());
        PatronymicApplicantEditLine->setPlaceholderText(QCoreApplication::translate("FilterDialog", "\320\230\320\262\320\260\320\275\320\276\320\262\320\270\321\207", "\320\230\320\262\320\260\320\275"));
        StatusBox->setItemText(0, QCoreApplication::translate("FilterDialog", "\320\222\320\276\320\267\320\261\321\203\320\266\320\264\320\265\320\275\320\276", nullptr));
        StatusBox->setItemText(1, QCoreApplication::translate("FilterDialog", "\320\237\321\200\320\270\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        StatusBox->setItemText(2, QCoreApplication::translate("FilterDialog", "\320\235\320\260 \321\200\320\260\321\201\321\201\320\274\320\276\321\202\321\200\320\265\320\275\320\270\320\270", nullptr));
        StatusBox->setItemText(3, QCoreApplication::translate("FilterDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\320\276", nullptr));

        DateEditLine->setPlaceholderText(QCoreApplication::translate("FilterDialog", "01 \321\217\320\275\320\262 2024", nullptr));
        AddFilterButton->setText(QCoreApplication::translate("FilterDialog", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        CanelButton->setText(QCoreApplication::translate("FilterDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterDialog: public Ui_FilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_DIALOG_H
