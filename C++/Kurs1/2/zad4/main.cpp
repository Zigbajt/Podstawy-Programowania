#include <iostream>

using namespace std;

int Ciagfibonacziego(int n){
    if(n<=1){
        return n;
    }
    return Ciagfibonacziego(n-1)+Ciagfibonacziego(n-2);

}
int main()
{
    int wyraz;
    cout << "Podaj wyraz ciagu fibonacciego:" << endl;
    cin>>wyraz;
    cout<< "Wyraz "<< wyraz <<" ciagu fibonacciego wynosi: "<<Ciagfibonacziego(wyraz)<<endl;
    return 0;
}
