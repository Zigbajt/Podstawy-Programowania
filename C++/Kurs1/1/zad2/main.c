#include <stdio.h>
#include <stdlib.h>

void zapis(FILE *f){
    char tab[100];
    printf("Podaj dane: ");
    scanf("%s",tab);

    fprintf(f,"%s ",tab);
}

int main()
{
    FILE *plik;
    plik = fopen("test.txt","a+");
    if(plik == NULL) {
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    if(fseek(plik,0,SEEK_SET)==-1) {
        printf("Blad operacji przesuwania wskaznika pliku!\n");
    return 0;
    }
    zapis(plik);
    if(fclose(plik))
        printf("Blad zamkniecia pliku!\n");
    return 0;
}
