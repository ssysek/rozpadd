#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chartwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int currInd = 0;
    bool wykrJ = false;
    bool wykrE = false;


private slots:
    void on_rysujWykres_clicked();

    void on_pierwiastkiBox_currentIndexChanged(int index);

    void on_wykresJ_toggled(bool checked);

    void on_wykresE_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Ui::ChartWindow *cw1;
    Ui::ChartWindow *cw2;
    QMainWindow *chart1;
    QMainWindow *chart2;

};

#endif // MAINWINDOW_H
