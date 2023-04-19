#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definicja typu bazowego jednokierunkowej listy liniowej oraz
// podstawowych operacji wykonywanych na liœcie (patrz kod Ÿród³owy 1).
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


void perform_operation(struct sll_node *node,
    void (*operation)(struct sll_node *node))
{
    if ((NULL != node) && (NULL != operation))
    {
        operation(node);
        perform_operation(node->next, operation);
    }
}

void print_node(struct sll_node *node)
{
    printf("%d ", node->data);
}

int evaluate_operation(struct sll_node *node,
    int (*operation)(int result, struct sll_node *node))
{
    if ((NULL != node) && (NULL != operation))
        return operation(evaluate_operation(node->next, operation),
                         node);
    return 0;
}

int count_nodes(int result, struct sll_node *node)
{
    return result+1;
}

int sum_nodes(int result, struct sll_node *node)
{
    return result+node->data;
}
int nieparzyste(struct sll_node *node,
    int (*operation)(int result, struct sll_node *node))
{
    if ((NULL != node) && (NULL != operation)){
    //if((node->data%2==1)){
        return operation(nieparzyste(node->next, operation),
                         node);
   // }

    }
    return 0;
}

int parzyste(struct sll_node *node,
    int (*operation)(int result,struct sll_node *node))
{
    if ((NULL != node) && (NULL != operation))
    {
        int liczba=node->data;
        //if(liczba%2==0){
        return operation(parzyste(node->next, operation),node);
       // }
        return 0;
        //parzyste(node->next, operation);
    }
}
int main()
{
    struct sll_node *front = NULL;

    // Utworzenie listy i dodanie do niej przyk³adowych elementów
    // (patrz kod Ÿród³owy 1).
    int i;

    for (i=1; i<5; i++)
        if (!insert_node(&front, i))
            fprintf(stderr, "Error while inserting %d!\n", i);
    for (i=6; i<10; i++)
        if (!insert_node(&front, i))
            fprintf(stderr, "Error while inserting %d!\n", i);
    printf("List elements:\n");
    print_list(front);


    printf("List elements printed with higher order function:\n");
    perform_operation(front, print_node);
    printf("\n");
    printf("Number of list elements: %d\n",
           evaluate_operation(front, count_nodes));
    printf("Sum of list elements: %d\n",
           evaluate_operation(front, sum_nodes));

    printf("\nWartosci nieparzyste: \n");
    int x = nieparzyste(front, count_nodes);
    printf("%d",x);
    printf("\nWartosci parzyste: \n");
    //parzyste(front, print_node);

    remove_list(&front);
    front = NULL;
    return 0;
}
