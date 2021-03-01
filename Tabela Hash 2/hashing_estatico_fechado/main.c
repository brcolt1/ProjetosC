#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tipo_Dado
{
    int dado;
    char nome[50];
};

typedef struct Tipo_Dado TipoDado;

int valorString(char* str)
{
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++)
        valor = 31 * valor + (int)str[i];
    return (valor & 0x7FFFFFFF);
}

int chaveDivisao(int chave, int tamanhoHash)
{
    return (chave & 0x7FFFFFFF) % tamanhoHash;
}

int chaveMultiplicacao(int chave, int tamanhoHash)
{
    double A = 0.6180339887;
    double val = chave * A;
    val = val - (int) val;
    return (int) (tamanhoHash * val);
}

int chaveDobra(int chave, int tamanhoHash)
{
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (tamanhoHash - 1);
    return (parte1 ^ parte2);
}

int sondagemLinear(int pos, int i, int tamanhoHash)
{
    return ((pos + i) & 0x7FFFFFFF) % tamanhoHash;
}

int sondagemQuadratica(int pos, int i, int tamanhoHash)
{
    pos = pos + 2*i + 5*i*i; //hash + (c1 * i) + (c2 * i^2)
    return (pos & 0x7FFFFFFF) % tamanhoHash;
}

int duploHash(int H1, int chave, int i, int tamanhoHash)
{
    int H2 = chaveMultiplicacao(chave, tamanhoHash - 1) + 1;
    //Obs: poderia ter usado outra funcao de hashing para H2
    return ((H1 + i*H2) & 0x7FFFFFFF) % tamanhoHash;
}

void criaHash(TipoDado** ha, int tamanhoHash)
{
    int i;
    for(i = 0; i < tamanhoHash; i++)
        ha[i] = NULL;
}

int insereHash(TipoDado** ha, int tamanhoHash, TipoDado td)
{
    if(ha == NULL)
        return -1; //Erro grave

    int chave = td.dado;
    //int chave = valorString(td->nome);

    int i, pos, novaPos;
    pos = chaveDivisao(chave, tamanhoHash);

    for(i = 0; i < tamanhoHash; i++)
    {
        novaPos = sondagemLinear(pos, i, tamanhoHash);
        //newPos = sondagemQuadratica(pos,i,tamanhoHash);
        //newPos = duploHash(pos,chave,i,tamanhoHash);
        if(ha[novaPos] == NULL)
        {
            TipoDado* novo;
            novo = (TipoDado*)malloc(sizeof(TipoDado));
            if(novo == NULL)
                return 0;
            *novo = td;
            ha[novaPos] = novo;

            return 1;
        }
    }
    return 0; //Tabela cheia!!
}

int buscaHash(TipoDado** ha, int tamanhoHash, int info, TipoDado* td)
{
    if(ha == NULL)
        return -1;

    int i, pos, novaPos;
    pos = chaveDivisao(info, tamanhoHash);

    for(i = 0; i < tamanhoHash; i++)
    {
        novaPos = sondagemLinear(pos, i, tamanhoHash);
        //newPos = sondagemQuadratica(pos,i,tamanhoHash);
        //newPos = duploHash(pos,chave,i,tamanhoHash);
        if(ha[novaPos] == NULL)
            return 0; //Nao achou!

        if(ha[novaPos]->dado == info)
        {
            *td = *(ha[novaPos]);
            return 1; //Achou
        }
    }

    return 0; //Erro
}

void liberaHash(TipoDado** ha, int tamanhoHash)
{
    int i ;
    for(i = 0; i < tamanhoHash; i++)
    {
        if(ha[i] != NULL)
            free(ha[i]);
    }
}

void imprimeHash(TipoDado** ha, int tamanhoHash)
{
    int i;
    printf("\nA tabela hash tem a seguinte configuracao:\n");
    printf("--------------------------------\n");
    for(i = 0; i < tamanhoHash; i++)
    {
        if(ha[i] != NULL)
        {
            printf("\nPosicao %d: Dado: %d\n", i, ha[i]->dado);
        }
        else
        {
            printf("\nPosicao %d desocupada!\n", i);
        }
    }
    printf("--------------------------------\n");
}

int main()
{
    int tamanhoHash = 3;
    TipoDado** ha = (TipoDado**)malloc(tamanhoHash * sizeof(TipoDado*));
    criaHash(ha, tamanhoHash);

    TipoDado teste;
    teste.dado = 1;

    if(insereHash(ha, tamanhoHash, teste))
        printf("Valor 1 adicionado a tabela hash\n");
    else
        printf("\nTabela cheia!\n");

    imprimeHash(ha, tamanhoHash);

    teste.dado = 7;

    if(insereHash(ha, tamanhoHash, teste))
        printf("\nValor 7 adicionado a tabela hash\n");
    else
        printf("\nTabela cheia!\n");

    imprimeHash(ha, tamanhoHash);

    teste.dado = 5;

    if(insereHash(ha, tamanhoHash, teste))
        printf("\nValor 5 adicionado a tabela hash\n");
    else
        printf("\nTabela cheia!\n");

    imprimeHash(ha, tamanhoHash);

    teste.dado = 10;

    if(insereHash(ha, tamanhoHash, teste))
        printf("\nValor 1 adicionado a tabela hash\n");
    else
        printf("\nTabela cheia!\n");

    imprimeHash(ha, tamanhoHash);
    liberaHash(ha, tamanhoHash);

    return 0;
}
