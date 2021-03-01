#include "progs.h"

/*BACKTRACKING*/

/* O programa gera todos os possiveis números de N digitos.
*/

void imprime_g(int* v, int tam_v)
{
    int i = 0;

    for(i = 0; i < tam_v; i++)
        printf("%d", v[i]);
    printf("\n");
}

void gera_N(int* v, int tam_v, int k)
{
    if(k == tam_v)
        imprime_g(v, tam_v);
    else
    {
        int i = 0;
        for(i = 0; i <= 9; i++)
        {
            v[k] = i;
            gera_N(v, tam_v, k+1);
        }
    }
}
