#include <iostream>
#include <exception>
#include <cmath>

using namespace std;
class licznik: public exception{
    virtual const char* what() const throw(){
        return "Licznik musi byc wiekszy od zera";
    }
};
class mianownik: public exception{
    virtual const char* what() const throw(){
        return "Mianownik powinna byc rozna od zera";
    }
};
class wzor{
public:
    int a,b;
    float wynik;
    friend class licznik;
    friend class mianownik;
    void wczytaj(){
        cout<<"Podaj a:"<<endl;
        cin>>a;
        cout<<"Podaj b:"<<endl;
        cin>>b;
    }
    void obliczenia(){
        licznik w1;
        mianownik w2;
        try{
            if(a < 0)throw w1;
            if(b == 0)throw w2;
            wynik = sqrt(a)/b;
        }
        catch(exception &r)
        {
            cout <<"WYJATEK:"<<r.what()<<endl;
        }
    }
    void wypisz(){
        cout<<"sqrt("<<a<<")/"<<b<<" = "<<wynik<<endl;
    }
};
int main()
{
    wzor o1;
    o1.wczytaj();
    o1.obliczenia();
    o1.wypisz();
    cout << "Koniec programu!" << endl;
    return 0;
}
