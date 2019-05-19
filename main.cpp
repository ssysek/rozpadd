#include "mainwindow.h"
#include "Decay.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    Decay pierwiastek(1000,13,220.0113940,216.0019150,true);
    pierwiastek.NucleiOverTimeDisc(100,0.1);
    pierwiastek.FillEnergyMap();



    QApplication a(argc, argv);

        QLineSeries *series = new QLineSeries();
        QLineSeries *series2 = new QLineSeries();

        for(int i = 0; i < pierwiastek.decayVec.size(); i++){
            series->append(i*0.1,pierwiastek.decayVec[i]);
        }
        for(int i = 0; i < pierwiastek.energie.size(); i++){
            series2->append(i*0.1,pierwiastek.energie[i]);
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

}
