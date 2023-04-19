#include <stdio.h>
#include <stdlib.h>
struct sll_node
{
    char data;
    struct sll_node *next;
};

struct sll_node *create_list(char data)
{
    struct sll_node *front = (struct sll_node *)
        malloc(sizeof(struct sll_node));
    if (NULL != front)
    {
        front->data = data;
        front->next = NULL;
    }
    return front;
}

struct sll_node *insert_front(struct sll_node *front,
                              struct sll_node *new_node)
{
    new_node->next = front;
    return new_node;
}
struct sll_node *insert_node(struct sll_node *front, char data)
{
    struct sll_node *new_node = (struct sll_node *)
        malloc(sizeof(struct sll_node));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
        return insert_front(front, new_node);

    }
}
void insert_back(struct sll_node *back, struct sll_node *new_node)
{
    back->next = new_node;
}
struct sll_node *find_spot(struct sll_node *front, char data)
{
    struct sll_node *prev = NULL;
    while (NULL != front)
    {
        prev = front;
        front = front->next;
    }
    return prev;
}
struct sll_node *insert_nn(struct sll_node *front, char data)
{
    struct sll_node *new_node = (struct sll_node *)
        malloc(sizeof(struct sll_node));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
        struct sll_node *node = find_spot(front, data);
        insert_back(node, new_node);
    }
    return front;
}

void delete_after(struct sll_node *node)
{
    struct sll_node *next = node->next;
    if (NULL != next)
    {
        node->next = next->next;
        free(next);
    }
}

void print_list(struct sll_node *front)
{
    for (; NULL != front; front = front->next)
        printf("%c ", front->data);
    printf("\n");
}
void sprawdz(struct sll_node *front,struct sll_node *front_tyl)
{
    int zmienna=-1;
    for (; NULL != front; front = front->next){

        if(front->data==front_tyl->data){
            zmienna=1;
        }else{
            zmienna=0;
            break;
        }
        front_tyl=front_tyl->next;
    }
    if(zmienna==1){
    printf("Slowo jest palindrom");
    }
    if(zmienna==0){
    printf("Slowo NIE jest palindrom");
    }
}

void remove_list(struct sll_node **front)
{
    while (NULL != *front)
    {
        struct sll_node *next = (*front)->next;
        free(*front);
        *front = next;
    }
}

int main()
{
    struct sll_node *front_tyl = NULL;
    struct sll_node *front = NULL;
/*
    front_tyl = insert_node(front_tyl, 'A');
    front = insert_nn(front,'A');
    front_tyl = insert_node(front_tyl, 'J');
    front = insert_nn(front,'J');
    front_tyl = insert_node(front_tyl, 'A');
    front = insert_nn(front,'A');
    front_tyl = insert_node(front_tyl, 'K');
    front = insert_nn(front,'K');
    printf("List elements after insertion of 0:\n");
    print_list(front_tyl);
    printf("List elements after insertion of 0:\n");
    print_list(front);
    sprawdz(front,front_tyl);
*/
    int ilosc;
    char litera;
    printf("Podaj ilosc liter:\n");
    scanf("%d",&ilosc);
    for(int i=1;i<=ilosc;i++){
        printf("Podaj %d Litere:\n",i);
        scanf(" %c",&litera);
        if(i==1){
            front_tyl = create_list(litera);
            front = create_list(litera);
        }else{
            front_tyl = insert_node(front_tyl, litera);
            front = insert_nn(front,litera);
        }
    }
    printf("Lista elementow:\n");
    print_list(front);
    printf("Lista elementow od tylu:\n");
    print_list(front_tyl);
    sprawdz(front,front_tyl);


    remove_list(&front_tyl);
    return 0;
}
