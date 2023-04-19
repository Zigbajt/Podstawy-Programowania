#include <iostream>

using namespace std;

int silnia(int n){
    if(n<2){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return n*silnia(n-1);
}
int main()
{
    int liczba;
    cout << "Oblicz silnie dla:" << endl;
    cin>>liczba;
    cout << "Silnia dla "<<liczba<<" wynosi: "<<silnia(liczba)<<endl;
    return 0;
}
