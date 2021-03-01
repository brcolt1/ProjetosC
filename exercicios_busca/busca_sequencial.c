#include "algBusca.h"

//Algoritmo de busca sequencial com sentinela.
//O vetor de tamanho n deve ter n-1 elementos

int buscaSeqSent(int* v, int tamanhoV, int chave)
{
    v[tamanhoV - 1] = chave;

    int i;
    for(i = 0; v[i] != chave; i++); //O elemento sempre será encontrado

    if(i < tamanhoV - 1)
        return 1; //Encontrado

    return 0; // Nao encontrado
}

/*BUSCA SEQUENCIAL INDEXADA*/

void cria_indices(blocoIndices tabelaInd[], int tamInd, int v[], int N)
{
    int pos, i;

    for(i = 0; i < tamInd; i++)
    {
        pos = i * N / tamInd; //Posicao pra onde o primeiro elemento da tabela de indice "aponta" no vetor original
        tabelaInd[i].pos = pos;
        tabelaInd[i].kindex = v[pos]; //kindex guarda o numero pra onde é apontado no vetor original
    }
}

int buscaSeqIndex(int v[], int N, blocoIndices indice[], int tamInd, int chave)
{
    int i;

    //busca no indice primario
    for(i = 0; i < tamInd && indice[i].kindex <= chave; i++);

    i = indice[i-1].pos;

    //busca na tabela
    while(i < N && v[i] < chave)
        i++;

    if(i < N && v[i] == chave)
        return i;
    else
        return -1;

}
