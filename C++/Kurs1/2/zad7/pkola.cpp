#include <iostream>
#include <cmath>
#include "plik.h"
using namespace std;

double PoleKola(){
    double promien;
    double pole=0;
    cout<<"Podaj dlugosc promienia"<< endl;
    cin>>promien;
    pole= M_PI*pow(promien,2);
    return pole;
}
