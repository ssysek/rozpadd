//
// Created by Maciej Syska on 2019-05-06.
//

#include "Decay.h"
#include <cmath>
#include <iostream>
#include <math.h>
#include <map>
#include <cfloat>
#include <ctime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

using std::map;
QT_CHARTS_USE_NAMESPACE

double MASA_HELU=4.0015; //[u] masa cząsteczki alfa
double MASA_ELEKTRONU=0.00055;
long PREDKOSC_SWIATLA_KWADRAT=89875517874;//[km^2/s]
int prev_elem=1000;
Decay::Decay():Nuc(0),Half(0) {

}

Decay::Decay(int Nuclei, double HalfLife , double _masa_pierwiastka, double _masa_produktu,bool _alfa){
    Nuc=Nuclei;
    Half=HalfLife;
    masa_pierwiastka=_masa_pierwiastka;
    masa_produktu=_masa_produktu;
    alfa=_alfa;
    suma_energii=0;

    nuc_1 = Nuclei;
    t = 0;
    dt = 0;


}
Decay::~Decay() {

}

int Decay::NucleiOverTimeCont(double time) {
    int N;
    N=Nuc*exp(-1*Lambda()*time);

    return N;
}
long double Decay::EnergiaAlfa (int elem) {

    long double Energia = ((masa_pierwiastka-(masa_produktu+MASA_HELU)) * (elem) );
    return Energia;
}

double Decay::EnergiaBeta (int czas) {

    double Energia = ((masa_pierwiastka-(masa_produktu+2*MASA_ELEKTRONU)) * (Nuc-NucleiOverTimeCont(czas)) * PREDKOSC_SWIATLA_KWADRAT);
    return Energia;
}


int Decay::FillMap(){
    int i=0;
    it.emplace_back(i);
    v.emplace_back(Nuc);
    i++;
    while(Decay::NucleiOverTimeCont(i)>0){
        v.emplace_back(NucleiOverTimeCont(i));
        it.emplace_back(i);
        i++;
    }
    /*
      for(auto elem : v){
        std::cout<<elem<<std::endl;
   }
    */
    return 0;
};

void Decay::FillEnergyMap() {

    for(auto elem : decayVec){
        if(prev_elem>elem){
            suma_energii=suma_energii+EnergiaAlfa(elem);

        }
        energie.emplace_back(suma_energii);
        prev_elem=elem;


    }


}

double Decay::Lambda(){
    return log(2)/Half;
}

int Decay::NucleiOverTimeDisc() {
    double dt=CalculateStep();
    double t=CalculateTime(dt);
    this->nuc_1 = this->Nuc;
    this->t = 0;
    this->dt = dt;
    decayVec = {};
    if(t == 0) t = FLT_MAX;
    //decayVec.push_back(this->nuc_1);
    while(this->t + dt < t){
        if(this->nuc_1 == 0) break;
        decayVec.push_back(this->nuc_1);
        this->NucleiOverTimeDiscStep();
    }
    decayVec.push_back(this->nuc_1);
    return this->nuc_1;
}

int Decay::NucleiOverTimeDiscStep() {
    //srand(time(NULL));
    double roll = 0;
    int i = 0;
    double d = 1.0 - exp(-1*this->Lambda()*this->dt);
    for(int j = 0; j < this->nuc_1; j++){
        roll = (double) rand() / RAND_MAX;
        if(roll < d){
            i++;
        }

    }
    this->nuc_1 -= i;
    this->t += this->dt;
}

double Decay::CalculateStep(){
   return Half/130;
}

double Decay::CalculateTime(double step){
   return step*2000;
}

void Decay::PrintOutVector() {
    for(int i = 0; i < decayVec.size(); i++){
        std::cout<<"["<<i<<"]";
        std::cout<<decayVec[i]<<" ";

    }

}

