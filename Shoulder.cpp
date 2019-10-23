#include"Shoulder.h"
#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#define pi 3.14159265

double Shoulder::calcMassS(){
    double mass, volume;

    volume = calcVolumeS();
    mass = volume*_density;

    return mass;
}

double Shoulder::calcVolumeS(){
    double volume, total, center, sDiameterT, lDiameterT;

    sDiameterT = _smallerDiameter.x - 2*_thickness;
    lDiameterT = _largerDiameter.x - 2*_thickness;

    total = (1/12)*(pi*_height.y)*(pow(_smallerDiameter.x,2) + (_smallerDiameter.x*_largerDiameter.x) + pow(_largerDiameter.x,2));
    center = (1/12)*(pi*_height.y)*(pow(sDiameterT,2) + (sDiameterT*lDiameterT) + pow(lDiameterT,2));

    volume = total - center;

    return volume;
}


bool Shoulder::CheckS(){
    int answer;

    std::cout << "Do you want to include a shoulder? \t" << "1 for yes, 2 for no" << std::endl;
    std::cin >> answer;

    if (answer == 1){
        return true;
    } else
        return false;
}

double Shoulder::calcCPS(){
    double CP,Al,A0,volume;

    volume = calcVolumeS();
    Al = pi*pow(_largerDiameter.x,2)/4;
    A0 = pi*pow(_smallerDiameter.x,2)/4;

    CP = ((_height.y*Al)-volume)/(Al-A0);

    return CP;
}

Vector Shoulder::calcCGS(Vector centerline, double nose_height, double boattail_height, double body_height){
    Vector CG;

    CG = {centerline.x, nose_height + boattail_height + body_height + _height.y*(2/3)};

    return CG;
}

double Shoulder::calcCNS(double alpha, double nose_base){
    double CN;
    double Aref = pow((nose_base/2),2)*pi;
    double Al = pi*pow(_largerDiameter.x,2)/4;
    double A0 = pi*pow(_smallerDiameter.x,2)/4;

    if(alpha==0){
        CN = (2/Aref)*(Al - A0);
    } else {
        CN = (2/Aref)*(Al - A0)*sin(alpha);
    }
    return CN;
}
