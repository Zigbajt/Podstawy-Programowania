#include <iostream>

using namespace std;

class wektor{
    float x;
    float y;
public:
    wektor(float xx,float yy){
        x=xx;
        y=yy;
    }
    friend istream & operator >> (istream &wpisz,wektor &v){
        cout<<"Podaj wartosc x"<<endl;
        wpisz>>v.x;
        cout<<"Podaj wartosc y"<<endl;
        wpisz>>v.y;
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
    friend ostream & operator<<(ostream & wypisz, wektor & v){
        wypisz<<"WEKTOR: ("<<v.x<<","<<v.y<<")"<<endl;
    }
};
int main()
{
    cout<<"PODAJ WEKTOR 1"<<endl;
    wektor w1(0,0);
    cin>>w1;
    cout<<"PODAJ WEKTOR 2"<<endl;
    wektor w2(0,0);
    cin>>w2;
    cout<<"DODAWANIE:"<<endl;
    wektor w3(0,0);
    w3=w1+w2;
    cout<<w3;
    cout<<"ODEJMOWANIE"<<endl;
    wektor w4(0,0);
    w4=w1-w2;
    cout<<w4;
    cout << "Koniec programu!" << endl;
    return 0;
}
