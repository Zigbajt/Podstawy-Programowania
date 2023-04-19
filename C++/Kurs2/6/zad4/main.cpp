#include <iostream>
#include <set>

using namespace std;

class uczen{
public:
    string imie;
    string nazwisko;
    int wiek;


    void wypisz();
    uczen(string i,string n,int w){
        imie=i;
        nazwisko=n;
        wiek=w;
    }
};
void uczen::wypisz(){
    cout<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
}

int menu(void){
    int wybierz=0;
    do{
        try{
            cout<<"WYBIERZ METODE:"<<endl;
            cout<<"1.DODAJ UCZNIA"<<endl;
            cout<<"2.USUN UCZNIA"<<endl;
            cout<<"3.WYSWIETL UCZNIA"<<endl;
            cout<<"4.KONIEC"<<endl;
            cin>>wybierz;
            if((wybierz<1) || (wybierz>4)) throw "PODALES BLEDNA WARTOSC";
        }
        catch(const char *k){
            cout<<k<<endl;
            cout<<endl;
            cout<<"-------------------"<<endl;
            cout<<endl;
        }
    }while((wybierz<1) || (wybierz>4));
    return wybierz;
}

int main()
{
    set <uczen*> uczniowie;
    int wybierz;
    wybierz=menu();
    while(1){
        if(wybierz==1){
            string imie,nazwisko;
            int wiek;
            cout<<"Podaj imie"<<endl;
            cin>>imie;
            cout<<"Podaj nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Podaj wiek"<<endl;
            cin>>wiek;
            uczniowie.insert(new uczen(imie,nazwisko,wiek));
            cout<<endl;
            cout<<"-------------------"<<endl;
            cout<<endl;

        }
        if(wybierz==2){
            cout<<endl;
            cout<<"-------------------"<<endl;
            string im,n;
            int w;

            try{
                if(uczniowie.empty()) throw "Nie ma co usunac";
                cout<<"Podaj ucznia do usuniecia:"<<endl;
                cout<<"Podaj imie:"<<endl;
                cin>>im;
                cout<<"Podaj nazwiosko:"<<endl;
                cin>>n;
                cout<<"Podaj wiek:"<<endl;
                cin>>w;
                set<uczen*>::iterator i;
                for(i=uczniowie.begin();i!=uczniowie.end();i++){
                    if(((*i)->imie==im)&&((*i)->nazwisko==n)&&((*i)->wiek==w)){
                            uczniowie.erase(i);
                    }
                }
            }
            catch(const char *k){
                cout<<k<<endl;
            }
            cout<<"-------------------"<<endl;
            cout<<endl;
        }

        if(wybierz==3){
            cout<<endl;
            cout<<"-------------------"<<endl;
            try{
                if(uczniowie.empty()) throw "Nie ma co wyswietlic";
                set<uczen*>::iterator j;
                for(j=uczniowie.begin();j!=uczniowie.end();j++){
                    (*j)->wypisz();
                }
            }
            catch(const char *k){
                cout<<k<<endl;
            }
            cout<<"-------------------"<<endl;
                cout<<endl;
        }
        if(wybierz==4){
            break;
        }
        wybierz=menu();
    }

    cout << "Koniec programu!" << endl;
    return 0;
}
