#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
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
class stos{
public:
    set<typ> stosik;

    void wypisz(){
            for(auto j=stosik.begin();j!=stosik.end();j++){
                cout<<*j<<" ";

            }
            cout<<endl;
    }
    void dodaj(typ w){
        stosik.insert(w);
    }


};

int main()
{
    int wybierz;
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
        stos<int> s1;
        int to;
        for(int i=0;i<ilosc;i++){
            to=rand()%20+1;
            //cout<<to<<endl;
            s1.dodaj(to);
        }
        s1.wypisz();
    }
    if(wybierz==2){
        stos<float> s1;
        float ro;
        int to;
        for(int i=0;i<ilosc;i++){
            to=rand()%20+1;
            ro=(float)to/(float)20;
            //cout<<ro<<endl;
            s1.dodaj(ro);
        }
        s1.wypisz();
    }
    if(wybierz==3){
        stos<string> s1;
        string slowo;
        for(int i=0;i<ilosc;i++){
            cout<<"Podaj slowo nr: "<<i+1<<endl;
            cin>>slowo;
            //cout<<slowo<<endl;
            s1.dodaj(slowo);
        }
        s1.wypisz();
    }

    cout << "Koniec programu!" << endl;
    return 0;
}
