#include "report_table_model.h"
#include <QString>

ReportTableModel::ReportTableModel(const InterfaceStorage<PoliceReport>& storage, QObject *parent)
    : QAbstractTableModel(parent), manager_storage(storage)
{
}

int ReportTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return manager_storage.get_size();
}

int ReportTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return 3; // 3 колонки Номер, ФИО, Описание
}

QVariant ReportTableModel::data(const QModelIndex &index, int role) const
{
    if ((!index.isValid()) || (role != Qt::DisplayRole)) {
        return QVariant();
    }

    const PoliceReport& report = manager_storage.get_element(index.row());

    switch (index.column()) {
    case 0:
        return report.report_number;
    case 1: {
        std::string fio = report.applicant.surname + " " + report.applicant.name + " " + report.applicant.patronymic;
        return QString::fromUtf8(fio.c_str());
    }
    case 2:
        return QString::fromUtf8(report.description.c_str());
    default:
        return QVariant();
    }
}

QVariant ReportTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "Номер заявления";
        case 1: return "ФИО заявителя";
        case 2: return "Описание";
        default: return QVariant();
        }
    }

    if (orientation == Qt::Vertical) {
        return section + 1;
    }
    return QVariant();
}

void ReportTableModel::updateData()
{
    beginResetModel();
    endResetModel();
}