#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    fstream plik;
    plik.open("plik.txt",ios::in);

    if(plik.good()==false){
        cout<<"Plik nie istniej!";
        exit(0);
    }
    string linia;
    int suma;
    float wynik;
    int nr_lini=1;
    while(getline(plik,linia)){
        suma+=atoi(linia.c_str());
        nr_lini++;
    }
    nr_lini--;
    wynik=suma/(float)nr_lini;
    cout<<"Srednia liczb w pliku wynosi: "<<wynik<<endl;
    plik.close();
    return 0;
}
