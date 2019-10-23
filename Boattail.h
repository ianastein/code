#ifndef BOATTAIL_H_INCLUDED
#define BOATTAIL_H_INCLUDED
#include"VECTOR.h"

class Boattail{
private:
    Vector _height;
    Vector _smallerDiameter;
    Vector _largerDiameter;
    double _density;
    double _thickness;

public:

    Boattail(Vector h, Vector sD, Vector lD, double d, double t):
        _height(h), _smallerDiameter(sD), _largerDiameter(lD), _density(d), _thickness(t) {};   // OK

    ~Boattail(){};                     // OK

    bool CheckB();                     // OK


    double calcMassBoattail();         // OK
    double calcVolumeBoattail();       // OK

    Vector calcCGBoattail(double,Vector);   // OK
    double calcCNBoattail(double,double);   // OK
    double calcCPBoattail();                // OK
    double calcCDPBoattail();

    Vector getHeight() { return _height; }
};


#endif // BOATTAIL_H_INCLUDED
