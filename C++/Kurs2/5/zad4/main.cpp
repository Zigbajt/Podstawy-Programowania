#include <iostream>

using namespace std;

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
    friend istream & operator >> (istream &wpisz,wektor &v){
        cout<<"Podaj wartosc x"<<endl;
        wpisz>>v.x;
        cout<<"Podaj wartosc y"<<endl;
        wpisz>>v.y;
        cout<<"Podaj wartosc z"<<endl;
        wpisz>>v.y;
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
    friend ostream & operator<<(ostream & wypisz, wektor & v){
        wypisz<<"WEKTOR: ("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
    }
};
int main()
{
    cout<<"PODAJ WEKTOR 1"<<endl;
    wektor w1(0,0,0);
    cin>>w1;
    cout<<"PODAJ WEKTOR 2"<<endl;
    wektor w2(0,0,0);
    cin>>w2;
    cout<<w1;
    cout<<w2;
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
