#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED
#include"VECTOR.h"
#include"NoseCone.h"

class Body{
private:
    Vector _bodyDiameter;
    Vector _height;
    double _thickness;
    double _density;

public:

    //CONSTRUCTOR
    Body(Vector bD, Vector h, double t, double d):
        _bodyDiameter(bD), _height(h), _thickness(t), _density(d) {};       // OK

    //DESTROYER
    ~Body(){};                  // OK

    //MASS CALCULATION
    double calcMassBody();      // OK

    //VOLUME CALCULATION
    double calcVolumeBody();    // OK

    //COEFFICIENTS CALCULATION
    Vector calcCGB(Vector,double,double);           // OK
    double calcCNB(double,double);     // OK

    Vector getDiameter() { return _bodyDiameter; }  // OK
    Vector getHeight() { return _height; }          //OK
};


#endif // BODY_H_INCLUDED
