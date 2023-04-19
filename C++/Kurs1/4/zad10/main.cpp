#include <iostream>
#include <sstream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    int tab[10];
    srand(time(NULL));
    for(int i=0;i<10;i++){
        tab[i]=rand()%20;
    }
    ostringstream oss;
    for(int i=0;i<10;i++){
        oss<<tab[i]<<endl;
    }
    cout<<oss.str()<<endl;
    return 0;
}
