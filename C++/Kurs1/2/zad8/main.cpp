#include <iostream>

using namespace std;

double srednia(double a,double b){
    double suma=a+b;
    double wynik=suma/(double)2;
    return wynik;
}
double srednia(double a,double b, double c){
    double suma=a+b+c;
    double wynik=suma/(double)3;
    return wynik;

}
double srednia(double *tab){
    double suma=0;
    for(int i=0;i<5;i++){
        suma+=tab[i];
    }
    double wynik=suma/(double)5;
    return wynik;

}
double srednia(double *tab,int pocz,int kon){
    double suma=0,y=0;
    pocz--;
    kon--;
    for(int i=pocz;i<=kon;i++){
        suma+=tab[i];
        y++;
    }
    double wynik=suma/(double)y;
    return wynik;

}

int main()
{
    int i=1;
    double a,b,c;
    cout << "Podaj wartosc " << i << " : "<< endl;
    cin>>a;
    cout << "Podaj wartosc " << i+1 << " : "<< endl;
    cin>>b;
    cout<<"Srednia dla dwoch liczb " << a <<" i "<<b<<" wynosi: "<<srednia(a,b)<< endl;
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    cout << "Podaj wartosc " << i+3 << " : "<< endl;
    cin>>c;
    cout<<"Srednia dla trzech liczb " << a <<" "<<b<< " i "<<c<<" wynosi: "<<srednia(a,b,c)<< endl;
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    double tab[5];
    for(int i=0;i<5;i++){
        cout<<"Podaj wartosc tablicy "<<i+1<<" : "<<endl;
        cin>>tab[i];
    }
    cout<<"Srednia dla tablicy liczb wynosi: "<<srednia(tab)<< endl;
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    int pocz,kon;
    cout << "Podaj poczatek "<< " : "<< endl;
    cin>>pocz;
    cout << "Podaj koniec " << " : "<< endl;
    cin>>kon;
    cout<<"Srednia dla elementow od "<<pocz<<" do "<<kon<<" tablicy liczb wynosi: "<<srednia(tab,pocz,kon)<< endl;
    return 0;
}
