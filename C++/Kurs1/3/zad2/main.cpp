#include <iostream>

using namespace std;

class stac {
    public:
        int tab[128];
        int n;
        void cl();
        void push(int el);
        int pop();
};
void stac::cl(){
    n=0;
}
void stac::push(int el) {
    if (n < 128) {
        tab[n] = el;
        n++;
    }
}
int stac::pop(){
    if (n == 0) return(0);
    n--;
    return(tab[n]);
}
int main()
{
    stac stack1, stack2;
    stack1.cl();
    for(int i=0;i<5;i++){
        stack1.push(i);
    }
    stack2.cl();
    stack2.push(4);
    stack2.push(6);
    cout<<"Stos nr 1:"<<endl;
    for(int j=0;j<5;j++){
        cout<<stack1.pop()<<endl;
    }
    cout<<"Stos nr 2:"<<endl;
    cout<<stack2.pop()<<endl;
    cout<<stack2.pop()<<endl;
    cout<<stack2.pop()<<endl;
    return 0;
}
