/********************************************************************************
** Form generated from reading UI file 'report_directory.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_DIRECTORY_H
#define UI_REPORT_DIRECTORY_H

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

class Ui_ReportDirectoryWindow
{
public:
    QAction *actionAddReport;
    QAction *actionDeleteReport;
    QAction *actionLoadDirectoryReport;
    QAction *actionSaveDirectoryReport;
    QAction *actionFilter;
    QAction *actionFindReportByNumber;
    QAction *actionEditCapacity;
    QAction *actionPrintStructures;
    QAction *actionPrintHashTable;
    QAction *actionPrintReports;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *TextLableReportsDirectory;
    QTableView *ReportsDirectoryTable;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ReportDirectoryWindow)
    {
        if (ReportDirectoryWindow->objectName().isEmpty())
            ReportDirectoryWindow->setObjectName("ReportDirectoryWindow");
        ReportDirectoryWindow->setEnabled(true);
        ReportDirectoryWindow->resize(634, 500);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReportDirectoryWindow->sizePolicy().hasHeightForWidth());
        ReportDirectoryWindow->setSizePolicy(sizePolicy);
        ReportDirectoryWindow->setMinimumSize(QSize(600, 500));
        ReportDirectoryWindow->setMaximumSize(QSize(16777215, 16777215));
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
        ReportDirectoryWindow->setPalette(palette);
        ReportDirectoryWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        ReportDirectoryWindow->setAutoFillBackground(false);
        ReportDirectoryWindow->setStyleSheet(QString::fromUtf8("/* \320\224\320\265\320\273\320\260\320\265\320\274 \321\200\320\260\320\267\320\264\320\265\320\273\320\270\321\202\320\265\320\273\320\270 \320\260\320\272\320\272\321\203\321\200\320\260\321\202\320\275\321\213\320\274\320\270 \320\270 \321\201\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\321\213\320\274\320\270 */\n"
"QToolBar::separator {\n"
"    background-color: #d0d0d0; /* \320\234\321\217\320\263\320\272\320\270\320\271 \321\201\320\265\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 \320\262\320\274\320\265\321\201\321\202\320\276 \321\207\320\265\321\200\320\275\320\276\320\263\320\276 */\n"
"    width: 1px;                /* \320\243\320\274\320\265\320\275\321\214\321\210\320\270\320\274 \321\202\320\276\320\273\321\211\320\270\320\275\321\203 \320\264\320\276 1 \320\277\320\270\320\272\321\201\320\265\320\273\321\217 \320\264\320\273\321\217 \320\270\320\267\321\217\321\211\320\275\320\276\321\201\321\202\320\270 */\n"
"    margin-left: 6px;          /* \320\247\321\203"
                        "\321\202\321\214 \321\203\320\262\320\265\320\273\320\270\321\207\320\270\320\274 \320\276\321\202\321\201\321\202\321\203\320\277\321\213, \321\207\321\202\320\276\320\261\321\213 \321\200\320\260\320\267\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\320\275\320\265\320\273\321\214 */\n"
