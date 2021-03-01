#ifndef ALGBUSCA_H_INCLUDED
#define ALGBUSCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaSeqSent(int* v, int tamanhoV, int chave);
int buscaBinaria(int* v, int inicio, int fim, int chave);
int buscaBinInterp(int* v, int inicio, int fim, int chave);

//BUSCA SEQUENCIAL INDEXADA
struct BlocoIndices
{
    int pos;
    int kindex;
};

typedef struct BlocoIndices blocoIndices;

void cria_indices(blocoIndices tabelaInd[], int tamInd, int v[], int N);
int buscaSeqIndex(int v[], int N, blocoIndices indice[], int tamInd, int chave);


#endif // ALGBUSCA_H_INCLUDED
