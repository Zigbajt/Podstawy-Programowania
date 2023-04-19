#include <iostream>
#include <vector>
using namespace std;

void zadanie10(){
    vector<string> znaki;
    string ciag;
    int ilosc;
    cout<<"Podaj ilosc elementow"<<endl;
    cin>>ilosc;
    cout<<"--------------------------"<<endl;
    for(int i=0;i<ilosc;i++){
        cout<<"Podaj ciag: "<<endl;
        cin>>ciag;
        znaki.push_back(ciag);
    }
    for(int j=0;j<znaki.size();j++){
        cout<<znaki[j]<<" ";
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Pierwszym elementem jest: "<<znaki.front()<<endl;
    cout<<"Ostatnim elementem jest: "<<znaki.back()<<endl;
}
int main()
{
    zadanie10();
    return 0;
}
