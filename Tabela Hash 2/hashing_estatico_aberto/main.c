#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERRO 0
#define TABLE_SIZE 10

//HASHING ESTATICO ABERTO!

struct NO
{
    int valor;
    struct NO* prox;
};

typedef struct NO no;

void criaHash(no* tabela[])
{
    int i;

    for(i = 0; i < TABLE_SIZE; i++)
        tabela[i] = NULL;
}

void liberaHash(no* tabela[])
{
    int i;
    no* aux;

    for(i = 0; i < TABLE_SIZE; i++)
    {
        while(tabela[i] != NULL)
        {
            aux = tabela[i];
            tabela[i] = tabela[i]->prox;
            free(aux);
        }
    }
}

int chaveDivisao(int dado)
{
    return dado % TABLE_SIZE;
}

int insereDado(no* tabela[], int dado)
{
    int chave = chaveDivisao(dado);

    no* novo = (no*)malloc(sizeof(no));
        if(novo == NULL)
            return ERRO;

    novo->valor = dado;
    novo->prox = NULL;

    if(tabela[chave] == NULL)
    {
        tabela[chave] = novo;

        printf("\nSem colisao: valor %d inserido na posicao (%d,0).\n", dado, chave);

        return OK;
    }
    else
    {
       no* aux = tabela[chave];
       int i=0;

       while(aux->prox != NULL)
       {
           i++;
           aux = aux->prox;
       }

        i++;

       //Achamos o ultimo elemento. Daria para implementar a insercao na primeira posicao, o que seria melhor.
       if(aux->valor != dado)
       {
           aux->prox = novo;

           printf("\nColisao: valor %d foi inserida na posicao (%d,%d).\n", dado, chave, i);
       }
       else
       {
           printf("\nO valor ja foi inserido na tabela.\n");
       }
    }

    return OK;
}

void imprimeHash(no* tabela[])
{
    int i;
    no* aux;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("Elementos da linha %d da tabela de hash\n-----------------------------------------\n", i);
        aux = tabela[i];

        while (aux != NULL)
        {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }

        printf("\n-----------------------------------------\n\n");
    }
}
int main()
{
    //Criamos um vetor de ponteiros de no
    no* tabelaHash[TABLE_SIZE];
    criaHash(tabelaHash);

    int dado = 0;

    printf("Insira numero positivos. Se quiser terminar a operacao, insira -1.\n");

    while(1)
    {
        scanf("%d", &dado);

        if(dado != -1)
            insereDado(tabelaHash, dado);
        else
            break;
    }

    imprimeHash(tabelaHash);
    liberaHash(tabelaHash);

    return 0;
}
