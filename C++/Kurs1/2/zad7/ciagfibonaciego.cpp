#include "plik.h"

int Ciagfibonacziego(int n){
    if(n<=1){
        return n;
    }
    return Ciagfibonacziego(n-1)+Ciagfibonacziego(n-2);

}
