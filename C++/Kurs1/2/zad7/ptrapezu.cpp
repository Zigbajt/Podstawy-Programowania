#include <iostream>
#include "plik.h"
using namespace std;

double PoleTrapezu(){
    double a,b,h;
    double pole=0;
    cout<<"Podaj dlugosc a"<< endl;
    cin>>a;
    cout<<"Podaj dlugosc b"<< endl;
    cin>>b;
    cout<<"Podaj dlugosc wysokosc"<< endl;
    cin>>h;
    pole=((a+b)*h)/(double)2;
    return pole;
}
