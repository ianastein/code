#ifndef BODYMOTOR_H_INCLUDED
#define BODYMOTOR_H_INCLUDED
#include"VECTOR.h"
#include"NoseCone.h"

class BodyMotor{
private:
    Vector _bodyDiameter;
    Vector _height;
    double _thickness;
    double _density;

public:

    BodyMotor(Vector bd, Vector h, double t, double d):
        _bodyDiameter(bd), _height(h), _thickness(t), _density(d) {};

    ~BodyMotor(){};

    double calcMassBodyM();
    double calcVolumeBodyM();

    Vector calcCGBM(Vector,double,double,double,double);           // OK
    double calcCNBM(double,double);     // OK

    Vector getDiameter() { return _bodyDiameter; }  // OK
    Vector getHeight() { return _height; }          // OK
};

#endif // BODYMOTOR_H_INCLUDED
