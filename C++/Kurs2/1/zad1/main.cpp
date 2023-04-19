#include <iostream>

using namespace std;
float konwersja(float kg){
    float funt=0;
    funt=kg*2.2046;
    return funt;
}

int main()
{
    float kilogramy=0;

    cout << "Podaj kilogramy:" << endl;
    cin>>kilogramy;
    if(kilogramy<0){
        cout<<"Niepodales niewlasciwa wartosc!"<<endl;
    }else{
        cout<< kilogramy<<" kg = "<<konwersja(kilogramy)<<" funt"<<endl;
    }
    return 0;
}
