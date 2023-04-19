#include <stdio.h>
#include <stdlib.h>

float ciag_nr1(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 3;
    }
    if(n==3){
        return 9;
    }
    if(n>3){
        float x=(ciag_nr1(n-3)+ciag_nr1(n-2));
        float y=ciag_nr1(n-1);
        return x/y;
    }
}
int ciag_nr2(int n){
    if(n<5){
        return n-1;
    }
    if(n==5){
        return 6;
    }
    if(n==6){
        return 11;
    }
    if(n>6){
        return ciag_nr2(n-1)+ciag_nr2(n-2)+ciag_nr2(n-3);
    }
}
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
    float x=0,y=0,z=0;
    int n=5;
    //x=ciag_nr1(n);  // wystêpuj¹ b³êdy w rekurencji
    //printf("Wynik ciagu pierwszego: %lf\n",x);
    y=ciag_nr2(n);
    printf("Wynik ciagu drugiego: %lf\n",y);
    z=fibonaci_drugiego_rzedu(n);
    printf("Wynik fibonaci drugiego rzedu: %lf\n",z);
    return 0;
}
