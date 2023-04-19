#include <stdio.h>
#include <stdlib.h>
struct stack{
    char arg[1];
    struct stack *next;
};
struct stack *push(struct stack *top, char *znak){
    struct stack *new_stack=NULL;
    new_stack=(struct stack*)malloc(sizeof(struct stack));
    if(new_stack==NULL){
        printf("Blad przydzialu pamieci\n");
        return top;
    }
    strncpy(new_stack->arg,znak,1);
    new_stack->next=top;
    return new_stack;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
