#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int losuj(int **tab,int liczba1,int liczba2){
    srand(time(NULL));
    int i,j;
    for(i=0;i<liczba1;i++){
        for(j=0;j<liczba2;j++){
            tab[i][j]=rand()%11-5;
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    return tab;
}
int dodaj(int **tab,int liczba1,int liczba2){
    int i,j,z=0;
    int suma=0;
    while(z<liczba1 && z<liczba2){
            suma+=tab[z][z];
        z++;
    }
    printf("Suma wynosi: %d \n",suma);
    return suma;
}
int zwolnij(int **tab,int liczba1,int liczba2){
    int i;
    for ( i = 0; i < liczba1; i++ ) {
        free(tab[i]);
        tab[i]=NULL;
    }
    free(tab);
}

int main()
{
    int i, j;
    int liczba1,liczba2;
    printf("Podaj ilosc wierszy:\n");
    scanf("%d",&liczba1);
    printf("Podaj ilosc kolumn:\n");
    scanf("%d",&liczba2);
    int **tab;
    tab = (int **)malloc( liczba1 * sizeof( int * ) );
    if ( tab == NULL ){
        printf("Pamiec juz przydzielona!\n");
    }
    for ( i = 0; i < liczba1; i++ ) {
        tab[i]= (int *)malloc( liczba2 * sizeof( int ) );

        if ( tab[i] == NULL )
        {
            printf("Pamiec juz przydzielona!\n");
        }
    }
    losuj(tab,liczba1,liczba2);
    dodaj(tab,liczba1,liczba2);
    zwolnij(tab,liczba1,liczba2);
    //printf("Hello world!\n");
    return 0;
}
