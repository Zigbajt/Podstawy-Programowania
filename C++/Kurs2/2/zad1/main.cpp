#include <iostream>
#include <list>

using namespace std;

int menu(void){
    int wybierz=0;
    do{
    cout<<"WYBIERZ METODE STOSU:"<<endl;
    cout<<"1.DODAJ"<<endl;
    cout<<"2.USUN"<<endl;
    cout<<"3.WYSWIETL"<<endl;
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
list <int> dodaj(list <int> stos){
    int liczba;
    cout<<"Podaj wartosc"<<endl;
    cin>>liczba;
    stos.push_back(liczba);
    cout<<endl;
    cout<<"-------------------"<<endl;
    cout<<endl;
    return stos;
}
void wyswietl(list <int> stos){
    cout<<"Wartosci stosu"<<endl;
    cout<<endl;
    if(stos.empty()){
        cout<<"pusty"<<endl;
    }else{
    list<int>::iterator i;
        for(i=stos.begin();i!=stos.end();i++){
            cout<<*i<<" ";
        }
    }
    cout<<endl;
    cout<<"------------------"<<endl;
    cout<<endl;
}
int main()
{
    list <int> stos;
    int wybierz;
    wybierz=menu();
    while(1){
        if(wybierz==1){
            stos=dodaj(stos);

        }
        if(wybierz==2){
            stos.pop_back();
        }
        if(wybierz==3){
            wyswietl(stos);
        }
        if(wybierz==4){
            break;
        }

        wybierz=menu();
    }
    cout << "Koniec programu!" << endl;
    return 0;
}
