#pragma once
#include <QAbstractTableModel>
#include "IStorage.h"
#include "structures.h"


class InvestigationTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit InvestigationTableModel(const InterfaceStorage<Investigation>& storage, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Метод для перерисовки таблицы после загрузки данных
    void updateData();

private:
    const InterfaceStorage<Investigation>& manager_storage;
};