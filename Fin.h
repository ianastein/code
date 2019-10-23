#ifndef FIN_H_INCLUDED
#define FIN_H_INCLUDED
#include"VECTOR.h"

class Fin{
private:
    Vector _largerBase;
    Vector _smallerBase;
    Vector _height;
    Vector _dist;       // straight line from the body
    Vector _distL;      // RETA QUE VAI DA BASE MAIOR PRA MENOR (VV) PARALELA
    double _deltaB;
    double _thickness;
    double _density;
    int _numberFins;

public:

    //CONSTRUCTOR
    Fin(Vector,Vector,Vector,double,double,double,int);     // OK

    //DESTROYER
    ~Fin(){};                       // OK

    double calcMassF();             // OK
    double calcVolumeF();           // OK

    //CALCULO DOS COEFICIENTES
    Vector calcCGF();               // OK
    double calcCNF(double,bool);    // OK
    double calcCPF();               // OK
    double calcCDPF();

    Vector getHeight() { return _height; }  // OK
};


#endif // FIN_H_INCLUDED
