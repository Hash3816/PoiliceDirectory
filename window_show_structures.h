#ifndef WINDOW_SHOW_STRUCTURES_H
#define WINDOW_SHOW_STRUCTURES_H

#include <QDialog>
#include <QString>

namespace Ui {
class WindowShowStructures;
}

class WindowShowStructures : public QDialog
{
    Q_OBJECT

public:
    explicit WindowShowStructures(const QString &text = "", QWidget *parent = nullptr);
    ~WindowShowStructures();

private:
    Ui::WindowShowStructures *ui;
};

#endif // WINDOW_SHOW_STRUCTURES_H
