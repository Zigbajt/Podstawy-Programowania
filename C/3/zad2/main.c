#include <stdio.h>
#include <stdlib.h>

int spirala(int a){
    if(a<=0){
        return 0;
    }
    if(a>0&&a<=3){
        return a;
    }
    if(a>3){
        return a-1+spirala(a-2);
    }
}

int main()
{
    int z,y;
    printf("podaj dlugosc pierwszego boku: ");
    scanf("%d",&y);
    z=spirala(y);
    printf("Ilosc wlaczonych pikseli jest: %d\n",z);
    return 0;
}
