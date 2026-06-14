/********************************************************************************
** Form generated from reading UI file 'investigation_directory.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVESTIGATION_DIRECTORY_H
#define UI_INVESTIGATION_DIRECTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvestigationDirectoryWindow
{
public:
    QAction *actionAddInvestigation;
    QAction *actionDeleteInvestigation;
    QAction *actionLoadDirectoryInvestigation;
    QAction *actionSaveDirectoryInvestigation;
    QAction *actionFilter;
    QAction *actionFindInvestigationsByNumber;
    QAction *actionPrintStructures;
    QAction *actionPrintRBTreeReportsNumbers;
    QAction *actionPrintInvestigations;
    QAction *actionPrintRBTreeDates;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *TextLabelInvestigationsDirectory;
    QTableView *InvestigationsDirectoryTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *InvestigationDirectoryWindow)
    {
        if (InvestigationDirectoryWindow->objectName().isEmpty())
            InvestigationDirectoryWindow->setObjectName("InvestigationDirectoryWindow");
        InvestigationDirectoryWindow->setEnabled(true);
        InvestigationDirectoryWindow->resize(634, 500);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InvestigationDirectoryWindow->sizePolicy().hasHeightForWidth());
        InvestigationDirectoryWindow->setSizePolicy(sizePolicy);
        InvestigationDirectoryWindow->setMinimumSize(QSize(600, 500));
        InvestigationDirectoryWindow->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush1);
        QBrush brush2(QColor(245, 245, 245, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush2);
        QBrush brush3(QColor(117, 117, 117, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush3);
        QBrush brush4(QColor(157, 157, 157, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush6(QColor(0, 0, 0, 127));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush1);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush1);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        QBrush brush7(QColor(235, 235, 235, 255));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush7);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush8(QColor(117, 117, 117, 127));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush1);
#endif
        InvestigationDirectoryWindow->setPalette(palette);
        InvestigationDirectoryWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        InvestigationDirectoryWindow->setAutoFillBackground(false);
        InvestigationDirectoryWindow->setStyleSheet(QString::fromUtf8("/* \320\224\320\265\320\273\320\260\320\265\320\274 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\320\270 \320\260\320\272\320\272\321\203\321\200\320\260\321\202\320\275\321\213\320\274\320\270 \320\270 \321\201\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\321\213\320\274\320\270 */\n"
"QToolBar::separator {\n"
"    background-color: #d0d0d0; /* \320\234\321\217\320\263\320\272\320\270\320\271 \321\201\320\265\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 \320\262\320\274\320\265\321\201\321\202\320\276 \321\207\320\265\321\200\320\275\320\276\320\263\320\276 */\n"
"    width: 1px;                /* \320\243\320\274\320\265\320\275\321\214\321\210\320\270\320\274 \321\202\320\276\320\273\321\211\320\270\320\275\321\203 \320\264\320\276 1 \320\277\320\270\320\272\321\201\320\265\320\273\321\217 \320\264\320\273\321\217 \320\270\320\267\321\217\321\211\320\275\320\276\321\201\321\202\320\270 */\n"
"    margin-left: 6px;          /* \320\247\321\203"
                        "\321\202\321\214 \321\203\320\262\320\265\320\273\320\270\321\207\320\270\320\274 \320\276\321\202\321\201\321\202\321\203\320\277\321\213, \321\207\321\202\320\276\320\261\321\213 \321\200\320\260\320\267\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\320\275\320\265\320\273\321\214 */\n"
