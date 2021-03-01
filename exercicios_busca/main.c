#include <stdio.h>
#include <stdlib.h>
#include "algBusca.h"

int main()
{
    /* BUSCA SEQUENCIAL
    int v[5] = {1, 2, 3, 4, 5};
    int chave = 6;

    if(buscaSeqSent(v, 5, chave))
        printf("Valor encontrado!\n");
    else
        printf("Valor nao encontrado!\n");
    */

    /*BUSCA BINARIA
    int v[9] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
    int chave = 10;

    //int indice = buscaBinaria(v, 0, 9-1, chave);
    int indice = buscaBinInterp(v, 0, 9-1, chave);

    if(indice > -1)
        printf("Elemento %d encontrado: posicao %d!\n", v[indice], indice);
    else
        printf("Elemento %d nao encontrado!\n", chave);
    */

    /* BUSCA SEQUENCIAL INDEXADA */

    //Vamos considerar que estamos trabalhando com inteiros
    //Elementos devem estar ordenados!

    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    blocoIndices indices[2];
    cria_indices(indices, 2, v, 10);

    int x = buscaSeqIndex(v, 10, indices, 2, 5);

    if(x != -1)
        printf("%d\n", v[x]);

    return 0;
}
