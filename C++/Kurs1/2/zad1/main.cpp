#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void lancuch(){
    string ciag;
    cout<<"Podaj lancuch:"<<endl;
    getline(cin,ciag); //funkcja uwzgladnia spacje w ciagu znakow

    cout<<"-------------"<<endl;
    int dlugosc_ciagu=ciag.length();
    cout<<"dlugosc lancucha wynosi: "<<dlugosc_ciagu<<" w: "<<ciag<<endl;
    cout<<"-------------"<<endl;
    string usuniete=ciag.substr(2,4);
    ciag.erase(2,4);//usuwanie znakow z ciagu
    cout<<"Po usunieciu: "<<ciag<<" usunieto: "<<usuniete<<endl;

}
void dane(){
    string imie,nazwisko,miejscowosc,kraj;
    cout<<"Podaj imie: "<<endl;
    cin>>imie;
    cout<<"Podaj nazwisko: "<<endl;
    cin>>nazwisko;
    cout<<"Podaj miejscowosc: "<<endl;
    cin>>miejscowosc;
    cout<<"Podaj kraj: "<<endl;
    cin>>kraj;
    cout<<"------------------------"<<endl;
    transform(kraj.begin(),kraj.end(),kraj.begin(),::toupper);
    cout<< imie+" "+nazwisko+" "+miejscowosc+" "+kraj<<endl;
}

int main()
{
    lancuch();
    dane();
    return 0;
}
