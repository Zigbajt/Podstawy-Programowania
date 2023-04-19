#include <iostream>

using namespace std;

void zachlanny(int reszta){
    int l;
    int tab[7]={100,50,20,10,5,2,1};
    for(int i=0;i<7;i++){
        if(reszta>0){
            if(reszta>=tab[i]){
                l=reszta/tab[i];
                reszta=reszta-tab[i]*l;
                cout<<tab[i]<< "   " << l <<endl;
            }
        }
    }
}
void silowy(int reszta){
    int tab[7]={100,50,20,10,5,2,1};
    int rozwiazania;
    int ile_banknotow[]={0,0,0,0,0,0,0};
    for(int i=0;i<reszta/100;i++){



    }
}



int main()
{
    int liczba;
    cout<<"Podaj reszte: "<<endl;
    cin>>liczba;
    silowy(liczba);
    return 0;
}
