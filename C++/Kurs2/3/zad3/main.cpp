#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;

int menu(void){
    int wybierz=0;
    do{
    cout<<"WYBIERZ:"<<endl;
    cout<<"1.INT"<<endl;
    cout<<"2.FLOAT"<<endl;
    cout<<"3.TEKST"<<endl;
    cout<<"4.KONIEC"<<endl;
    cin>>wybierz;
    if((wybierz<1) || (wybierz>4)){
        cout<<"PODALES BLEDNA WARTOSC"<<endl;
        cout<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
    }
    }while((wybierz<1) || (wybierz>4));
    return wybierz;
}
template <typename typ>
class lista{
public:
    list<typ> lista;

    void wypisz(){
            for(auto j=lista.begin();j!=lista.end();j++){
                cout<<*j<<" ";

            }
            cout<<endl;
    }
    void dodaj_koniec(typ w){
        lista.push_back(w);
    }
    void dodaj_poczatek(typ w){
        lista.push_front(w);
    }


};
int gdzie(void){
    int wybierz=0;
    do{
    cout<<"WYBIERZ:"<<endl;
    cout<<"1.NA KONCU"<<endl;
    cout<<"2.NA POCZATKU"<<endl;
    cout<<"3.KONIEC"<<endl;
    cin>>wybierz;
    if((wybierz<1) || (wybierz>3)){
        cout<<"PODALES BLEDNA WARTOSC"<<endl;
        cout<<endl;
        cout<<"-------------------"<<endl;
        cout<<endl;
    }
    }while((wybierz<1) || (wybierz>3));
    return wybierz;
}
int main()
{
    int wybierz,g;
    srand(NULL);
    wybierz=menu();
    if(wybierz==4){
        cout << "Koniec programu!" << endl;
        return 0;
    }
    int ilosc;
    cout<<"Podaj ilosc elemnetow"<<endl;
    cin>>ilosc;
    if(wybierz==1){
        lista<int> s1;
        int to;
        for(int i=0;i<ilosc;i++){
            to=rand()%20+1;
            cout<<"Wylosowana liczba: "<<to<<endl;
            g=gdzie();
            if(g==3){
                cout << "Koniec programu!" << endl;
                return 0;
            }
            if(g==1){
                s1.dodaj_koniec(to);
            }
            if(g==2){
                s1.dodaj_poczatek(to);
            }
        }
        s1.wypisz();
    }
    if(wybierz==2){
        lista<float> s1;
        float ro;
        int to;
        for(int i=0;i<ilosc;i++){
            to=rand()%20+1;
            ro=(float)to/(float)20;
            cout<<"Wylosowana liczba: "<<ro<<endl;
            g=gdzie();
            if(g==3){
                cout << "Koniec programu!" << endl;
                return 0;
            }
            if(g==1){
                s1.dodaj_koniec(ro);
            }
            if(g==2){
                s1.dodaj_poczatek(ro);
            }
        }
        s1.wypisz();
    }
    if(wybierz==3){
        lista<string> s1;
        string slowo;
        for(int i=0;i<ilosc;i++){
            cout<<"Podaj slowo nr: "<<i+1<<endl;
            cin>>slowo;
            //cout<<slowo<<endl;
            g=gdzie();
            if(g==3){
                cout << "Koniec programu!" << endl;
                return 0;
            }
            if(g==1){
                s1.dodaj_koniec(slowo);
            }
            if(g==2){
                s1.dodaj_poczatek(slowo);
            }
        }
        s1.wypisz();
    }

    cout << "Koniec programu!" << endl;
    return 0;
}
