#include "progs.h"

void Merge(int v[], int e, int m, int d)
{
    extern int cont;

    //Vamos criar dois vetores auxiliares
    int sizeE = (m - e + 1);
    int sizeD = (d - m);
    cont += 5;

    int* E = (int*)malloc(sizeE * sizeof(int));
    int* D = (int*)malloc(sizeD * sizeof(int));

    int i = 0;
    cont += 3;

    for(i = 0; i < sizeE; i++)
    {
        E[i] = v[e + i];
        cont += 4;
    }

    for(i = 0; i < sizeD; i++)
    {
        D[i] = v[m + i + 1];
        cont += 5;
    }

    //Como os vetores E e L estao ordenados, podemos comparar seus menores
    //elementos para, entao, muda-los no vetor original.
    //Vamos achar o menor de todos, dai o segundo menor etc.

    i = 0; //Indice auxiliar para E[]
    int j = 0; //Indice auxiliar para D[]
    int k = e; //Indice auxiliar para v[]
    cont += 3;

    while(i < sizeE && j < sizeD)
    {
        cont += 3;

        if(E[i] <= D[j])
        {
            v[k] = E[i];
            i++;
            cont += 3;
        }
        else
        {
            v[k] = D[j];
            j++;
            cont += 3;
        }
        k++; cont += 2;
    }

    //Sempre vai sobrar algum elemento no vetor que contém
    //os maiores valores.

    while(i < sizeE)
    {
        v[k] = E[i];
        i++;
        k++;
        cont += 6;
    }

    while(j < sizeD)
    {
        v[k] = D[j];
        j++;
        k++;
        cont += 6;
    }
}

void mergeSort(int v[], int e, int d)
{
    extern int cont;

    //Pra se der algum erro ou se o vetor for unitario
    if(e < d)
    {
        int m = (d + e) / 2;
        cont += 4;

        //Ramo da esquerda
        mergeSort(v, e, m);

        //Ramo da direita
        mergeSort(v, m + 1, d);

        //Unimos os ramos
        Merge(v, e, m, d);
    }
}
