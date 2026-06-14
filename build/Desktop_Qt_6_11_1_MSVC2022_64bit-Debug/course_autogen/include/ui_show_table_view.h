/********************************************************************************
** Form generated from reading UI file 'show_table_view.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_TABLE_VIEW_H
#define UI_SHOW_TABLE_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowTableView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *TextAboutTable;
    QTableView *tableView;

    void setupUi(QDialog *ShowTableView)
    {
        if (ShowTableView->objectName().isEmpty())
            ShowTableView->setObjectName("ShowTableView");
        ShowTableView->resize(631, 482);
        verticalLayout_3 = new QVBoxLayout(ShowTableView);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        TextAboutTable = new QLabel(ShowTableView);
        TextAboutTable->setObjectName("TextAboutTable");
        TextAboutTable->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout->addWidget(TextAboutTable);

        tableView = new QTableView(ShowTableView);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ShowTableView);

        QMetaObject::connectSlotsByName(ShowTableView);
    } // setupUi

    void retranslateUi(QDialog *ShowTableView)
    {
        ShowTableView->setWindowTitle(QCoreApplication::translate("ShowTableView", "Dialog", nullptr));
        TextAboutTable->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowTableView: public Ui_ShowTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_TABLE_VIEW_H
