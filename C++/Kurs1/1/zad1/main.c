#include <stdio.h>
#include <stdlib.h>

void odczyt_text(FILE *plik){
    int liczba;
    while(feof(plik) == 0)
   {
      fscanf(plik,"%c",&liczba);
      printf("%c",liczba);
   }
}

int main()
{
    FILE *plik;
    plik = fopen("test.txt","r");
    if(plik == NULL) {
        printf("Blad otwarcia pliku!\n");
        return 0;
    }
    //printf("Ok\n");
    odczyt_text(plik);
    if(fclose(plik))
        printf("Blad zamkniecia pliku!\n");
    return 0;

}
