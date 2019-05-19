//
// Created by Maciej Syska on 2019-05-06.
//

#ifndef ROZPAD_DECAY_H
#define ROZPAD_DECAY_H

#include <math.h>
#include <map>
#include <vector>
using std::map;
class Decay {
public:
    Decay();
    Decay(int Nuclei, double HalfLife , double masa_pierwiastka, double masa_produktu,bool alfa);
    ~Decay();
    int NucleiOverTimeCont(double time);


    double EnergiaAlfa (int czas); //Ile jednostek energii rozpadu alfa zostało wytworzonej po danym czasie

    double EnergiaBeta(int czas);

    double Lambda();

    int FillMap();
    void FillEnergyMap();

    void Print();


    int NucleiOverTimeDisc(double t, double dt);
    int NucleiOverTimeDiscStep();
    void PrintOutVector();




private:
    double Half;
    int Nuc;
    std::vector<int> it; //czasy
    std::vector<int> v; //ilości cząsteczek w czasach
    double masa_pierwiastka;
    double masa_produktu;
    bool alfa;
    std::vector<double> energie; //wydzielona energia po danym czasie


    int nuc_1;
    double t;
    double dt;

    std::vector<int> decayVec;

};


#endif //ROZPAD_DECAY_H
