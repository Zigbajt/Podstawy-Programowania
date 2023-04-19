#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAB_MAX 20
#define RANDOM_MAX 10

#define left(i) 2*(i)
#define parent(i) (i)/2
#define right(i) 2*(i)+1


void heapify(int t[], int i, int size)
{
    int largest, l, r;
    int tmp;
    l = left(i);
    r = right(i);
    largest = i;
    if ((l <= size) && (t[l] > t[i]))
        largest = l;
    if ((r <= size) && (t[r] > t[largest]))
        largest = r;
    if (largest != i)
    {
        tmp = t[i];
        t[i] = t[largest];
        t[largest] = tmp;
        heapify(t, largest, size);
    }
}

void build_heap(int t[], int size)
{
    int i;
    for (i=size/2; i>=0; i--)
        heapify(t, i, size);
}

void heap_sort(int t[], int size)
{
    int i, tmp, s;
    build_heap(t, size);
    for (i=size; i>1; i--)
    {
        tmp = t[0];
        t[0] = t[i];
        t[i] = tmp;
        --size;
        heapify(t, 0, size);
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
    srand(time(NULL));
    int tab[TAB_MAX];
    tab_random(tab);
    print(tab);
    heap_sort(tab, TAB_MAX-1);
    print(tab);
    return 0;
}
