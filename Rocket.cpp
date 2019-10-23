#include"Rocket.h"
#include"VECTOR.h"
#include<string>
#include<vector>
#include<cmath>
#define pi 3.14159265

double Rocket::totalMass(){
    double bd, bm, n, f, bt, s, total;

    bd = _body.calcMassBody();
    bm = _bodymotor.calcMassBodyM();
    n = _nose.calcMassN();
    f = _fin.calcMassF();
    bt = _boattail.calcMassBoattail();
    s = _shoulder.calcMassS();

    total = bd + bm+ n + f + bt + s;

    return total;
}

double Rocket::totalVolume(){
    double bd, bm, n, f, bt, s, total;

    bd = _body.calcVolumeBody();
    bm = _bodymotor.calcVolumeBodyM();
    n = _nose.calcVolumeN();
    f = _fin.calcVolumeF();
    bt = _boattail.calcVolumeBoattail();
    s = _shoulder.calcVolumeS();

    total = bd + bm + n + f + bt + s;

    return total;
}

Vector Rocket::calcCenterline(){
    Vector centerline;

    // ACHAR ATITUDE

    return centerline;
}

double Rocket::calcAlpha(){
    Vector centerline = calcCenterline();

    double absCenterline = sqrt(pow(centerline.x,2)+pow(centerline.y,2));
    double absSpeed = sqrt(pow(_speed.x,2)+pow(_speed.y,2));
    double cosalpha = (centerline.x*_speed.x + centerline.y*_speed.y)/(absCenterline*absSpeed);
    double alpha = acos(cosalpha);

    return alpha;
}

Vector Rocket::CG(){
    Vector CG;
    double mass = totalMass();
    Vector centerline = calcCenterline();

    double nh = _nose.getHeight().y;
    double bth = _boattail.getHeight().y;
    double bh = _body.getHeight().y;
    double sh = _shoulder.getHeight().y;

    Vector nose = _nose.calcCGN(centerline);
    Vector fin = _fin.calcCGF();
    Vector body = _body.calcCGB(centerline,nh,bth);
    Vector bodymotor = _bodymotor.calcCGBM(centerline,nh,bth,bh,sh);
    Vector shoulder = _shoulder.calcCGS(centerline,nh,bth,bh);
    Vector boattail = _boattail.calcCGBoattail(nh,centerline);

    Vector aux_nose = {nose.x*_nose.calcMassN(), nose.y*_nose.calcMassN()};
    Vector aux_fin = {fin.x*_fin.calcMassF(), fin.y*_fin.calcMassF()};
    Vector aux_body = {body.x*_body.calcMassBody(), body.y*_body.calcMassBody()};
    Vector aux_bodymotor = {bodymotor.x*_bodymotor.calcMassBodyM(), bodymotor.y*_bodymotor.calcMassBodyM()};
    Vector aux_shoulder = {shoulder.x*_shoulder.calcMassS(), shoulder.y*_shoulder.calcMassS()};
    Vector aux_boattail = {boattail.x*_boattail.calcMassBoattail(), boattail.y*_boattail.calcMassBoattail()};

    double soma_auxx = aux_nose.x+aux_fin.x+aux_body.x+aux_bodymotor.x+aux_shoulder.x+aux_boattail.x;
    double soma_auxy = aux_nose.y+aux_fin.y+aux_body.y+aux_bodymotor.y+aux_shoulder.y+aux_boattail.y;
    CG = {soma_auxx/mass, soma_auxy/mass};

    return CG;
}

double Rocket::Cmalpha(){
    double Cmalpha;

    double alpha = calcAlpha();
    double diameter = _nose.getBaseDiameter().x;
    double height = _body.getHeight().y + _nose.getHeight().y + _fin.getHeight().y + _boattail.getHeight().y + _shoulder.getHeight().y + _bodymotor.getHeight().y;
    double volume = totalVolume();

    Cmalpha = (2*sin(alpha)*((height*pi*diameter*diameter/4)-volume))/(pi*diameter*diameter/4);

    return Cmalpha;
}


Vector Rocket::CP(int geometry, bool check){
    Vector CP;

    double alpha = calcAlpha();
    Vector centerline = calcCenterline();
    double nose_base = _nose.getBaseDiameter().x;

    double nose_CP = _nose.calcCPN(geometry);
    double boattail_CP = _boattail.calcCPBoattail();
    double shoulder_CP = _shoulder.calcCPS();
    double fin_CP = _fin.calcCPF();

    double nose_CN = _nose.calcCNN(alpha);
    double boattail_CN = _boattail.calcCNBoattail(alpha, nose_base);
    double shoulder_CN = _shoulder.calcCNS(alpha, nose_base);
    double fin_CN = _fin.calcCNF(alpha,check);

    double num = nose_CP*nose_CN + boattail_CP*boattail_CN + shoulder_CP*shoulder_CN + fin_CP*fin_CN;
    double denom = nose_CN + boattail_CN + shoulder_CN + fin_CN;

    CP = {centerline.x, num/denom};

    return CP;
}

double Rocket::calcReynolds(){
    double reynolds, mod_speed, diameter;

    mod_speed = sqrt(pow(_speed.x,2)+pow(_speed.y,2));
    diameter = _body.getDiameter().x;
    reynolds = (1.2*mod_speed*diameter)/(1.8*10e-5);

    return reynolds;
}

double Rocket::CDFriction(){
    double reynolds, CDF;

    reynolds = calcReynolds();

    if (reynolds<1000 && reynolds>0){
        CDF = 24/reynolds;
    } else if (reynolds>1000){
        CDF = 0.45;
    } else
        CDF = 0;

    return CDF;
}

double Rocket::CNalpha(){
    double CNalpha;

    return CNalpha;
}

double Rocket::normalForce(double ro, double speed){
    double normal, CN, Aref;

    CN = CNalpha();
    normal = CN*(1/2)*ro*(pow(speed,2))*Aref;

    return normal;
}

double Rocket::moment(double ro, double speed){
    double moment, CM, Aref, d;

    CM = Cmalpha();
    moment = CM*(1/2)*ro*(pow(speed,2))*Aref*d;

    return moment;
}

double Rocket::dragForce(double ro, double speed){
    double drag, CD, Aref;

    CD = calcCD();
    drag = CD*(1/2)*ro*(pow(speed,2))*Aref;

    return CD;
}

void Rocket::simulation(){
    // SUBIDA


    // DESCIDA
}
