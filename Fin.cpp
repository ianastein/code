#include"Fin.h"
#include"NoseCone.h"
#include<string>
#include<vector>
#include<cmath>
#define PI 3.14159265

Fin::Fin(Vector lB, Vector sB, Vector h, double dB, double t, double d, int n){
    _largerBase = lB;
    _smallerBase = sB;
    _height = h;
    _deltaB = dB;
    _thickness = t;
    _density = d;
    _numberFins = n;
}


double Fin::calcVolumeF(){
    double volume;

    volume = ((1/2)*(_largerBase.y+_smallerBase.y)*_height.x*_thickness)*_numberFins;

    return volume;
}


double Fin::calcMassF(){
    double mass;

    mass = _numberFins*(_density*calcVolumeF());

    return mass;
}


Vector Fin::calcCGF(){
    Vector CGF, aux;

    aux = {(_largerBase.y+_smallerBase.y)/4, (_height.x/3)*((_largerBase.y+2*_smallerBase.y)/(_largerBase.y+_smallerBase.y))};
    CGF = {aux.x*_numberFins, aux.y*_numberFins};

    return CGF;
}


double Fin::calcCNF(double alpha, bool check){
    double Cn, Cn_aux, k, absDist, absDistL;

    absDist = sqrt(pow(_dist.x,2)+ pow(_dist.y,2));
    absDistL = sqrt(pow(_distL.x,2)+ pow(_distL.y,2));

    if (check == true){
        Cn_aux = (4*_numberFins*(pow((_height.x/absDist),2)))/(1+sqrt(1+pow(((2*absDistL)/(_smallerBase.y+_largerBase.y)),2)));
        k = 2*(_height.x+absDist)/((2*_height.x)+absDist);
        Cn = Cn_aux*k;
    }
    else {
        Cn = 2;
    }

    return Cn;

    /*

    double Aref = pow((n.getBaseDiameter().x/2),2)*pi;

    CNalpha = (2*PI*s*s/Aref)/(1+sqrt(1+pow((b*s*s/(Afin*cos(tal))),2)));

    if (_numberFins == 3){
        CN = 1.50*CNalpha*(1-0.15*pow(cos(3/(2*teta)),2));
    } else if (_numberFins == 4){
        CN = 2.00*CNalpha*(1-0.06*pow(sin(2*teta),2));
    } else if (_numberFins == 5){
        CN = 2.37*CNalpha;
    } else if (_numberFins == 6){
        CN = 2.74*CNalpha;
    } else if (_numberFins == 7){
        CN = 2.99*CNalpha;
    } else if (_numberFins == 8){
        CN = 3.24*CNalpha;
    } else
        CN = CNalpha;

    return CN;

     */
}

double Fin::calcCPF(){
    double CP;

    CP = ((_deltaB/3)*(_largerBase.y+2*_smallerBase.y)/(_largerBase.y+_smallerBase.y)) + ((1/6)*(pow(_largerBase.y,2)+pow(_smallerBase.y,2)+(_largerBase.y*_smallerBase.y))/(_largerBase.y+_smallerBase.y));

    return CP;

}


double Fin::calcCDPF(){


}
