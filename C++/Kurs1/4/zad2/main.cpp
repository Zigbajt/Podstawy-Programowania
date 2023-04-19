#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream File;
    File.open("tekst.txt");
    string linia;
    if(File.is_open()){
        while(getline(File,linia)){
            cout<<linia<<endl;
        }
    }else{
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
    }
    File.close();
    return 0;
}
