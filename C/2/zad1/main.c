#include <stdio.h>
#include <stdlib.h>
#define rozmiar 7
struct stos{
    int data[rozmiar];
    int top;
};
struct stos *push(struct stos *top,int data[]){
    struct stos *new_stos=NULL;
    if(new_stos==NULL){
        printf("Blad przydzia³u pamiêci\n");
        return top;
    }
    new_stos->data[i]=
    new_stos->top=top;
    top=new_stos;

    return top;
};
int peek (struct stos *top)
{
    if (top != NULL){
        return top->data[rozmiar];
    }
    printf("Stos nie istnieje\n");
    return -1;
}

int main()
{
    peek(*top)
    struct stos *top = NULL;

    int data[rozmiar];
    for(int i=0;i<rozmiar;i++){
        data[i]=rand()%10;
        top=push(top,data);
        peek(top);
        printf("klade element %d na stos\n",data);
    }
    while(top!=NULL){

    }
    //printf("Hello world!\n");
    return 0;
}
