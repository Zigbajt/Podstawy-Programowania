#include <iostream>
#include "plik.h"
using namespace std;


double PoleTrojkata(){
    double a,h;
    double pole=0;
    cout<<"Podaj dlugosc a"<< endl;
    cin>>a;
    cout<<"Podaj dlugosc wysokosc"<< endl;
    cin>>h;
    pole=(a*h)/(double)2;
    return pole;
}
