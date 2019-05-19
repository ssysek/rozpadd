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


    QApplication a(argc, argv);

        QLineSeries *series = new QLineSeries();

        for(int i = 0; i < pierwiastek.decayVec.size(); i++){
            series->append(i*0.1,pierwiastek.decayVec[i]);
        }


        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("Ilość jąder w czasie");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QMainWindow window;
        window.setCentralWidget(chartView);
        window.resize(1080, 720);
        window.show();

        return a.exec();

}
