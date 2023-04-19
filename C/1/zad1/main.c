#include <stdio.h>
#include <stdlib.h>

int ciag_arytmetyczny(int a1,int an,int n){
    return ((a1+an)/2)*n;
}
int ciag_geometryczny(int a1,int n, int q){
    if(q==1){
        return a1*n;
    }else{
        return a1*((1-pow(q,n))/(1-q));
    }
}
void wypisz(int wynik){
    printf("wynik ciagu wynosi: %d",wynik);
}
int main()
{
    int (*funkcja_ciag_arytmetyczny)(int,int,int)=ciag_arytmetyczny;
    int (*funkcja_ciag_geometryczny)(int,int,int)=ciag_geometryczny;
    int (*funkcja_wynik)(int)=wypisz;

    int a1=2,an=30,n=8,q=3;
    int y=funkcja_ciag_arytmetyczny(a1,an,n);
    funkcja_wynik(y);
    printf("\n");
    int x=funkcja_ciag_geometryczny(a1,n,q);
    funkcja_wynik(x);
    return 0;
}
