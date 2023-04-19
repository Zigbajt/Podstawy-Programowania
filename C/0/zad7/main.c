#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=7;
    int tab[x][x];
    losuj(tab,x);
    wypisz(tab,x);
    printf("iiko");
    return 0;
}
int losuj(int *tab[],int liczba){
    srand(time(NULL));
    for(int i=0;i<liczba;i++){
        for(int j=0;j<liczba;j++){
            tab[i][j]=rand()%11-5;
        }
    }
    return tab;
}
void wypisz(int *tab[],int liczba){
    srand(time(NULL));
    for(int i=0;i<liczba;i++){
        for(int j=0;j<liczba;j++){
            printf("%d",tab[i][j]);
        }
    }
}
