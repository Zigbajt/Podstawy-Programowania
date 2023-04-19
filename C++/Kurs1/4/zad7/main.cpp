#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
//zadanie7
class osoba{
public:
    string imie;
    string nazwisko;
    string nr_telefonu;
    int wiek;
    osoba();
    void wpisz_do_pliku();


};
osoba::osoba(){
    cout<<"Wczytaj dane osoby do systemu:"<<endl;
    cout<<"Podaj imie"<<endl;
    cin>>imie;
    cout<<"Podaj nazwisko"<<endl;
    cin>>nazwisko;
    cout<<"Podaj numer telefonu"<<endl;
    cin>>nr_telefonu;
    cout<<"Podaj wiek"<<endl;
    cin>>wiek;
}
//zadanie8
void osoba::wpisz_do_pliku(){
    fstream plik;
    plik.open("plik.txt",ios::out | ios::app);
    plik<<imie<<endl;
    plik<<nazwisko<<endl;
    plik<<nr_telefonu<<endl;
    plik<<wiek<<endl;
    plik.close();
}
//zadanie9
void odczytaj(){
    fstream plik;
    plik.open("plik.txt",ios::in);
    if(plik.good()==false){
        cout<<"Plik nie istnieje";
        exit(0);
    }
    string linia;
    vector<string> imie,nazwisko;
    vector<int> nr_telefonu,wiek;
    int nr_linii=1;
    while(getline(plik,linia)){
        switch(nr_linii){
            case 1: imie.push_back(linia); break;
            case 2: nazwisko.push_back(linia); break;
            case 3: nr_telefonu.push_back(atoi(linia.c_str())); break;
            case 4: wiek.push_back(atoi(linia.c_str())); break;
        }
        nr_linii++;
        if(nr_linii==5){
            nr_linii=1;
        }
    }
    plik.close();
    for(int i=0;i<imie.size();i++){
    cout<<imie[i]<<endl;
    cout<<nazwisko[i]<<endl;
    cout<<nr_telefonu[i]<<endl;
    cout<<wiek[i]<<endl;
    }
}
int main()
{
    int to;
    while(1){
        cout<<"1.Wprowadz osobe"<<endl;
        cout<<"2.Wypisz osobe"<<endl;
        cout<<"3.Koniec"<<endl;
        cin>>to;
        if(to==1){
            vector<osoba> osoby;
            int ile;
            cout<<"Podaj ile osob"<<endl;
            cin>>ile;
            for(int i=0;i<ile;i++){
                osoba czlowiek;
                osoby.push_back(czlowiek);
                osoby[i].wpisz_do_pliku();
            }
        }
        if(to==2){
            odczytaj();
        }
        if(to==3){
            break;
        }
    }
    return 0;
}
