#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dll_node
{
    int data;
    struct dll_node *prev, *next;
};
struct stos{
    int data;
    struct stos *next;
};
struct dll_node *create_list(int data)
{
    struct dll_node *new_node = (struct dll_node *)
        malloc(sizeof(struct dll_node));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->prev = new_node->next = new_node;
    }
    return new_node;
}

struct dll_node *find_max_node(struct dll_node *node)
{
    struct dll_node *start = node, *result = node;
    int maximum = node->data;
    do
    {
        if (maximum < node->data)
        {
            maximum = node->data;
            result = node;
        }
        node = node->next;
    } while (node != start);
    return result;
}
struct dll_node *find_min_node(struct dll_node *node)
{
    struct dll_node *start = node, *result = node;
    int min = node->data;
    do
    {
        if (min > node->data)
        {
            min = node->data;
            result = node;
        }
        node = node->next;
    } while (node != start);
    return result;
}

struct dll_node *find_next_node(struct dll_node *node, int data)
{
    node = find_max_node(node);
    struct dll_node *start = node;
    do
    {
        if (node->data < data)
            break;
        node = node->next;
    } while (node != start);
    return node;
}

void insert_node(struct dll_node *node, int data)
{
    if (NULL == node)
        return;

    struct dll_node *new_node = (struct dll_node *)
        malloc(sizeof(struct dll_node));
    if (NULL != new_node)
    {
        new_node->data = data;
        node = find_next_node(node, data);
        new_node->next = node;
        new_node->prev = node->prev;
        node->prev->next = new_node;
        node->prev = new_node;
    }
}

struct dll_node *delete_node(struct dll_node *node, int data)
{
    if (NULL == node)
        return NULL;

    node = find_next_node(node, data);
    node = node->prev;
    if (node->data == data)
    {
        if (node == node->next)
        {
            free(node);
            return NULL;
        }
        else
        {
            struct dll_node *next = node->next;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            free(node);
            node = next;
        }
    }
    return node;
}

void print_list(struct dll_node *node,bool doprzodu)
{
    if(doprzodu==true){
    if (NULL == node)
        return;

    node = find_max_node(node);
    struct dll_node *start = node;
    do
    {
        printf("%d ", node->data);
        node = node->next;
    } while (node != start);
    printf("\n");
    }else{
    if (NULL == node)
        return;

    node = find_min_node(node);
    struct dll_node *start = node;
    do
    {
        printf("%d ", node->data);
        node = node->prev;
    } while (node != start);
    printf("\n");

    }
}

void remove_list(struct dll_node **node)
{
    if (NULL == *node)
        return;

    struct dll_node *start = *node;
    do
    {
        struct dll_node *next = (*node)->next;
        free(*node);
        *node = next;
    } while (*node != start);
    *node = NULL;
}
struct stos *szukaj(struct dll_node *node,int liczba,struct stos *top){
    if(node==NULL){
        printf("Pusta");
        return;
    }
    struct dll_node *start = node, *result = node;
    do
    {
        if (liczba==node->data)
        {
            printf("TO: %d\n",node);

            struct stos *new_node = (struct stos *)
            malloc(sizeof(struct stos));
            if (NULL != new_node){
                new_node->data = node;
                new_node->next = top;
                top = new_node;
            }

        }
        node = node->next;
    } while (node != start);
    return top;

}
int peek(struct stos *top)
{
    if (NULL != top)
        return top->data;

    fprintf(stderr, "Stack is empty.\n");
    return -1;
}
int pop(struct stos **top)
{
    int result = -1;
    if (NULL != *top)
    {
        result = (*top)->data;
        struct stos *tmp = (*top)->next;
        free(*top);
        *top = tmp;
    }
    return result;
}

int main()
{
    struct dll_node *dlcl = create_list(1);
    int i;

    for (i=2; i<5; i++)
        insert_node(dlcl, i);
    for (i=6; i<10; i++)
        insert_node(dlcl, i);
    printf("List elements:\n");
    print_list(dlcl,true);

    insert_node(dlcl, 0);
    printf("List elements after insertion of 0:\n");
    //print_list(dlcl);
    insert_node(dlcl, 5);
    printf("List elements after insertion of 5:\n");
    //print_list(dlcl);
    insert_node(dlcl, 7);
    insert_node(dlcl, 7);
    insert_node(dlcl, 7);
    insert_node(dlcl, 7);
    insert_node(dlcl, 7);
    printf("List elements after insertion of 7:\n");
    //print_list(dlcl);
    insert_node(dlcl, 10);
    printf("List elements after insertion of 10:\n");
    print_list(dlcl,true);
    print_list(dlcl,false);
    struct stos *top = NULL;
    top=szukaj(dlcl,10,top);
    //top=push(dlcl,7,top);
    while (NULL != top)
        printf("%d ", pop(&top));
    dlcl = delete_node(dlcl, 0);
    //printf("List elements after deletion of 0:\n");
    //print_list(dlcl);
    dlcl = delete_node(dlcl, 1);
    //printf("List elements after deletion of 1:\n");
    //print_list(dlcl);
    dlcl = delete_node(dlcl, 1);
    //printf("List elements after deletion of 1:\n");
    //print_list(dlcl);
    dlcl = delete_node(dlcl, 5);
    //printf("List elements after deletion of 5:\n");
    //print_list(dlcl);
    dlcl = delete_node(dlcl, 7);
    //printf("List elements after deletion of 7:\n");
    //print_list(dlcl);
    dlcl = delete_node(dlcl, 10);
    //printf("List elements after deletion of 10:\n");
    //print_list(dlcl,true);

    remove_list(&dlcl);
    return 0;
}
