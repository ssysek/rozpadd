#include "customelement.h"
#include "ui_customelement.h"
#include "Decay.h"

CustomElement::CustomElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomElement)
{
    ui->setupUi(this);
}

CustomElement::~CustomElement()
{
    delete ui;
}

void CustomElement::on_buttonBox_accepted()
{
    if(ui->nucleiCount->text() != "" && ui->halfLife->text() != "" && ui->elementMass->text() != "" && ui->productMass->text() != ""){
        Decay pierw = Decay(ui->nucleiCount->text().toInt(), ui->halfLife->text().toDouble(), ui->elementMass->text().toDouble(), ui->productMass->text().toDouble(), true);
        pierw.NucleiOverTimeDisc();
        //pierw.PrintOutVector();
        QLineSeries *jednSeries = new QLineSeries();
        for(int i = 0; i < (int)pierw.decayVec.size(); i++){
            jednSeries->append(i*pierw.CalculateStep(), pierw.decayVec[i]);
        }
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(jednSeries);
        chart->createDefaultAxes();
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setAnimationDuration(25000);
        chart->setTitle("Ilość jąder w czasie[n/s]");

        QChartView *jednChart = new QChartView(chart);
        jednChart->setRenderHint(QPainter::Antialiasing);

        QMainWindow *chart1 = new QMainWindow();
        chart1->setCentralWidget(jednChart);
        chart1->resize(600, 500);
        chart1->show();

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
        energChart->setAnimationOptions(QChart::SeriesAnimations);
        energChart->setAnimationDuration(25000);
        energChart->setTitle("Energia w czasie(Hartree na sekundę)[E/s]");

        QChartView *energView = new QChartView(energChart);
        energView->setRenderHint(QPainter::Antialiasing);

        QMainWindow *chart2 = new QMainWindow();
        chart2->setCentralWidget(energView);
        chart2->resize(600,500);
        chart2->show();
    }
    else {
        QMessageBox err;
        err.critical(0, "Błąd!", "Nieprawidłowo wprowadzone dane!");
        err.setFixedSize(300,200);
        this->show();
    }
}
