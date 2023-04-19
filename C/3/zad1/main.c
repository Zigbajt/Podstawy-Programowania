#include <stdio.h>
#include <stdlib.h>

int fibonaci_drugiego_rzedu(int n){
    if(n<=1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(n>2){
        return fibonaci_drugiego_rzedu(n-1)+fibonaci_drugiego_rzedu(n-2)+fibonaci_drugiego_rzedu(n-3);
    }
}

int main()
{
    int n;
    float z=0;
    printf("podaj dlugosc fibonaciego: ");
    scanf("%d",&n);
    z=fibonaci_drugiego_rzedu(n);
    printf("Wynik fibonaci drugiego rzedu: %lf\n",z);
    return 0;
}
