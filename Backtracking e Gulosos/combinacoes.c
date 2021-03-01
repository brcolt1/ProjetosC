#include "progs.h"

/*BACKTRACKING*/

/* Dado uma quantidade de elementos, vamos encontrar
   todos os conjuntos possiveis de se formar com esses
   elementos.

   Logica: testamos todas as combinacoes em que o elemento
   esta presente (verdadeiro) e todos que o elemento nao esta
   presente (falso). Fazemos isso para todos os elementos de
   forma recursiva.
*/

void imprime_comb(int* v, int* vb, int tam_v)
{
    int i = 0;

    for(i = 0; i < tam_v; i++)
    {
        if(vb[i] == 1)
            printf("%d ", v[i]);
    }

    printf("\n");
}

void comb(int* v, int* vb, int tam_v, int i)
{
    if(i == tam_v)
        imprime_comb(v, vb, tam_v);
    else
    {
        vb[i] = 1;
        comb(v, vb, tam_v, i+1);
        vb[i] = 0;
        comb(v, vb, tam_v, i+1);
    }
}
