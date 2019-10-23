#include"Boattail.h"
#include<string>
#include<vector>
#include<cmath>
#include<iostream>
#define pi 3.14159265

double Boattail::calcMassBoattail(){
    double mass, volume;

    volume = calcVolumeBoattail();
    mass = volume*_density;

    return mass;
}

double Boattail::calcVolumeBoattail(){
    double volume, total, center, sDiameterT, lDiameterT;

    sDiameterT = _smallerDiameter.x - 2*_thickness;
    lDiameterT = _largerDiameter.x - 2*_thickness;

    total = (1/12)*(pi*_height.y)*(pow(_smallerDiameter.x,2) + (_smallerDiameter.x*_largerDiameter.x) + pow(_largerDiameter.x,2));
    center = (1/12)*(pi*_height.y)*(pow(sDiameterT,2) + (sDiameterT*lDiameterT) + pow(lDiameterT,2));

    volume = total - center;

    return volume;
}

bool Boattail::CheckB(){
    int answer;

    std::cout << "Do you want to include a boattail? \t" << "1 for yes, 2 for no" << std::endl;
    std::cin >> answer;

    if (answer == 1){
        return true;
    } else
        return false;
}

double Boattail::calcCPBoattail(){
    double CP,Al,A0,volume;

    volume = calcVolumeBoattail();
    A0 = pi*pow(_largerDiameter.x,2)/4;
    Al = pi*pow(_smallerDiameter.x,2)/4;

    CP = ((_height.y*Al)-volume)/(Al-A0);

    return CP;
}

Vector Boattail::calcCGBoattail(double nose_height, Vector centerline){
    Vector CG;

    CG = {centerline.x, _height.y*_height.y*(1/3) + nose_height};

    return CG;
}


double Boattail::calcCNBoattail(double alpha, double nose_base){
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
