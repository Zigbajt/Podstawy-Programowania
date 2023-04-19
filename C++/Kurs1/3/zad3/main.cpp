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
    void wczytaj();
    void losuj_id();
    void wypisz();
    void sprawdz_plec();
};
void czlowiek::losuj_id(){
    srand(time(NULL));
    id=rand();
}
void czlowiek::wczytaj(){
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
int main()
{
    czlowiek c1, c2;
    c1.wczytaj();
    c2.wczytaj();
    cout<<"Wczytywanie osoba do systemu to:"<<endl;
    c1.wypisz();
    c2.wypisz();
    return 0;
}