"    margin-right: 6px;\n"
"    margin-top: 5px;           \n"
"    margin-bottom: 5px;        \n"
"}"));
        InvestigationDirectoryWindow->setAnimated(false);
        actionAddInvestigation = new QAction(InvestigationDirectoryWindow);
        actionAddInvestigation->setObjectName("actionAddInvestigation");
        actionAddInvestigation->setCheckable(false);
        actionAddInvestigation->setChecked(false);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        actionAddInvestigation->setIcon(icon);
        actionAddInvestigation->setMenuRole(QAction::MenuRole::NoRole);
        actionDeleteInvestigation = new QAction(InvestigationDirectoryWindow);
        actionDeleteInvestigation->setObjectName("actionDeleteInvestigation");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionDeleteInvestigation->setIcon(icon1);
        actionDeleteInvestigation->setMenuRole(QAction::MenuRole::NoRole);
        actionLoadDirectoryInvestigation = new QAction(InvestigationDirectoryWindow);
        actionLoadDirectoryInvestigation->setObjectName("actionLoadDirectoryInvestigation");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionLoadDirectoryInvestigation->setIcon(icon2);
        actionLoadDirectoryInvestigation->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveDirectoryInvestigation = new QAction(InvestigationDirectoryWindow);
        actionSaveDirectoryInvestigation->setObjectName("actionSaveDirectoryInvestigation");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        actionSaveDirectoryInvestigation->setIcon(icon3);
        actionSaveDirectoryInvestigation->setMenuRole(QAction::MenuRole::NoRole);
        actionFilter = new QAction(InvestigationDirectoryWindow);
        actionFilter->setObjectName("actionFilter");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        actionFilter->setIcon(icon4);
        actionFilter->setMenuRole(QAction::MenuRole::NoRole);
        actionFindInvestigationsByNumber = new QAction(InvestigationDirectoryWindow);
        actionFindInvestigationsByNumber->setObjectName("actionFindInvestigationsByNumber");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        actionFindInvestigationsByNumber->setIcon(icon5);
        actionFindInvestigationsByNumber->setMenuRole(QAction::MenuRole::NoRole);
        actionPrintStructures = new QAction(InvestigationDirectoryWindow);
        actionPrintStructures->setObjectName("actionPrintStructures");
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("printer")));
        actionPrintStructures->setIcon(icon6);
        actionPrintStructures->setMenuRole(QAction::MenuRole::NoRole);
        actionPrintRBTreeReportsNumbers = new QAction(InvestigationDirectoryWindow);
        actionPrintRBTreeReportsNumbers->setObjectName("actionPrintRBTreeReportsNumbers");
        actionPrintInvestigations = new QAction(InvestigationDirectoryWindow);
        actionPrintInvestigations->setObjectName("actionPrintInvestigations");
        actionPrintInvestigations->setMenuRole(QAction::MenuRole::NoRole);
        actionPrintRBTreeDates = new QAction(InvestigationDirectoryWindow);
        actionPrintRBTreeDates->setObjectName("actionPrintRBTreeDates");
        actionPrintRBTreeDates->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(InvestigationDirectoryWindow);
        centralwidget->setObjectName("centralwidget");
        QPalette palette1;
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush7);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush2);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush3);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush4);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush2);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush5);
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush1);
#endif
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush7);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush3);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush4);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush2);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush5);
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush1);
#endif
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush2);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush4);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush1);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush3);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush7);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush5);
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette1.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush1);
#endif
        centralwidget->setPalette(palette1);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 4, 10, 8);
        TextLabelInvestigationsDirectory = new QLabel(centralwidget);
        TextLabelInvestigationsDirectory->setObjectName("TextLabelInvestigationsDirectory");
        TextLabelInvestigationsDirectory->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout->addWidget(TextLabelInvestigationsDirectory);

        InvestigationsDirectoryTable = new QTableView(centralwidget);
        InvestigationsDirectoryTable->setObjectName("InvestigationsDirectoryTable");
        QPalette palette2;
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush7);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush1);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush2);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush3);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush4);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush1);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush1);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush7);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush2);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush5);
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush1);
#endif
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush7);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush1);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush2);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush3);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush4);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush1);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush1);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush7);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush2);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush5);
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush6);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush1);
#endif
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush7);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush1);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush2);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush4);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush1);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush3);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush7);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush7);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush7);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush5);
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush8);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette2.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush1);
#endif
        InvestigationsDirectoryTable->setPalette(palette2);
        InvestigationsDirectoryTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout->addWidget(InvestigationsDirectoryTable);

        InvestigationDirectoryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InvestigationDirectoryWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setMinimumSize(QSize(0, 25));
        InvestigationDirectoryWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(InvestigationDirectoryWindow);
        toolBar->setObjectName("toolBar");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setMinimumSize(QSize(0, 25));
        toolBar->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        toolBar->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        InvestigationDirectoryWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actionLoadDirectoryInvestigation);
        toolBar->addSeparator();
        toolBar->addAction(actionSaveDirectoryInvestigation);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionFilter);
        toolBar->addSeparator();
        toolBar->addAction(actionFindInvestigationsByNumber);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionAddInvestigation);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteInvestigation);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionPrintStructures);

        retranslateUi(InvestigationDirectoryWindow);

        QMetaObject::connectSlotsByName(InvestigationDirectoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InvestigationDirectoryWindow)
    {
        InvestigationDirectoryWindow->setWindowTitle(QCoreApplication::translate("InvestigationDirectoryWindow", "MainWindow", nullptr));
        actionAddInvestigation->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\321\217\320\262\320\272\321\203", nullptr));
        actionDeleteInvestigation->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\321\217\320\262\320\272\321\203", nullptr));
#if QT_CONFIG(tooltip)
        actionDeleteInvestigation->setToolTip(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\265", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLoadDirectoryInvestigation->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        actionSaveDirectoryInvestigation->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272", nullptr));
        actionFilter->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\321\221\321\202", nullptr));
        actionFindInvestigationsByNumber->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        actionFindInvestigationsByNumber->setIconText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\321\217", nullptr));
#if QT_CONFIG(tooltip)
        actionFindInvestigationsByNumber->setToolTip(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPrintStructures->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        actionPrintRBTreeReportsNumbers->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\232\320\247-\320\264\320\265\321\200\320\265\320\262\320\276 \320\275\320\276\320\274\320\265\321\200\320\276\320\262 \320\267\320\260\321\217\320\262\320\276\320\272", nullptr));
        actionPrintRBTreeReportsNumbers->setIconText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\272\321\200\320\260\321\201\320\275\320\276-\321\207\321\221\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
#if QT_CONFIG(tooltip)
        actionPrintRBTreeReportsNumbers->setToolTip(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\272\321\200\320\260\321\201\320\275\320\276-\321\207\321\221\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPrintInvestigations->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\240\320\260\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\271", nullptr));
        actionPrintRBTreeDates->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276 \320\264\320\260\321\202 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\271", nullptr));
        TextLabelInvestigationsDirectory->setText(QCoreApplication::translate("InvestigationDirectoryWindow", "\320\241\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272 \321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\271", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("InvestigationDirectoryWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvestigationDirectoryWindow: public Ui_InvestigationDirectoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVESTIGATION_DIRECTORY_H
