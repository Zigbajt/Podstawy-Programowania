#include <stdio.h>
#include <stdlib.h>

int Ciagfibonacziego(int n){
    if(n<=1){
        return n;
    }
    return Ciagfibonacziego(n-1)+Ciagfibonacziego(n-2);

}
int main()
{
    printf("Ciag wynosi: %d\n",Ciagfibonacziego(0));
    return 0;
}
