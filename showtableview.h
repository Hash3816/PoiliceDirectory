#ifndef SHOWTABLEVIEW_H
#define SHOWTABLEVIEW_H
#include <QDialog>
#include <QStandardItemModel>
#include <vector>
#include <QString>
#include "structures.h"
#include "Pair.h"

namespace Ui {
class ShowTableView;
}

class ShowTableView : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTableView(QWidget *parent = nullptr);
    ~ShowTableView();

    // Добавляем метод для загрузки вектора
    void set_find_report(const std::reference_wrapper<const PoliceReport> data_find_reports);
    void set_find_investigations(const std::vector<std::reference_wrapper<const Investigation>>&);
    void set_filtered_data(const std::vector<Pair<const PoliceReport&, const Investigation&>>&);

private:
    Ui::ShowTableView *ui;
    QStandardItemModel *model;
};

#endif // SHOWTABLEVIEW_H