"    margin-right: 6px;\n"
"    margin-top: 5px;           \n"
"    margin-bottom: 5px;        \n"
"}"));
        ReportDirectoryWindow->setAnimated(false);
        actionAddReport = new QAction(ReportDirectoryWindow);
        actionAddReport->setObjectName("actionAddReport");
        actionAddReport->setCheckable(false);
        actionAddReport->setChecked(false);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        actionAddReport->setIcon(icon);
        actionAddReport->setMenuRole(QAction::MenuRole::NoRole);
        actionDeleteReport = new QAction(ReportDirectoryWindow);
        actionDeleteReport->setObjectName("actionDeleteReport");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionDeleteReport->setIcon(icon1);
        actionDeleteReport->setMenuRole(QAction::MenuRole::NoRole);
        actionLoadDirectoryReport = new QAction(ReportDirectoryWindow);
        actionLoadDirectoryReport->setObjectName("actionLoadDirectoryReport");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionLoadDirectoryReport->setIcon(icon2);
        actionLoadDirectoryReport->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveDirectoryReport = new QAction(ReportDirectoryWindow);
        actionSaveDirectoryReport->setObjectName("actionSaveDirectoryReport");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        actionSaveDirectoryReport->setIcon(icon3);
        actionSaveDirectoryReport->setMenuRole(QAction::MenuRole::NoRole);
        actionFilter = new QAction(ReportDirectoryWindow);
        actionFilter->setObjectName("actionFilter");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        actionFilter->setIcon(icon4);
        actionFilter->setMenuRole(QAction::MenuRole::NoRole);
        actionFindReportByNumber = new QAction(ReportDirectoryWindow);
        actionFindReportByNumber->setObjectName("actionFindReportByNumber");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        actionFindReportByNumber->setIcon(icon5);
        actionFindReportByNumber->setMenuRole(QAction::MenuRole::NoRole);
        actionEditCapacity = new QAction(ReportDirectoryWindow);
        actionEditCapacity->setObjectName("actionEditCapacity");
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("applications-development")));
        actionEditCapacity->setIcon(icon6);
        actionEditCapacity->setMenuRole(QAction::MenuRole::NoRole);
        actionPrintStructures = new QAction(ReportDirectoryWindow);
        actionPrintStructures->setObjectName("actionPrintStructures");
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("printer")));
        actionPrintStructures->setIcon(icon7);
        actionPrintStructures->setMenuRole(QAction::MenuRole::NoRole);
        actionPrintHashTable = new QAction(ReportDirectoryWindow);
        actionPrintHashTable->setObjectName("actionPrintHashTable");
        actionPrintReports = new QAction(ReportDirectoryWindow);
        actionPrintReports->setObjectName("actionPrintReports");
        actionPrintReports->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(ReportDirectoryWindow);
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
        TextLableReportsDirectory = new QLabel(centralwidget);
        TextLableReportsDirectory->setObjectName("TextLableReportsDirectory");
        TextLableReportsDirectory->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"    padding-left: 10px;   /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\273\320\265\320\262\320\260 \320\276\321\202 \320\272\321\200\320\260\321\217 \320\276\320\272\320\275\320\260 */\n"
"    padding-top: 10px;    /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\262\320\265\321\200\321\205\321\203 \320\276\321\202 Toolbar */\n"
"    padding-bottom: 5px;  /* \320\236\321\202\321\201\321\202\321\203\320\277 \321\201\320\275\320\270\320\267\321\203 \320\264\320\276 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 */\n"
"}"));

        verticalLayout->addWidget(TextLableReportsDirectory);

        ReportsDirectoryTable = new QTableView(centralwidget);
        ReportsDirectoryTable->setObjectName("ReportsDirectoryTable");
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
        ReportsDirectoryTable->setPalette(palette2);
        ReportsDirectoryTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout->addWidget(ReportsDirectoryTable);

        ReportDirectoryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ReportDirectoryWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setMinimumSize(QSize(0, 25));
        ReportDirectoryWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(ReportDirectoryWindow);
        toolBar->setObjectName("toolBar");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setMinimumSize(QSize(0, 25));
        toolBar->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        toolBar->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        ReportDirectoryWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actionLoadDirectoryReport);
        toolBar->addSeparator();
        toolBar->addAction(actionSaveDirectoryReport);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionFilter);
        toolBar->addSeparator();
        toolBar->addAction(actionFindReportByNumber);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionAddReport);
        toolBar->addSeparator();
        toolBar->addAction(actionDeleteReport);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionPrintStructures);
        toolBar->addSeparator();
        toolBar->addAction(actionEditCapacity);

        retranslateUi(ReportDirectoryWindow);

        QMetaObject::connectSlotsByName(ReportDirectoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ReportDirectoryWindow)
    {
        ReportDirectoryWindow->setWindowTitle(QCoreApplication::translate("ReportDirectoryWindow", "MainWindow", nullptr));
        actionAddReport->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\321\217\320\262\320\272\321\203", nullptr));
        actionDeleteReport->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\321\217\320\262\320\272\321\203", nullptr));
        actionLoadDirectoryReport->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        actionSaveDirectoryReport->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272", nullptr));
        actionFilter->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\321\221\321\202", nullptr));
        actionFindReportByNumber->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        actionEditCapacity->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\262\320\274\320\265\321\201\321\202\320\270\320\274\320\276\321\201\321\202\321\214 \321\205\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        actionPrintStructures->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        actionPrintHashTable->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\240\320\260\321\201\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \321\205\320\265\321\210-\321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        actionPrintReports->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\240\320\260\320\277\320\265\321\207\320\260\321\202\320\260\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262 \320\267\320\260\321\217\320\262\320\273\320\265\320\275\320\270\320\271", nullptr));
        TextLableReportsDirectory->setText(QCoreApplication::translate("ReportDirectoryWindow", "\320\241\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272 \320\267\320\260\321\217\320\262\320\273\320\265\320\275\320\270\320\271", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("ReportDirectoryWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportDirectoryWindow: public Ui_ReportDirectoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_DIRECTORY_H
