#include "progs.h"

/*BACKTRACKING*/

/* Este algoritmo gera todas as possiveis permutacoes de elementos
   de um dado vetor
*/

void imprime(int* v, int sup)
{
    int i = 0;
    for(i = 0; i <= sup; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

//Damos os indices dos elementos que devem ser trocados
void troca(int* v, int a, int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void permuta(int* v, int inf, int sup)
{
    if(inf == sup)
        imprime(v, sup);
    else
    {
        int i = 0;
        for(i = inf; i <= sup; i++)
        {
            troca(v, inf, i);
            permuta(v, inf + 1, sup);
            troca(v, inf , i); //backtracking
        }
    }
}
