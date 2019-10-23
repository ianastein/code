#ifndef SHOULDER_H_INCLUDED
#define SHOULDER_H_INCLUDED
#include"VECTOR.h"

class Shoulder{
private:
    Vector _height;
    Vector _smallerDiameter;
    Vector _largerDiameter;
    double _density;
    double _thickness;

public:

    Shoulder(Vector h, Vector sD, Vector lD, double d, double t):
        _height(h), _smallerDiameter(sD), _largerDiameter(lD), _density(d), _thickness(t) {};   // OK

    ~Shoulder(){};          // OK

    bool CheckS();          // OK

    double calcMassS();     // OK
    double calcVolumeS();   // OK

    Vector calcCGS(Vector,double,double,double);    // OK
    double calcCNS(double,double);
    double calcCPS();       // OK

    Vector getHeight() { return _height; }          // OK
};


#endif // SHOULDER_H_INCLUDED
