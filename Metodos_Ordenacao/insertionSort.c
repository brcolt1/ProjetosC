#include "progs.h"

void insertionSort(int v[], int T)
{
    extern int cont;
    extern int cTroca;
    extern int cComp;

    int i, j, novo;

    cont++;
    for(i = 1; i < T; i++)
    {
        cont += 3;

        novo = v[i];

        cont++;
        cComp++;
        for(j = i - 1; (novo < v[j] && j >= 0); j--)
        {
            cComp++;
            cont += 4;
            trocar(v, j, j + 1); cTroca++;
        }
    }
}

void insertionCustomizado(int v[], int esq, int dir)
{
    extern int cont;
    extern int cTroca;
    extern int cComp;

    int i, j, novo;

    cont++;
    for(i = esq; i <= dir; i++)
    {
        cont += 3;

        novo = v[i];

        cont++;
        cComp++;
        for(j = i - 1; (novo < v[j] && j >= 0); j--)
        {
            cComp++;
            cont += 4;
            trocar(v, j, j + 1); cTroca++;
        }
    }
}
