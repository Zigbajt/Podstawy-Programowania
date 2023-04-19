#include <iostream>
#include <string>
#include <vector>
using namespace std;
void wypisz(vector<string> osoby){
    vector<string>::iterator x; //Zadanie 5
    for(x=osoby.begin();x!=osoby.end();x++){
        cout<<*x<<" ";
    }
}
int main(){
    vector<string> osoby; //zadanie 4 bardzej rozudowana wersja w zadaniu nr 6
    string imie;
    for(int i=1;i<=6;i++){
        cout<<"Podaj imie "<<i<<":"<<endl;
        cin>>imie;
        osoby.push_back(imie);
    }
    cout<<endl;
    cout<<"Pierwszy element "<<osoby.front()<<endl;
    cout<<"Ostatni element "<<osoby.back()<<endl;
    cout<<endl;
    wypisz(osoby);
    return 0;
}
