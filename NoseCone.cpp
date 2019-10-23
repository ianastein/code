#include"NoseCone.h"
#include"VECTOR.h"
#include<string>
#include<vector>
#include<cmath>
#define pi 3.14159265

double NoseCone::calcMassN(){
    double mass, volume;

    volume = calcVolumeN();

    mass = _density*volume;

    return mass;
}

double NoseCone::calcVolumeN(int shape){ // 1 FOR CONICAL, 2 FOR OGIVAL, 3 FOR PARABOLIC
    double volume, diameterT, total, center; // total = total volume  and  center = center volume

    diameterT = _baseDiameter.x - 2*_thickness;

    if (shape == 1){
        total = (1/12)*pi*(pow(_baseDiameter.x,2))*_height.y;
        center = (1/12)*pi*(pow(diameterT,2))*_height.y;
        volume = total - center;
    } else if (shape == 2){
        total = (1/6)*pi*(pow(_baseDiameter.x,2))*_height.y;
        center = (1/6)*pi*(pow(diameterT,2))*_height.y;
        volume = total - center;
    } else if (shape == 3){
        total = (2/15)*pi*(pow(_baseDiameter.x,2))*_height.y;
        center = (2/15)*pi*(pow(diameterT,2))*_height.y;
        volume = total - center;
    } else
        volume = 0;

    return volume;
}


Vector NoseCone::calcCGN(Vector centerline){
    Vector CGN;

    CGN = {centerline.x, (2/3)*_height.y};

    return CGN;
}


double NoseCone::calcCNN(double alpha){
    double CNN;
    double Aref = pow((_baseDiameter.x/2),2)*pi;
    double Al = pi*pow(_baseDiameter.x,2)/4;
    double A0 = 0;

    if(alpha==0){
        CNN = (2/Aref)*(Al - A0);
    } else {
        CNN = (2/Aref)*(Al - A0)*sin(alpha);
    }

    return CNN;
}


double NoseCone::calcCPN(int geometry){     // 1 for conical, 2 for ogival, 3 for parabolic
    double CP;

    if (geometry == 1){
        CP = 0,666*_height.y;
    } else if (geometry == 2){
        CP = 0,466*_height.y;
    } else if (geometry == 3){
        CP = 0,5*_height.y;
    } else
        CP = 0;

    return CP;
}


double NoseCone::calcCDPN(int shape, double angle){ // 1 FOR CONICAL, 2 FOR PARABOLIC
    double CDP;

    if (shape == 1){
        CDP = 0.2;
    } else if (shape == 2){
        CDP = -0.05;
    } else {
        CDP = 0.8*sin(angle)*sin(angle);
    }

    return CDP;
}

