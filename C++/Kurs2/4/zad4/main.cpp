#include <iostream>

using namespace std;

float wybierz_wartosc_wektora(int rodzaj){
    float liczba;
    if(rodzaj==1){
        cout<<"Podaj wartosc x"<<endl;
        cin>>liczba;
    }
    if(rodzaj==2){
        cout<<"Podaj wartosc y"<<endl;
        cin>>liczba;
    }
    if(rodzaj==3){
        cout<<"Podaj wartosc z"<<endl;
        cin>>liczba;
    }
    cout<<endl;
    return liczba;
}
class wektor{
    float x;
    float y;
    float z;
public:
    wektor(float xx,float yy,float zz){
        x=xx;
        y=yy;
        z=zz;
    }
    bool operator==(wektor &u){
        if((x==u.x)&&(y==u.y)&&(z==u.z)){
            return true;
        }else{
            return false;
        }
    }
    bool operator!=(wektor &u){
        if((x!=u.x)||(y!=u.y)||(z!=u.z)){
            return true;
        }else{
            return false;
        }
    }
    void wypisz(){
        cout<<"WEKTOR: ("<<x<<","<<y<<","<<z<<")"<<endl;
    }
};
int main()
{
    float x,y,z;
    cout<<"PODAJ WEKTOR 1"<<endl;
    x=wybierz_wartosc_wektora(1);
    y=wybierz_wartosc_wektora(2);
    z=wybierz_wartosc_wektora(3);
    wektor w1(x,y,z);
    cout<<"PODAJ WEKTOR 2"<<endl;
    x=wybierz_wartosc_wektora(1);
    y=wybierz_wartosc_wektora(2);
    z=wybierz_wartosc_wektora(3);
    wektor w2(x,y,z);
    w1.wypisz();
    w2.wypisz();
    cout<<endl;
    cout<<"SPRAWDZANIE ROWNOSCI"<<endl;
    if(w1==w2){
        cout<<"wektory sa rowne"<<endl;
    }else{
        cout<<"wektory sa rozne"<<endl;
    }
    cout<<endl;
    cout<<"SPRAWDZANIE ROZNOSCI"<<endl;
    cout<<endl;
    if(w1!=w2){
        cout<<"rozne"<<endl;
    }else{
        cout<<"rowne"<<endl;
    }
    cout<<endl;
    cout << "Koniec programu!" << endl;
    return 0;
}
