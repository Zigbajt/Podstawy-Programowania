#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
/*
5. Napisz program, w którym utworzysz macierz dynamiczną, wypełnisz ją liczbami
całkowitymi należącymi do przedziału [−10, 10] oraz wypiszesz na ekran zawartość
tej macierzy i sumę elementów leżących na jej przekątnej. Program przed zakończeniem
pracy powinien usunąć macierz. Wskazówki znajdziesz w książce B. W.
Kernighana i D. M. Ritchie’go.
*/
int tab1(int **tab,int wiersz , int kolumna){

tab=malloc(wiersz * sizeof(int*));
    for(int i=0; i<wiersz; i++){
        tab[i]=malloc(kolumna*sizeof(int));
    }
    return tab;
}
//------------------------------------------------------------------------------------
int wartosci(int wiersz,int kolumna,int **tab)
{
     for(int i=0;i<wiersz;i++)
        for(int j=0;j<kolumna;j++)
            {
            srand(time);
            tab[i][j]=rand()%21-11;
            }
    return tab;
}
//-------------------------------------------------------------------------------------
void wypisanie(int wiersz,int kolumna,int **tab)
{
     for(int i=0;i<wiersz;i++){
        for(int j=0;j<kolumna;j++){
            printf("%d", tab[i][j]);
        }
        printf("\n");
}
}
//-----------------------------------------------------------------------------------
void czyszczenie(int kolumna,int **tab)
{
    for(int i=0; i<kolumna; i++)
        free(tab[i]);
    free(tab);
}
//---------------------------------------------------------------------------------
int suma1(int wiersz,int **tab)
{
    int suma=0,j=1;
    for(int i=0;i<wiersz;i++,j++)
    {
        suma+=tab[i][j];
    }
    return suma;
}
//--------------------------------------------------------------------------------------
int main()
{
    int wiersz,kolumna;
    printf("Podaj ilosc wierszy: \n");
    scanf("%d",&wiersz);
    printf("Podaj ilosc kolumn: \n");
    scanf("%d",&kolumna);

    int **tab;
    tab1(tab,wiersz,kolumna);
    wartosci(wiersz,kolumna,tab);
    wypisanie(wiersz,kolumna,tab);
    int wynik=suma1(wiersz,tab);
    printf("Suma wartosci po przekatnej wynosi: ",wynik);
    czyszczenie(kolumna,tab);




    return 0;
}
