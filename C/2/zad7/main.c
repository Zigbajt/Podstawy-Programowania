#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stack_node
{
    int data;
    int min;
    struct stack_node *next;
};

struct stack_node *push(struct stack_node *top, int data)
{
    struct stack_node *new_node = (struct stack_node *)
        malloc(sizeof(struct stack_node));
    if (NULL != new_node){
        new_node->data = data;
        int wynik=sprawdz(top);
        printf("%d ---- %d\n",wynik,data);
        if(wynik<data){
            new_node->min = top;
        }
        new_node->next = top;
        top = new_node;
    }
    return top;
}

int pop(struct stack_node **top)
{
    int result = -1;
    if (NULL != *top)
    {
        result = (*top)->data;
        struct stack_node *tmp = (*top)->next;
        free(*top);
        *top = tmp;
    }
    return result;
}

int peek(struct stack_node *top)
{
    if (NULL != top)
        return top->data;

    //fprintf(stderr, "Stos nie istnieje\n");
    return -1;
}
int sprawdz (struct stack_node *top)
{
    if (NULL != top)
        return top->min;

    //fprintf(stderr, "Stos nie istnieje\n");
    return 1000;
}


int main()
{
    struct stack_node *top = NULL;
    srand(time(0));
    int liczba;
    for(int i=1;i<5;i++){
    liczba=rand()%10;
    top=push(top,i);
    printf("Wartosc ze szczytu stosu: %d\n",peek(top));
    printf("Wartosc najmniejsza znajduje sie w stosie: %d\n",sprawdz(top));
    }

    return 0;
}
