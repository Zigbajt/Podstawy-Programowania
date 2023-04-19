#include <iostream>
#include <string>
#include <vector>
using namespace std;

void zadanie11(){
    vector<string> znaki;
    string ciag,szukaj;
    int ilosc;
    cout<<"Podaj ilosc elementow"<<endl;
    cin>>ilosc;
    cout<<"--------------------------"<<endl;
    for(int i=0;i<ilosc;i++){
        cout<<"Podaj ciag: "<<endl;
        cin>>ciag;
        znaki.push_back(ciag);
    }
    cout<<"Podaj ciag do szukania: "<<endl;
    cin>>szukaj;
    for(int j=0;j<znaki.size();j++){
        size_t found=znaki[j].find(szukaj);
        if (found!=std::string::npos)
            cout<<"Znaleziono poszukiwany ciag w vektorze nr: " << j <<endl;
        }
}
int main()
{
    zadanie11();
    return 0;
}
