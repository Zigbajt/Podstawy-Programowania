#include <iostream>

using namespace std;

class Figura{
public:
    float pole(){
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
cout<<"<-zadanie1->"<<endl;
Kolo kolo(5);
Prostokat protokat(3,6);
Kwadrat kwadrat(5);
cout << "Pole kola = " << kolo.pole() << endl;
cout << "Pole prostokata = " << protokat.pole() << endl;
cout << "Pole kwadratu = " << kwadrat.pole() << endl;

cout<<"-------------------"<<endl;
Figura figury[3] = {Kolo(5), Kwadrat(5), Prostokat(3,6)};
for (int i = 0; i < 3; i++)
cout << "Pole figury " << i << " = " << figury[i].pole() << endl;


return 0;
}

