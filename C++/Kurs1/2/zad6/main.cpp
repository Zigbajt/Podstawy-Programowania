#include <iostream>
#include "plik.h"

using namespace std;

int main()
{

    int i;
    do{
        cout<<"1.Oblicz pole kola"<<endl;
        cout<<"2.Oblicz pole trapezu"<<endl;
        cout<<"3.Oblicz pole trojkata"<<endl;
        cout<<"4.Oblicz silnie"<<endl;
        cout<<"5.Oblicz ciag fibonacjiego"<<endl;
        cin>>i;
        if(i==1){
          double wynik=0;
          wynik=PoleKola();
          cout << "Pole kola wynosi: "<< wynik << endl << endl;
        }
        if(i==2){
          double wynik=0;
          wynik=PoleTrapezu();
          cout << "Pole trapezu wynosi: "<< wynik << endl << endl;
        }
        if(i==3){
           double wynik=0;
           wynik=PoleTrojkata();
           cout << "Pole trojkata wynosi: "<< wynik << endl << endl;
        }

        if(i==4){
            int liczba;
            cout << "Oblicz silnie dla:" << endl;
            cin>>liczba;
            cout << "Silnia dla "<<liczba<<" wynosi: "<<silnia(liczba)<<endl;
        }
        if(i==5){
            int wyraz;
            cout << "Podaj wyraz ciagu fibonacciego:" << endl;
            cin>>wyraz;
            cout<< "Wyraz "<< wyraz <<" ciagu fibonacciego wynosi: "<<Ciagfibonacziego(wyraz)<<endl;
        }
        cout<<endl;
    }while(i>=1 && i<=5);


    return 0;
}
