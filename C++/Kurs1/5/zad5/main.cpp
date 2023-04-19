#include <iostream>
#include <vector>

using namespace std;
int pozycja=1;
class Zwierze{
private:

public:
    int id;
    void wypisz(int yy){
        id=yy;
    }
    virtual void wyswietl_nazwe()=0;
    virtual void nazwa(string g,string i)=0;
    virtual void glos()=0;
    virtual void ruch()=0;
};
class Zajac:public Zwierze{
private:
    string imie;
    string gatunek;
public:
    void wyswietl_nazwe(){
        cout<<"Gatunek: "<<gatunek<<" <---> Imie :"<<imie<<endl;
    }
    void nazwa(string g,string i){
        imie=i;
        gatunek=g;
    }
    void glos(){
        cout<<"Nc! Nc!"<<endl;
    }
    void ruch(){
        cout<<"Skok"<<endl;
    }
};
class Pies:public Zwierze{
private:
    string imie;
    string gatunek;
public:
    void wyswietl_nazwe(){
        cout<<"Gatunek: "<<gatunek<<" <---> Imie :"<<imie<<endl;
    }
    void nazwa(string g,string i){
        imie=i;
        gatunek=g;
    }
    void glos(){
        cout<<"Hal! Hal!"<<endl;
    }
    void ruch(){
        cout<<"Bieg"<<endl;
    }
};
class Kon:public Zwierze{
private:
    string imie;
    string gatunek;
public:
    void wyswietl_nazwe(){
        cout<<"Gatunek: "<<gatunek<<" <---> Imie :"<<imie<<endl;
    }
    void nazwa(string g,string i){
        imie=i;
        gatunek=g;
    }
    void glos(){
        cout<<"Ya! Ya!"<<endl;
    }
    void ruch(){
        cout<<"Galop"<<endl;
    }
};
string podaj(bool imie){
    string zmienna;
    if(imie==true){
        cout<<"Podaj imie:"<<endl;
    }else{
        cout<<"Podaj gatunek:"<<endl;
    }
    cin>>zmienna;
    return zmienna;
}
int main()
{
    vector <Zwierze*> z;
    int liczba;

    while(1){
    cout<<"Wybierz:"<<endl;
    cout<<"1.Dodaj:"<<endl;
    cout<<"2.Wyszukaj:"<<endl;
    cout<<"3.Usuwanie:"<<endl;
    cout<<"4.Modyfikacja:"<<endl;
    cout<<"5.Wyswietl:"<<endl;
    cout<<"6.Koniec:"<<endl;
    cin>>liczba;
    if(liczba==1){
        string gatunek;
        string imie;
        cout<<"Podaj gatunek:"<<endl;
        cin>>gatunek;
        cout<<"Podaj imie:"<<endl;
        cin>>imie;
        if(gatunek=="zajac"){
            z.push_back(new Zajac);
            int ostatni=z.size();
            z[ostatni-1]->wypisz(pozycja);
            z[ostatni-1]->nazwa(gatunek,imie);
        }
        else if(gatunek=="pies"){
            z.push_back(new Pies);
            int ostatni=z.size();
            z[ostatni-1]->wypisz(pozycja);
            z[ostatni-1]->nazwa(gatunek,imie);
        }
        else if(gatunek=="kon"){
            z.push_back(new Kon);
            int ostatni=z.size();
            z[ostatni-1]->wypisz(pozycja);
            z[ostatni-1]->nazwa(gatunek,imie);
        }
        pozycja++;
    }
    if(liczba==2){
    cout<<"Podaj id"<<endl;
    int rodzaj;
    cin>>rodzaj;
    for(int i=0;i<z.size();i++){
            if(rodzaj==z[i]->id){
                z[i]->wyswietl_nazwe();
                z[i]->glos();
                z[i]->ruch();
            }
    }
    }
    if(liczba==3){
    cout<<"Podaj id"<<endl;
    int rodzaj;
    cin>>rodzaj;
    int i;
    for(i=0;i<z.size();i++){
        if(rodzaj==z[i]->id){
            z.erase(z.begin()+i);
        }
    }
    }
    if(liczba==4){
        cout<<"Podaj id:"<<endl;
        int rodzaj;
        cin>>rodzaj;
        for(int i=0;i<z.size();i++){
            if(rodzaj==z[i]->id){
                string gatunek;
                string imie;
                cout<<"Podaj gatunek:"<<endl;
                cin>>gatunek;
                cout<<"Podaj imie:"<<endl;
                cin>>imie;
                if(gatunek=="zajac"){
                    z.push_back(new Zajac);
                    z[i]->wypisz(pozycja);
                    z[i]->nazwa(gatunek,imie);
                }
                else if(gatunek=="pies"){
                    z.push_back(new Pies);
                    z[i]->wypisz(pozycja);
                    z[i]->nazwa(gatunek,imie);
                }
                else if(gatunek=="kon"){
                    z.push_back(new Kon);
                    z[i]->wypisz(pozycja);
                    z[i]->nazwa(gatunek,imie);
                }
            }
        }
    }
    if(liczba==5){
        for(int i=0;i<z.size();i++){
            cout<<endl;
            cout<<i+1<<endl;
            z[i]->wyswietl_nazwe();
            z[i]->glos();
            z[i]->ruch();
            cout<<endl;
        }
    }
    if(liczba==6){
        break;
    }

}
    return 0;
}
