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

void MainWindow::on_rysujWykres_clicked()
{
    Decay pierw;
    switch (currInd) { //wybrany pierwiastek
    case 0: //polon 210
        pierw = Decay(1000,11955686.4,209.9828737,205.9744653,true);
        break;
    case 1: //astat 209
        pierw = Decay(1000,19476,208.986174,204.977390,true);
        break;
    case 2: //radon 210
        pierw = Decay(1000,207360,209.989697,205.980482,true);
        break;
    case 3: //frans 221
        pierw = Decay(1000,288,221.014256,217.0047,true);
        break;
    case 4: //rad 224
        pierw = Decay(1000,13074.84,224.0202118,220.0113940,true);
        break;
    case 5: //aktyn 225
        pierw = Decay(1000,864000,225.023231,221.014256,true);
        break;
    case 6: //tor 227
        pierw = Decay(1000,1613952,227.0277041,223.0185022,true);
        break;
        }
    if(wykrJ == true){
        pierw.NucleiOverTimeDisc();
        QLineSeries *jednSeries = new QLineSeries();
        for(int i = 0; i < (int)pierw.decayVec.size(); i++){
            jednSeries->append(i*pierw.CalculateStep(),(int)pierw.decayVec[i]);
        }
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(jednSeries);
        chart->createDefaultAxes();
        chart->setTitle("Ilość jąder w czasie");

        QChartView *jednChart = new QChartView(chart);
        jednChart->setRenderHint(QPainter::Antialiasing);

        QMainWindow jednWindow;
        jednWindow.setCentralWidget(jednChart);
        jednWindow.resize(1080, 720);
        jednWindow.show();
    }
    if(wykrE == true){
        pierw.FillMap();
        pierw.FillEnergyMap();
        QLineSeries *energSeries = new QLineSeries();
        for(int i = 0; i < pierw.energie.size(); i++){
            energSeries->append(i*pierw.CalculateStep(),pierw.energie[i]);
        }
        QChart *energChart = new QChart();
        energChart->legend()->hide();
        energChart->addSeries(energSeries);
        energChart->createDefaultAxes();
        energChart->setTitle("Energia w czasie");

        QChartView *energView = new QChartView(energChart);
        energView->setRenderHint(QPainter::Antialiasing);

    }
}




