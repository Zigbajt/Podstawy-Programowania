#include <stdio.h>
#include <stdlib.h>

double dywanSierpinskiego(double pole,int ilosczagnieszczen){
if(ilosczagnieszczen==0){
return pole;
}
return dywanSierpinskiego(pole*8.0/9.0,ilosczagnieszczen-1);
}





int main()
{
puts("Podaj dlugosc boku");
 int b=0;
 scanf("%d",&b);
 b=b*b;
 int ilosczagnieszczen=0;
 puts("Podaj iloscz zagnieszczen");
 scanf("%d",&ilosczagnieszczen);
 printf("Dlugosc boku %d daje %lf",b,dywanSierpinskiego(b,ilosczagnieszczen));
}
