#include"Body.h"
#include"NoseCone.h"
#include<string>
#include<vector>
#include<cmath>
#define pi 3.14159265

double Body::calcMassBody(){
    double mass;
    mass = _density*calcVolumeBody();
    return mass;
}

double Body::calcVolumeBody(){
    double volume, Ratio, total, center; // total = total volume  and  center = center volume
    Ratio = (_bodyDiameter.x/2)-_thickness;

    total = (pi)*(pow((_bodyDiameter.x/2),2))*(_height.y);
    center = (pi)*(pow(Ratio,2)*(_height.y));

    volume = total - center;

    return volume;
}


Vector Body::calcCGB(Vector centerline, double nose_height, double boattail_height){
    Vector CGB;
    CGB = {centerline.x,(nose_height + boattail_height + _height.y/2)};
    return CGB;
}


double Body::calcCNB(double alpha, double nose_base){
    double CNB;
    double Aref = pow((nose_base/2),2)*pi;
    double Al = pi*pow(_bodyDiameter.x,2)/4;
    double A0 = pi*pow(_bodyDiameter.x,2)/4;

    if(alpha==0){
        CNB = (2/Aref)*(Al - A0);
    } else {
        CNB = (2/Aref)*(Al - A0)*sin(alpha);
    }
    return CNB;
}

// criando um teste
