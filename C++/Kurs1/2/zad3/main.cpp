#include <iostream>
#include <cmath>
using namespace std;

double PoleKola(){
    double promien;
    double pole=0;
    cout<<"Podaj dlugosc promienia"<< endl;
    cin>>promien;
    pole= M_PI*pow(promien,2);
    return pole;
}
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
int main()
{
    double wynik=0;
    int i;
    do{
        cout<<"1.Oblicz pole kola"<<endl;
        cout<<"2.Oblicz pole trapezu"<<endl;
        cout<<"3.Oblicz pole trojkata"<<endl;
        cin>>i;
        if(i==1) wynik=PoleKola();
        if(i==2) wynik=PoleTrapezu();
        if(i==3) wynik=PoleTrojkata();
        cout << "Pole wynosi: "<< wynik << endl << endl;
    }while(i>=1 && i<=3);
    //wynik=PoleKola();

    return 0;
}
