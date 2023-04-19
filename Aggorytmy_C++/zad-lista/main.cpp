#include <iostream>

using namespace std;

struct lista{
    lista *nastepny;
    int id;
};
lista *pocz=NULL;
lista *q, *s;

int a[10] ={0,1,2,3,4,5,6,7,8,9};

void GenerujListe(){
    int i=0;
    while(i<10){
        q= new lista;
        q->nastepny=pocz;
        q->id=a[i];
        pocz=q;

    }

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
