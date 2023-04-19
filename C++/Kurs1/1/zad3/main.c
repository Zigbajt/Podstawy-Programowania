#include <stdio.h>
#include <stdlib.h>

void licz(FILE *f){
    int wynik=0;
    int wynik1=0;
    for(int i=1;i<=100;i++){
      wynik=i*i;
      wynik1=i*i*i;
      fprintf(f,"x= %d x^2= %d x^3= %d \n",i,wynik,wynik1);
    }
}

int main()
{
    FILE *plik;
    plik = fopen("liczby.txt","w+");
    if(plik == NULL) {
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    licz(plik);
    if(fseek(plik,0,SEEK_SET)==-1) {
        printf("Blad operacji przesuwania wskaznika pliku!\n");
    return 0;
    }
    licz(plik);
    if(fclose(plik))
        printf("Blad zamkniecia pliku!\n");
    return 0;
}
