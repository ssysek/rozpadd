#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

};

#endif // MAINWINDOW_H
