#include <iostream>

using namespace std;
float wybierz_wartosc_wektora(int rodzaj){
    float liczba;
    if(rodzaj==1){
        cout<<"Podaj wartosc x"<<endl;
        cin>>liczba;
    }
    if(rodzaj==2){
        cout<<"Podaj wartosc y"<<endl;
        cin>>liczba;
    }
    cout<<endl;
    return liczba;
}
class wektor{
    float x;
    float y;
public:
    wektor(float xx,float yy){
        x=xx;
        y=yy;
    }
    wektor operator+(wektor &u){
        wektor wynik(0,0);
        wynik.x=x+u.x;
        wynik.y=y+u.y;
        return wynik;
    }
    wektor operator-(wektor &u){
        wektor wynik(0,0);
        wynik.x=x-u.x;
        wynik.y=y-u.y;
        return wynik;
    }
    void wypisz(){
        cout<<"WEKTOR: ("<<x<<","<<y<<")"<<endl;
    }
};
int main()
{
    float x,y;
    cout<<"PODAJ WEKTOR 1"<<endl;
    x=wybierz_wartosc_wektora(1);
    y=wybierz_wartosc_wektora(2);
    wektor w1(x,y);
    cout<<"PODAJ WEKTOR 2"<<endl;
    x=wybierz_wartosc_wektora(1);
    y=wybierz_wartosc_wektora(2);
    wektor w2(x,y);
    cout<<"DODAWANIE:"<<endl;
    wektor w3(0,0);
    w3=w1+w2;
    w3.wypisz();
    cout<<"ODEJMOWANIE"<<endl;
    wektor w4(0,0);
    w4=w1-w2;
    w4.wypisz();
    cout << "Koniec programu!" << endl;
    return 0;
}
