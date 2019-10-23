#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED
#include"VECTOR.h"
#include"Boattail.h"
#include"Body.h"
#include"BodyMotor.h"
#include"Fin.h"
#include"NoseCone.h"
#include"Shoulder.h"
#include"VECTOR.h"

class Rocket{
private:
    Vector _speed;
    Body _body;
    BodyMotor _bodymotor;
    NoseCone _nose;
    Fin _fin;
    Boattail _boattail;
    Shoulder _shoulder;

public:

    Rocket(Vector s, Body b, BodyMotor bm, NoseCone n, Fin f, Boattail bt, Shoulder sh):
        _speed(s), _body(b), _bodymotor(bm), _nose(n), _fin(f), _boattail(bt), _shoulder(sh) {};
        // make it work
    ~Rocket(){};

    double totalMass();         // OK
    double totalVolume();       // OK

    Vector CG();                // TERMINAR
    double CNalpha();
    Vector CP(int,bool);        // OK
    double Cmalpha();           // OK
    double CDFriction();        // OK
    double calcCD(double,int);  // OK
    double calcPitchDamping();

    double calcAlpha();         // OK
    Vector calcCenterline();

    double calcReynolds();      // OK


    // FORCES CALCULATION
    double normalForce(double,double);            // OK
    double moment(double,double);                 // OK
    double dragForce(double,double,double,int);   // OK
    double angularVelocity();
    double angularAceleration();
    double velocityToMach();



    // SIMULATION
    void simulation();


};


#endif // ROCKET_H_INCLUDED
