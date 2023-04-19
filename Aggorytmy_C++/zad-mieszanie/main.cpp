#include <iostream>

using namespace std;

int mieszanie(int klucz,int n,int p){
    int w=(klucz%p)%n;
    return w;
}
int main()
{
    cout<<mieszanie(4567,500,521)<<endl;
    //cout << "Hello world!" << endl;
    return 0;
}
