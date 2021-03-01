#include "progs.h"

void trocar(int v[], int a, int b)
{
    extern int cont;

    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;

    cont += 3;
}

void printVetor(int v[], int T)
{
    int i = 0;

    for(i = 0; i < T; i++)
        printf("%d ", v[i]);
}
