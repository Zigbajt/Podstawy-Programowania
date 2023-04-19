#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dll_node
{
    int data;
    struct dll_node *prev, *next;
};

struct dll_with_guards
{
    struct dll_node *front, *back;
};

bool create_list(struct dll_with_guards *dll)
{
    struct dll_node *front = (struct dll_node *)
        malloc(sizeof(struct dll_node));
    struct dll_node *back = (struct dll_node *)
        malloc(sizeof(struct dll_node));
    if ((NULL != front) && (NULL != back))
    {
        dll->front = front->prev = back->prev = front;
        dll->back = front->next = back->next = back;
        return true;
    }
    free(front);
    free(back);
    return false;
}
void insert_node(struct dll_with_guards *front, int data)
{
    if (NULL == front)
        return NULL;

    struct dll_node *new_node = (struct dll_node *)malloc(sizeof(struct dll_node));
    if (NULL != new_node)
    {
        if(front->front=NULL){
            front->back=new_node;
            front->front=new_node;
        }
        new_node->
    }
}


void remove_list(struct dll_with_guards *dll)
{
    while (dll->front != dll->back)
    {
        struct dll_node *next = dll->front->next;
        free(dll->front);
        dll->front = next;
    }
    free(dll->back);
    dll->front = dll->back = NULL;
}

int main()
{
    struct dll_with_guards dll = {NULL, NULL};

    if (create_list(&dll))
    {
        //insert_node(&dll,23);
        // Wykonaj jakieœ operacje na liœcie.
        remove_list(&dll);
    }
    return 0;
}
