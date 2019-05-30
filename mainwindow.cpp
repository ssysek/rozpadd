#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Decay.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rysujWykres_clicked()
{

    switch (currInd) { //wybrany pierwiastek
    case 0:
        Decay Polon210(1000,11955686.4,209.9828737,205.9744653,true);
        if(wykrJ == true){
            Polon210.NucleiOverTimeDisc();
            QLineSeries *jednSeries = new QLineSeries();
            for(int i = 0; i < Polon210.decayVec.size(); i++){
                jednSeries->append(i*Polon210.CalculateStep(),Polon210.decayVec[i]);
            }
        }

    }
}



void MainWindow::on_pierwiastkiBox_currentIndexChanged(int index)
{
    currInd = index;
}

void MainWindow::on_wykresJ_toggled(bool checked)   //czy rysować wykres jednostek
{
    wykrJ = checked;
}

void MainWindow::on_wykresE_toggled(bool checked)   //czy rysować wykres energii
{
    wykrE = checked;
}
