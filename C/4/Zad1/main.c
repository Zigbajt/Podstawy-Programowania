#include <stdio.h>
#include <stdlib.h>

struct deque_node{
    int id;
    struct deque_node *next , * prev ;
};
struct deque_pointers{
    struct deque_node *head , * tail ;
};

void enqueue(struct deque_pointers *deque_node, int id){
        struct deque_node *new_node = (struct deque_node *)malloc(sizeof(struct deque_node));
        if(new_node!=NULL){
            new_node->id=id;
            new_node->prev=deque_node->tail;
            new_node->next=NULL;

            if(deque_node->tail==NULL){
                deque_node->tail=deque_node->head=new_node;
            }else{
                deque_node->tail->next=new_node;
                deque_node->tail=new_node;
            }
        }
}
void dequeuehead(struct deque_pointers *deque_node)
{
    if(deque_node->head!=NULL)
    {
        struct queue_node *tmp=deque_node->head->next;
        free(deque_node->head);
        deque_node->head=tmp;

        if(tmp==NULL)
        {
            deque_node->tail=NULL;
        }
        if(tmp!=NULL)
        {
            deque_node->head->prev=NULL;
        }
    }
}
void dequeuetail(struct deque_pointers *deque_node)
{
    if(deque_node->tail!=NULL)
    {
        struct queue_node *tmp=deque_node->tail->prev;
        free(deque_node->tail);
        deque_node->tail=tmp;

        if(tmp==NULL)
        {
            deque_node->head=NULL;
        }
        if(tmp!=NULL)
        {
            deque_node->tail->next=NULL;
        }
    }
}
void print(struct deque_pointers deque_node)
{

    while(deque_node.head!=NULL){
        printf("%d \n",deque_node.head->id);
        deque_node.head=deque_node.head->next;
    }
}

int main()
{
    struct deque_pointers deque_node={NULL,NULL};
    int liczba,x;
    while(1){
        printf("1-Zakoncz\n");
        printf("2-Dodaj\n");
        printf("3-Usun w glowie\n");
        printf("4-Usun w ogonie\n");
        printf("5-Wypisz\n");
        scanf("%d",&liczba);

        if(liczba==2){
            printf("Podaj id:\n");
            scanf("%d",&x);
            enqueue(&deque_node,x);
        }
        if(liczba==3){
            dequeuehead(&deque_node);
        }
        if(liczba==4){
            dequeuetail(&deque_node);
        }
        if(liczba==5){
            printf("Polaczone elementy:\n");
            print(deque_node);
            printf("\n");
        }
        if(liczba==1){
            break;
        }
    }



    return 0;
}
