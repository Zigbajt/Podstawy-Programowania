#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
class czlowiek{
public:
    int id;
    string imie;
    string nazwisko;
    int wzrost;
    int waga;
    string plec;
    int pesel;
    czlowiek();
    void losuj_id();
    void wypisz();
    void sprawdz_plec();
};
void czlowiek::losuj_id(){
    int id=0;
    id=rand();
}
czlowiek::czlowiek(){
    cout<<"Wczytaj dane osoby do systemu:"<<endl;
    losuj_id();
    cout<<"Podaj imie"<<endl;
    cin>>imie;
    cout<<"Podaj nazwisko"<<endl;
    cin>>nazwisko;
    cout<<"Podaj wzrost"<<endl;
    cin>>wzrost;
    cout<<"Podaj wage"<<endl;
    cin>>waga;
    sprawdz_plec();
    cout<<"Podaj pesel"<<endl;
    cin>>pesel;
}
void czlowiek::wypisz(){
    cout<<id<<" "<<imie<<" "<<nazwisko<<" "<<wzrost<<" "<<waga<<" "<<plec<<" "<<pesel<<endl;
}
void czlowiek::sprawdz_plec(){
    int liczba=0;
    liczba=imie.length();
    liczba--;
    if(imie[liczba]=='a'){
        plec="Kobieta";
    }else{
        plec="Mezczyzna";
    }
}
void szukaj_imie(vector<czlowiek> osoby,string dane){
    int ilosc=0;
    for(int i=0;i<osoby.size();i++){
        if(osoby[i].imie==dane){
        osoby[i].wypisz();
        ilosc++;
        }
    }
    cout<<"Liczba wyszukan: "<<ilosc<<endl;
}
void szukaj_nazwisko(vector<czlowiek> osoby,string dane){
    int ilosc=0;
    for(int i=0;i<osoby.size();i++){
        if(osoby[i].nazwisko==dane){
        osoby[i].wypisz();
        ilosc++;
        }
    }
    cout<<"Liczba wyszukan: "<<ilosc<<endl;
}
void szukaj_pesel(vector<czlowiek> osoby,int dane){
    for(int i=0;i<osoby.size();i++){
        if(osoby[i].pesel==dane){
        osoby[i].wypisz();
        }
    }
}
int main()
{
    vector<czlowiek> osoby;
    int to;
    cout<<"Ile osob wprowadzic"<<endl;
    cin>>to;
    for(int i=0;i<to;i++){
        czlowiek osoba;
        osoby.push_back(osoba);
    }
    int wybierz;
    while(1){
        cout<<endl;
        cout<<"1.Szukaj po imieniu:"<<endl;
        cout<<"2.Szukaj po nazwisku:"<<endl;
        cout<<"3.Szukaj po peselu:"<<endl;
        cout<<"4.Koniec:"<<endl;
        cout<<endl;
        cout<<"Wybierz rodzaj szukania"<<endl;
        cin>>wybierz;
        if(wybierz==1){
            string szukaj;
            cout<< "Podaj imie do szukania"<<endl;
            cin>>szukaj;
            cout<<endl;
            szukaj_imie(osoby,szukaj);
        }
        if(wybierz==2){
            string szukaj;
            cout<< "Podaj nazwisko do szukania"<<endl;
            cin>>szukaj;
            cout<<endl;
            szukaj_nazwisko(osoby,szukaj);
        }
        if(wybierz==3){
            int szukaj;
            cout<< "Podaj pesel do szukania"<<endl;
            cin>>szukaj;
            cout<<endl;
            szukaj_pesel(osoby,szukaj);
        }
        if(wybierz==4){
            break;
        }
    }
    return 0;
}
