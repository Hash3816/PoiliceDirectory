/********************************************************************************
** Form generated from reading UI file 'windowshowstructures.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSHOWSTRUCTURES_H
#define UI_WINDOWSHOWSTRUCTURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindowShowStructures
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *PrintTextLine;
    QLabel *LableInfo;

    void setupUi(QDialog *WindowShowStructures)
    {
        if (WindowShowStructures->objectName().isEmpty())
            WindowShowStructures->setObjectName("WindowShowStructures");
        WindowShowStructures->resize(756, 511);
        verticalLayout = new QVBoxLayout(WindowShowStructures);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        PrintTextLine = new QTextBrowser(WindowShowStructures);
        PrintTextLine->setObjectName("PrintTextLine");

        verticalLayout->addWidget(PrintTextLine);

        LableInfo = new QLabel(WindowShowStructures);
        LableInfo->setObjectName("LableInfo");
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        LableInfo->setFont(font);
        LableInfo->setStyleSheet(QString::fromUtf8("color: #808080;"));

        verticalLayout->addWidget(LableInfo);


        retranslateUi(WindowShowStructures);

        QMetaObject::connectSlotsByName(WindowShowStructures);
    } // setupUi

    void retranslateUi(QDialog *WindowShowStructures)
    {
        WindowShowStructures->setWindowTitle(QCoreApplication::translate("WindowShowStructures", "Dialog", nullptr));
        LableInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowShowStructures: public Ui_WindowShowStructures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSHOWSTRUCTURES_H
