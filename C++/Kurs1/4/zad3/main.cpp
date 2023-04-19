#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    //zadanie3
    ofstream plik;
    plik.open("plik.abc",ios::binary);
    srand(time(NULL));
    int liczba;
    for(int i=0;i<10;i++){
        liczba=rand()%10;
        //cout<<liczba<<endl;
        plik.write(reinterpret_cast<char*>(&liczba),sizeof(liczba));
    }
    plik.close();
    cout<<endl;
    //zadanie4
    ifstream file;
    file.open("plik.abc",ios::binary);
    int x;
    int tab[10]{0,0,0,0,0,0,0,0,0,0}; //zadanie 5
    for(int j=0;j<10;j++){
        file.read(reinterpret_cast<char*>(&x),sizeof(x));
        cout<<x<<endl;
        tab[x]++;
    }
    cout<<"-------------"<<endl;
    //zadanie 5
    cout<<"Haistogram:"<<endl;
    cout<<"-------------"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<"  :  ";
        for(int j=0;j<tab[i];j++){
            cout<<"*";
        }
        cout<<endl;
    }
    file.close();
    return 0;
}
