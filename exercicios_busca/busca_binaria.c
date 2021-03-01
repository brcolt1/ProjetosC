#include "algBusca.h"

//A funcao retorna a posicao do elemento no vetor
int buscaBinaria(int* v, int inicio, int fim, int chave)
{
    int meio = (inicio + fim) / 2;

    printf("%d\n", meio);

    if(inicio <= fim)
    {
        if(v[meio] == chave)
            return meio;

        else if(chave < v[meio])
            return buscaBinaria(v, inicio, meio-1, chave);

        else if(chave > v[meio])
            return buscaBinaria(v, meio+1, fim, chave);
    }

    return -1;
}

int buscaBinInterp(int* v, int inicio, int fim, int chave)
{
    int meio = inicio + ((fim - inicio) * (chave - v[inicio]))/(v[fim] - v[inicio]);

    printf("%d\n", meio);

    if(inicio <= fim)
    {
        if(v[meio] == chave)
            return meio;

        else if(chave < v[meio])
            return buscaBinaria(v, inicio, meio-1, chave);

        else if(chave > v[meio])
            return buscaBinaria(v, meio+1, fim, chave);
    }

    return -1;
}
