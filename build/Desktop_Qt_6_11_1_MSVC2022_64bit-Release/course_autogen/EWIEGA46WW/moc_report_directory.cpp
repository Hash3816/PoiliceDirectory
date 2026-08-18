/****************************************************************************
** Meta object code from reading C++ file 'report_directory.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../report_directory.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'report_directory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15ReportDirectoryE_t {};
} // unnamed namespace

template <> constexpr inline auto ReportDirectory::qt_create_metaobjectdata<qt_meta_tag_ZN15ReportDirectoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ReportDirectory",
        "on_actionLoadDirectoryReport_triggered",
        "",
        "on_actionSaveDirectoryReport_triggered",
        "on_actionAddReport_triggered",
        "on_actionEraseDirectory_triggered",
        "on_actionFindReportByNumber_triggered",
        "on_actionPrintStructures_triggered",
        "on_actionPrintHashTable_triggered",
        "on_actionPrintReports_triggered",
        "on_actionFilter_triggered",
        "on_actionDeleteReport_triggered",
        "on_actionEditCapacity_triggered",
        "mousePressEvent",
        "QMouseEvent*",
        "event"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_actionLoadDirectoryReport_triggered'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSaveDirectoryReport_triggered'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAddReport_triggered'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionEraseDirectory_triggered'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFindReportByNumber_triggered'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintStructures_triggered'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintHashTable_triggered'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintReports_triggered'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFilter_triggered'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDeleteReport_triggered'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionEditCapacity_triggered'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'mousePressEvent'
        QtMocHelpers::SlotData<void(QMouseEvent *)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ReportDirectory, qt_meta_tag_ZN15ReportDirectoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ReportDirectory::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ReportDirectoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ReportDirectoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15ReportDirectoryE_t>.metaTypes,
    nullptr
} };

void ReportDirectory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ReportDirectory *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_actionLoadDirectoryReport_triggered(); break;
        case 1: _t->on_actionSaveDirectoryReport_triggered(); break;
        case 2: _t->on_actionAddReport_triggered(); break;
        case 3: _t->on_actionEraseDirectory_triggered(); break;
        case 4: _t->on_actionFindReportByNumber_triggered(); break;
        case 5: _t->on_actionPrintStructures_triggered(); break;
        case 6: _t->on_actionPrintHashTable_triggered(); break;
        case 7: _t->on_actionPrintReports_triggered(); break;
        case 8: _t->on_actionFilter_triggered(); break;
        case 9: _t->on_actionDeleteReport_triggered(); break;
        case 10: _t->on_actionEditCapacity_triggered(); break;
        case 11: _t->mousePressEvent((*reinterpret_cast<std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ReportDirectory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReportDirectory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ReportDirectoryE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ReportDirectory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
