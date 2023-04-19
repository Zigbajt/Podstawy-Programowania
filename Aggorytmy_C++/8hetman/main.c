#include <stdio.h>
#include <stdlib.h>

int hetman(int n,int x,int **tab){
    for(int i=0;i<n;i++){
        if(tab[x][i] && wolne(tab,n,x)==0){
            tab[x][i]=1;
            if(x==n-1){
                return 1;
            }
            if(hetman(n,x+1,tab)==0){
                tab[x][i]=0;
            }else{
                return 1;
            }
        }
    }
    return 0;
}
int wolne(int **w,int y,int x){
    int i;
    for (i=0; i<x; i++){
        if (w[x][i]-i==y-x || w[x][i]+i==y+x || w[x][i]==y){
            return 0;
        }
    }
    return 1;
}
int Zeruj(int **tab,int n){
    int i,j,z=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tab[i][j]=z;
        }
        printf("\n");
    }
}
int wprowadz_wielkosc_szachownicy(void){
    int liczba;
    printf("Podaj rozmiar szachownicy:\n");
    scanf("%d",&liczba);
    return liczba;
}
void Wypisz(int **tab,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    int rozmiar_szachownicy;
    rozmiar_szachownicy=wprowadz_wielkosc_szachownicy();
    int **szachownica;
    szachownica = malloc( rozmiar_szachownicy * sizeof( int * ) );
    if ( szachownica == NULL ){
        printf("Pamiec juz przydzielona!\n");
    }
    for ( i = 0; i < rozmiar_szachownicy; i++ ) {
        szachownica[i]= malloc( rozmiar_szachownicy * sizeof( int ) );

        if ( szachownica[i] == NULL )
        {
            printf("Pamiec juz przydzielona!\n");
        }
    }
    Zeruj(szachownica,rozmiar_szachownicy);
    hetman(rozmiar_szachownicy,0,szachownica);
    Wypisz(szachownica,rozmiar_szachownicy);

    return 0;
}

