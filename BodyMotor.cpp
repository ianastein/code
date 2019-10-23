#include"BodyMotor.h"
#include"NoseCone.h"
#include<string>
#include<vector>
#include<cmath>
#define pi 3.14159265

double BodyMotor::calcMassBodyM(){
    double mass;
    mass = _density*calcVolumeBodyM();
    return mass;
}

double BodyMotor::calcVolumeBodyM(){
    double volume, Ratio, total, center; // total = total volume  and  center = center volume
    Ratio = (_bodyDiameter.x/2)-_thickness;

    total = (pi)*(pow((_bodyDiameter.x/2),2))*(_height.y);
    center = (pi)*(pow(Ratio,2)*(_height.y));

    volume = total - center;

    return volume;
}

Vector BodyMotor::calcCGBM(Vector centerline, double nose_height, double boattail_height, double body_height, double shoulder_height){
    Vector CGBM;
    CGBM = {centerline.x, nose_height + boattail_height + body_height + shoulder_height + _height.y/2};
    return CGBM;
}

double BodyMotor::calcCNBM(double alpha, double nose_base){
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
