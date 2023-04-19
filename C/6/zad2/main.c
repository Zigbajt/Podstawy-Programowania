#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sll_node
{
    int data;
    struct sll_node *next;
};

bool insert_before(struct sll_node **node, int data)
{
    struct sll_node *new_node = (struct sll_node *)
        malloc(sizeof(struct sll_node));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->next = *node;
        *node = new_node;
        return true;
    }
    return false;
}

bool insert_back(struct sll_node **node, int data)
{
    *node = (struct sll_node *)malloc(sizeof(struct sll_node));
    if (NULL != *node)
    {
        (*node)->data = data;
        (*node)->next = NULL;
        return true;
    }
    return false;
}

bool insert_node(struct sll_node **node, int data)
{
    if (NULL != *node)
    {
        if ((*node)->data <= data)
            return insert_before(node, data);
        else
            return insert_node(&(*node)->next, data);
    }
    else
        return insert_back(node, data);
}

void delete_node(struct sll_node **node, int data)
{
    if (NULL != *node)
    {
        if ((*node)->data == data)
        {
            struct sll_node *next = (*node)->next;
            free(*node);
            *node = next;
        }
        else
            delete_node(&(*node)->next, data);
    }
}

void print_list(struct sll_node *node)
{
    if (NULL != node)
    {
        printf("%d ", node->data);
        print_list(node->next);
    }
    else
        printf("\n");
}

void print_list_backwards(struct sll_node *node)
{
    if (NULL != node)
    {
        print_list_backwards(node->next);
        printf("%d ", node->data);
    }
}

void remove_list(struct sll_node **node)
{
    if (NULL != *node)
    {
        remove_list(&(*node)->next);
        free(*node);
    }
}

int sumuj(struct sll_node *node,int s){
    if (NULL != node)
    {
    int nsumuj=s+node->data;
    return sumuj(node->next,nsumuj);
    }
    else{
    return s;
    }

}

int main()
{
    struct sll_node *front = NULL;
    int i;

    for (i=1; i<5; i++)
        if (!insert_node(&front, i))
            fprintf(stderr, "Error while inserting %d!\n", i);
    for (i=6; i<9; i++)
        if (!insert_node(&front, i))
            fprintf(stderr, "Error while inserting %d!\n", i);
    printf("List elements:\n");
    print_list(front);


    printf("\nSUMA %d \n\n",sumuj(front,0));


    remove_list(&front);
    front = NULL;
    return 0;
}
