#include <stdio.h>
#include <stdlib.h>

int losuj(int tab[7][7],int liczba){
    srand(time(NULL));
    for(int i=0;i<liczba;i++){
        for(int j=0;j<liczba;j++){
            tab[i][j]=rand()%11-5;
        }
    }
    return tab;
}
void wypisz(int tab[7][7],int liczba){
    int min=tab[0][0];
    int max=tab[0][0];
    for(int i=0;i<liczba;i++){
        for(int j=0;j<liczba;j++){
            if(min>tab[i][j]){
                min=tab[i][j];
            }
            if(max<tab[i][j]){
                max=tab[i][j];
            }
        }
    }
    printf("Wartosc minimalna %d \nWartosc maksymalna %d \n",min,max);
}
int suma(int tab[7][7],int liczba){
    int x=0;
    int suma;
    while(x<liczba){
         suma=tab[x][x]*tab[x][x]*tab[x][x];
         x++;
    }
    return suma;
}
int main()
{
    int x=7;
    int tab[x][x];
    losuj(tab,x);
    wypisz(tab,x);
    int y=suma(tab,x);
    printf("Suma szescianow przekontnej wynosi: %d\n",y);
    return 0;
}
