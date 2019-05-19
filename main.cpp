#include "mainwindow.h"
#include "Decay.h"
#include <iostream>
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{

    Decay pierwiastek(1000,13,220.0113940,216.0019150,true);
    std::cout<<pierwiastek.Lambda()<<std::endl;
    std::cout<<pierwiastek.NucleiOverTimeDisc(20,0.1)<<std::endl;
    pierwiastek.PrintOutVector();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
