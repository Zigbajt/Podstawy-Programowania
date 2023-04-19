#include <iostream>
#include <cmath>
using namespace std;
class kawadratowa{
public:
    int a,b,c;
    float x1,x2,delta;
    void wczytaj(){
        cout<<"Podaj a:"<<endl;
        cin>>a;
        cout<<"Podaj b:"<<endl;
        cin>>b;
        cout<<"Podaj c:"<<endl;
        cin>>c;
    }
    void obliczenia(){
        try{
            if(a==0) throw "Nast¹pi dzielenie prze zero oraz nie jest to rownanie kwadratowe";
            delta=(b*b)-(4*a*c);
            if(delta < 0) throw "Delta jest mniejsza od zera oraz wystepuje brak miejsc zerowych";
            if(delta == 0)
            {
                x1 =-b/(2*a);
            }
            if(delta > 0)
            {
                x1 =(-b-sqrt(delta))/(2*a);
                x2 =(-b+sqrt(delta))/(2*a);
            }
        }
        catch(const char *r)
        {
            cout <<"WYJATEK:"<<r<< endl;
        }
    }
    void wypisz(){
        if(delta>0){
            cout<<"Funkcja ma dwa rozwiazania"<<endl;
            cout<<"x1="<<x1<<"    x2="<<x2<<endl;
        }
        if(delta==0){
            cout<<"Funkcja ma jedno rozwiazania"<<endl;
            cout<<"x1="<<x1<<endl;
        }
    }
};
int main()
{
    kawadratowa k1;
    k1.wczytaj();
    k1.obliczenia();
    k1.wypisz();
    //cout<<k1.a<<" "<<k1.b<<" "<<k1.c<<endl;
    cout << "Koniec programu!" << endl;
    return 0;
}
