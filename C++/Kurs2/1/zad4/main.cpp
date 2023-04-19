#include <iostream>

using namespace std;

class StaleMatematyczne{
    public:
    static float wartosc;
};
float StaleMatematyczne::wartosc=2.2046;
float konwersja(StaleMatematyczne w,float kg){
    float funt=0;
    funt=kg*w.wartosc;
    return funt;

}
int main()
{
    StaleMatematyczne w;
    float kilogramy=0;
    cout << "Podaj kilogramy:" << endl;
    cin>>kilogramy;
    if(kilogramy<0){
        cout<<"Niepodales niewlasciwa wartosc!"<<endl;
    }else{
        cout<< kilogramy<<" kg = "<<konwersja(w,kilogramy)<<" funt"<<endl;
    }
    return 0;
}
