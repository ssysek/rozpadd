#include "mainwindow.h"
#include "Decay.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{/*
    Decay pierwiastek(1000,13,220.0113940,216.0019150,true);
    pierwiastek.NucleiOverTimeDisc();
    pierwiastek.FillMap();
    pierwiastek.FillEnergyMap();
    
    //int Nuclei, double HalfLife , double masa_pierwiastka, double masa_produktu,bool alfa
    Decay Polon210(1000,11955686.4,209.9828737,205.9744653,true);
    Decay Astat209(1000,19476,208.986174,204.977390,true);
    Decay Radon210(1000,207360,209.989697,205.980482,true);
    Decay Frans221(1000,288,221.014256,217.0047,true);
    Decay Rad224(1000,13074.84,224.0202118,220.0113940,true);
    Decay Aktyn225(1000,864000,225.023231,221.014256,true);
    Decay Tor227(1000,1613952,227.0277041,223.0185022,true);
    //Decay Protaktyn(1000,);
    //Decay Uran(1000,);

    Polon210.NucleiOverTimeDisc();
    Polon210.FillMap();
    //Polon210.FillEnergyMap();


    QApplication a(argc, argv);

        QLineSeries *series = new QLineSeries();
        QLineSeries *series2 = new QLineSeries();

        for(int i = 0; i < Polon210.decayVec.size(); i++){
            series->append(i*Polon210.CalculateStep(),Polon210.decayVec[i]);
        }
        for(int i = 0; i < Polon210.energie.size(); i++){
            series2->append(i*Polon210.CalculateStep(),Polon210.energie[i]);
        }


        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("Ilość jąder w czasie");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QChart *chart2 = new QChart();
        chart2->legend()->hide();
        chart2->addSeries(series2);
        chart2->createDefaultAxes();
        chart2->setTitle("Energia w czasie");

        QChartView *chartView2 = new QChartView(chart2);
        chartView->setRenderHint(QPainter::Antialiasing);

        QMainWindow window;
        window.setCentralWidget(chartView);
        window.resize(1080, 720);
        window.show();

        QMainWindow window2;
        window2.setCentralWidget(chartView2);
        window2.resize(1080, 720);
        window2.show();

        return a.exec();
        */
    QApplication app(argc, argv);
        MainWindow mainwindow;
        mainwindow.resize(1080,720);
        mainwindow.show();
        app.exec();

}
