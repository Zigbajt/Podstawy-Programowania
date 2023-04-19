#include "plik.h"

int silnia(int n){
    if(n<2){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return n*silnia(n-1);
}
