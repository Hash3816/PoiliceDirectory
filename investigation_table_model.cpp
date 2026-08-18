#include "investigation_table_model.h"
#include <QString>

InvestigationTableModel::InvestigationTableModel(const InterfaceStorage<Investigation>& storage, QObject *parent)
    : QAbstractTableModel(parent), manager_storage(storage)
{
}

int InvestigationTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return manager_storage.get_size();
}

int InvestigationTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return 4; // 4 колонки Номер заявления, сдеователь, дата возбуждения
}

QVariant InvestigationTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    const Investigation& investigation  = manager_storage.get_element(index.row());

    switch (index.column()) {
    case 0:
        return investigation.report_number;
    case 1: {
        std::string full_name =  full_name_to_string(investigation.investigator);
        return QString::fromUtf8(full_name.c_str());
    }
    case 2:
        return QString::fromUtf8(status_to_string(investigation.investigation_status).c_str());

    case 3:
        return QString::fromUtf8(date_to_string(investigation.initiation_date).c_str());

    default:
        return QVariant();
    }
}

QVariant InvestigationTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "Номер заявления";
        case 1: return "ФИО следователя";
        case 2: return "Статус";
        case 3: return "Дата возбуждения";
        default: return QVariant();
        }
    }

    if (orientation == Qt::Vertical) {
        return section + 1;
    }
    return QVariant();
}

void InvestigationTableModel::updateData()
{
    beginResetModel();
    endResetModel();
}