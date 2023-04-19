#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>


using namespace std;

int *sortuj(int *tab,int ilosc){
    int liczba,x,j;
    for(int i=0;i<ilosc;i++){
        liczba=i;
        for(j=i+1;j<ilosc;j++){
            //cout<<liczba<<endl;
            if(tab[j]<tab[liczba]){
                liczba=j;
            }
        }
        //cout<<endl;
        x=tab[i];
        tab[i]=tab[liczba];
        tab[liczba]=x;
        //swap(tab[liczba],tab[i]);
    }
    return tab;
}
int *shella(int tab[],int ilosc){
    int h=ilosc/2;
    int i;
    while(h>=1){
        i=0;
        for(int j=h;j<ilosc;j++){
            if(tab[i]>tab[j]){
            swap(tab[i],tab[j]);
            }
            i++;
        }
        h=h/2;
    }
    return tab;
}
int main()
{
    int ilosc=8;
    int tab[ilosc];
    srand(time(NULL));
    for(int i=0;i<ilosc;i++){
        tab[i]=rand()%20;
    }
    cout << "---------------" << endl;
    cout << "Nieposortowana" << endl;
    cout << "---------------" << endl;
    for(int i=0;i<ilosc;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;

    sortuj(tab,ilosc);
    //shella(tab,ilosc);

    cout << "---------------" << endl;
    cout << "Posortowana" << endl;
    cout << "---------------" << endl;
    for(int i=0;i<ilosc;i++){
        cout<<tab[i]<<" ";
    }
    return 0;
}
