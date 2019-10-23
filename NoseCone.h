#ifndef NOSECONE_H_INCLUDED
#define NOSECONE_H_INCLUDED
#include"VECTOR.h"

class NoseCone{
private:
    Vector _baseDiameter;
    Vector _height;
    double _thickness;
    double _density;

public:

    //CONSTRUCTOR
    NoseCone(Vector bD, Vector h, double t, double d):
        _baseDiameter(bD), _height(h), _thickness(t), _density(d) {};      // OK

    //DESTROYER
    ~NoseCone(){};                                      // OK

    //MASS CALCULATION
    double calcMassN();                                 // OK

    //VOLUME CALCULATION
    double calcVolumeN(int = 0);                        // OK


    //COEFFICIENTS CALCULATION
    Vector calcCGN(Vector);                             // OK
    double calcCNN(double);                             // OK
    double calcCPN(int);                                // OK
    double calcCDPN(int, double = 0);                   // OK

    Vector getBaseDiameter() { return _baseDiameter; }  // OK
    Vector getHeight() { return _height; }              // OK
    double calcArea();
};


#endif // NOSECONE_H_INCLUDED
