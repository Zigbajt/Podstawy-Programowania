#include <iostream>

using namespace std;

class samochod{
public:
    string marka;
    string model;
    int rok;
    string vin;
    int przebieg;
    void dodaj_samochod();
    void wyswietl_samochod();

};
void samochod::dodaj_samochod(){
    cout<<"Wczytywanie auta do systemu:"<<endl;
    cout<<"Podaj marke:"<<endl;
    cin>> marka;
    cout<<"Podaj model:"<<endl;
    cin>> model;
    cout<<"Podaj rok produkcji:"<<endl;
    cin>> rok;
    cout<<"Podaj vin:"<<endl;
    cin>> vin;
    cout<<"Podaj przebieg:"<<endl;
    cin>> przebieg;
}
void samochod::wyswietl_samochod(){
    cout<<"Samochod to: "<<endl;
    cout<<marka<<" "<<model<<" "<<rok<<" "<<vin<<" "<<przebieg<<endl;
}
class telefon{
public:
    string marka;
    string model;
    string oprogramowanie;
    int nr_telefonu;
    int pojemnosc_baterii;
    void wczytaj_telefon();
    void wyswietl_telefon();
};
void telefon::wczytaj_telefon(){
    cout<<"Wczytywanie telefonu do systemu:"<<endl;
    cout<<"Podaj marke:"<<endl;
    cin>> marka;
    cout<<"Podaj model:"<<endl;
    cin>> model;
    int wybierz;
    cout<<"Podaj oprogramowanie:"<<endl;
    cout<<"1.Android"<<endl;
    cout<<"2.IOS"<<endl;
    cout<<"3.Inne"<<endl;
    cin>>wybierz;
    if(wybierz==1){
        oprogramowanie="Android";
    }
    if(wybierz==2){
        oprogramowanie="IOS";
    }
    if(wybierz==3){
        oprogramowanie="Inne";
    }
    cout<<"Podaj nr telefonu:"<<endl;
    cin>> nr_telefonu;
    cout<<"Podaj wielkosc baterii:"<<endl;
    cin>> pojemnosc_baterii;
}
void telefon::wyswietl_telefon(){
    cout<<"Telefon to: "<<endl;
    cout<<marka<<" "<<model<<" "<<oprogramowanie<<" "<<nr_telefonu<<" "<<pojemnosc_baterii<<endl;
}
class samolot{
public:
    string marka;
    string model;
    int szerokosc_samolotu;
    int dlugosc_samolotu;
    int wysokosc_samolotu;
    long int odlegosc;
    void wczytaj_samolot();
    void wyswietl_samolot();

};
void samolot::wczytaj_samolot(){
    cout<<"Wczytywanie samolot do systemu:"<<endl;
    cout<<"Podaj marke:"<<endl;
    cin>> marka;
    cout<<"Podaj model:"<<endl;
    cin>> model;
    cout<<"Podaj szerokosc samolotu:"<<endl;
    cin>> szerokosc_samolotu;
    cout<<"Podaj dlugosc samolotu:"<<endl;
    cin>> dlugosc_samolotu;
    cout<<"Podaj wysokosc samolotu:"<<endl;
    cin>> wysokosc_samolotu;
    cout<<"Podaj maksymalna odleglosc lotu:"<<endl;
    cin>> odlegosc;
}
void samolot::wyswietl_samolot(){
    cout<<"Samolot to: "<<endl;
    cout<<marka<<" "<<model<<" "<<szerokosc_samolotu<<" "<<dlugosc_samolotu<<" "<<wysokosc_samolotu<<" "<<odlegosc<<endl;
}

int main()
{
    telefon t;
    t.wczytaj_telefon();
    samochod a;
    a.dodaj_samochod();
    samolot s;
    s.wczytaj_samolot();
    cout<<endl;
    t.wyswietl_telefon();
    cout<<endl;
    a.wyswietl_samochod();
    cout<<endl;
    s.wyswietl_samolot();

    return 0;
}
