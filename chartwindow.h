#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QDialog>

namespace Ui {
class ChartWindow;
}

class ChartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();

private:
    Ui::ChartWindow *ui;
};

#endif // CHARTWINDOW_H
