#include <stdio.h>
#include <stdlib.h>

int losuj(int *tab,int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
            tab[i]=rand()%10;
    }
    return tab;

}

int wypisz(int *tab,int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
            printf("%d ",tab[i]);
    }
    printf("\n");
    return tab;

}
void sprawdz(int jaka_liczba,int i,int ilosc,int *tab,int n){
    if(jaka_liczba==tab[i]){
        ilosc++;
    }
    if(i==n){
        printf("ilosc liczby %d wynosi: %d",jaka_liczba,ilosc);
    }else{
    return sprawdz(jaka_liczba,i+1,ilosc,tab,n);
    }

}
int podaj(int wariant){
    int liczba;
    switch(wariant){
    case 1: printf("podaj wielkosc tablicy:\n"); break;
    case 2: printf("podaj jaka liczba:\n");break;
    }
    scanf("%d",&liczba);
    return liczba;
}
int main()
{
    int jaka_liczba,n;
    int *tab;
    n=podaj(1);
    tab=(int )malloc(n*sizeof(int));
    losuj(tab,n);
    wypisz(tab,n);
    jaka_liczba=podaj(2);
    sprawdz(jaka_liczba,0,0,tab,n);
    free(tab);
    return 0;
}
