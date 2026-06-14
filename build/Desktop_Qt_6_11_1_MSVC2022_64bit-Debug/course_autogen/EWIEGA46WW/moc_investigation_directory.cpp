/****************************************************************************
** Meta object code from reading C++ file 'investigation_directory.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../investigation_directory.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'investigation_directory.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22InvestigationDirectoryE_t {};
} // unnamed namespace

template <> constexpr inline auto InvestigationDirectory::qt_create_metaobjectdata<qt_meta_tag_ZN22InvestigationDirectoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "InvestigationDirectory",
        "on_actionLoadDirectoryInvestigation_triggered",
        "",
        "on_actionSaveDirectoryInvestigation_triggered",
        "on_actionAddInvestigation_triggered",
        "on_actionFindInvestigationsByNumber_triggered",
        "on_actionPrintStructures_triggered",
        "on_actionPrintRBTreeReportsNumbers_triggered",
        "on_actionPrintRBTreeDates_triggered",
        "on_actionPrintInvestigations_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_actionLoadDirectoryInvestigation_triggered'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSaveDirectoryInvestigation_triggered'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAddInvestigation_triggered'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFindInvestigationsByNumber_triggered'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintStructures_triggered'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintRBTreeReportsNumbers_triggered'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintRBTreeDates_triggered'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrintInvestigations_triggered'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<InvestigationDirectory, qt_meta_tag_ZN22InvestigationDirectoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject InvestigationDirectory::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22InvestigationDirectoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22InvestigationDirectoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22InvestigationDirectoryE_t>.metaTypes,
    nullptr
} };

void InvestigationDirectory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<InvestigationDirectory *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_actionLoadDirectoryInvestigation_triggered(); break;
        case 1: _t->on_actionSaveDirectoryInvestigation_triggered(); break;
        case 2: _t->on_actionAddInvestigation_triggered(); break;
        case 3: _t->on_actionFindInvestigationsByNumber_triggered(); break;
        case 4: _t->on_actionPrintStructures_triggered(); break;
        case 5: _t->on_actionPrintRBTreeReportsNumbers_triggered(); break;
        case 6: _t->on_actionPrintRBTreeDates_triggered(); break;
        case 7: _t->on_actionPrintInvestigations_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *InvestigationDirectory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvestigationDirectory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22InvestigationDirectoryE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int InvestigationDirectory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
