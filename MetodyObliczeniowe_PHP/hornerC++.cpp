#include <iostream>

using namespace std;

float horner(float tab[],float x,int len){
    float z=0;
    float y=tab[0];
    cout<<"---------"<<endl;
    cout<<"tab = "<<tab[0]<<endl;
    cout<<"z = "<<z<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"---------"<<endl;
    int i=1;
    while(i<len){
        z=(y*x);
        y=z+tab[i];
        cout<<"---------"<<endl;
        cout<<"tab = "<<tab[i]<<endl;
        cout<<"z = "<<z<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"---------"<<endl;
        i++;
    }
    return y;
}
float *wielomian(float tab[],int len){
    int w=len-1;
    for(int i=0;i<len;i++){
        cout<<"Podaj element"<<w<<" stopnia"<<endl;
        cin>>tab[i];
        w--;
    }
    return tab;
}
int main(){
    int wielkosc=0;
    float x=0;
    float y=0;
    cout << "Schemat Hornera! " << endl;
    cout << "---------------- " << endl;
    cout << "Podaj wielkosc wielomianu: " << endl;
    cin>>wielkosc;
    wielkosc++;
    float tab[wielkosc];
    cout << "Wprowadz wartosci wielomianu: " << endl;
    wielomian(tab,wielkosc);
    cout << "Podaj wartosc x: " << endl;
    cin>>x;
    y=horner(tab,x,wielkosc);
    cout << "----------------" << endl;
    cout << "W"<<wielkosc-1<<"("<<x<<") = "<<y<< endl;
    return 0;
}
