#include <iostream>

using namespace std;
class Zmiana{
public:
    static float kilogramy;
    static float konwersja(float kg);
    void wprowadz();
};
float Zmiana::kilogramy=0;
float Zmiana::konwersja(float kg){
    float funt=0;
    funt=kg*2.2046;
    return funt;
}
void Zmiana::wprowadz(){
    cout << "Podaj kilogramy:" << endl;
        cin>>kilogramy;
        if(kilogramy<0){
            cout<<"Niepodales niewlasciwa wartosc!"<<endl;
        }else{
            cout<< kilogramy<<" kg = "<<konwersja(kilogramy)<<" funt"<<endl;
        }
}

int main()
{
    Zmiana Z1;
    Z1.wprowadz();

    return 0;
}
