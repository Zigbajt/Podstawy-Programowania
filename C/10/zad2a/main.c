#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define TAB_MAX 20
#define RANDOM_MAX 10




int partition(int T[], int p, int r)
{
    int tmp, x, i, j;
    x = T[p];
    i = p-1;
    j = r+1;
    while (i < j)
    {
        do
        {
            --j;
        }
        while (!(T[j] <= x));
        do
        {
            ++i;
        }
        while (!(T[i] >= x));
        if (i < j)
        {
            tmp = T[i];
            T[i] = T[j];
            T[j] = tmp;
        }
    }
    return j;
}
int partition_n(int T[], int p, int r)
{
    int tmp, x, i, j;
    x = T[p];
    i = p-1;
    j = r+1;
    while (i < j)
    {
        do
        {
            --j;
        }
        while (!(T[j] >= x));
        do
        {
            ++i;
        }
        while (!(T[i] <= x));
        if (i < j)
        {
            tmp = T[i];
            T[i] = T[j];
            T[j] = tmp;
        }
    }
    return j;
}
void quicksort(int T[], int p, int r,bool rosnaco)
{
    int q;
    if(rosnaco==true){
    if (p < r)
    {
        q = partition(T, p, r);
        quicksort(T, p, q,rosnaco);
        quicksort(T, q+1, r,rosnaco);
    }
    }else{
    if (p < r)
    {
        q = partition_n(T, p, r);
        quicksort(T, p, q,rosnaco);
        quicksort(T, q+1, r,rosnaco);
    }
    }
}


void print(int T[])
{
    int i;
    printf("\n[");
    for (i=0; i<TAB_MAX; i++)
        printf("%d ", T[i]);
    printf("]\n\n");
}

void tab_random(int T[])
{
    int i;
    for (i=0; i<TAB_MAX; i++)
        T[i] = rand()%RANDOM_MAX;
}

int main()
{
    int i, tab[TAB_MAX];
    srand(time(NULL));
    print(tab);
    tab_random(tab);
    print(tab);
    quicksort(tab, 0, TAB_MAX-1,true);
    print(tab);
    quicksort(tab, 0, TAB_MAX-1,false);
    print(tab);
    return 0;
}
