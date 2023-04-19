#include <iostream>
#include <vector>

using namespace std;

class Figura{
public:
    virtual float pole(){
    return 0;
    }
};
class Prostokat:public Figura{
private:
    float a, b;
public:
    Prostokat(float a, float b){
        this->a = a;
        this->b = b;
}
float pole(){
    return a*b;
}
};
class Kwadrat : public Figura{
private:
    float a;
public:
    Kwadrat(float a){
        this->a = a;
}
    float pole(){
        return a*a;
    }
};
class Kolo : public Figura{
private:
    float r;
public:
    Kolo(float r){
    this->r = r;
}
    float pole(){
        return 3.14*r*r;
    }
};
int main(int argc, char argv[]){
    Kolo kolo(5);
    Prostokat protokat(3,6);
    Kwadrat kwadrat(5);
    cout << "Pole kwadratu = " << kwadrat.pole() << endl;
    cout << "Pole prostokata = " << protokat.pole() << endl;
    cout << "Pole kola = " << kolo.pole() << endl;

cout<<"-------------------"<<endl;
{
    cout<<endl;
    cout<<"<-zadanie2->"<<endl;
    Figura* figury[3] = { new Kwadrat(5), new Prostokat(3,6),new Kolo(5)};
    for (int i = 0; i < 3; i++)
    cout << "Pole figury " << i << " = " << figury[i]->pole() << endl;

    cout<<endl;
    cout<<"<-zadanie3->"<<endl;
    vector<Figura> figury_vector1;

    figury_vector1.push_back(Kwadrat(5));
    figury_vector1.push_back(Prostokat(3,6));
    figury_vector1.push_back(Kolo(5));
    for(int i=0;i<figury_vector1.size();i++){
        cout<<"Pole figury "<<i<<" = "<<figury_vector1[i].pole()<<endl;
    }

    cout<<endl;
    cout<<"<-zadanie4->"<<endl;
    vector<Figura*> figury_vector2;
    figury_vector2.push_back(new Kwadrat(5));
    figury_vector2.push_back(new Prostokat(3,6));
    figury_vector2.push_back(new Kolo(5));
    for(int i=0;i<figury_vector2.size();i++){
        cout<<"Pole figury "<<i<<" = "<<figury_vector2[i]->pole()<<endl;
    }
    cout<<endl;
    return 0;
}
}
