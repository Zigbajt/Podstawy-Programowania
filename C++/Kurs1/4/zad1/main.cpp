#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream File;
    File.open("tekst.txt");
    string dane;
    while(dane!="koniec"){
        cout<<"Podaj ciag"<<endl;
        getline(cin,dane);
        File<<dane;
    }
    File.close();
    return 0;
}
