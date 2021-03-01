#include "progs.h"

void troca(int* v, int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void imprime(int* v, int tamVet)
{
    int i = 0;

    printf("{");
    for(i = 0; i < tamVet-1; i++)
        printf("%d, ", v[i]);
    printf("%d}", v[tamVet-1]);
    printf("\n");
}

void permutacoes(int* v, int inicio, int tamV)
{
    int i;

    for(i = inicio; i < tamV; i++)
    {
        troca(v, i, inicio);
        permutacoes(v, inicio+1, tamV); //Faço todas as permutações para o subvetor
        troca(v, i, inicio); //Backtracking
    }

    if(inicio == tamV)//Nao entrou no loop for
        imprime(v, tamV);
}
