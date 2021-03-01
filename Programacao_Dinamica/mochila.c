#include "progs.h"

void imprime_matriz(int** m, int l, int c)
{
    int i, j;

    for(j = 0; j < c; j++)
    {
        printf("\n");
        for(i = 0; i < l; i++)
        {
            printf("%d ", m[i][j]);
        }
    }

    printf("\n");
}

int** cria_tabela(int W, int N)
{
    int i;

    int** tabela = (int**)malloc((N+1)*sizeof(int*));

    if(tabela == NULL)
    {
        printf("Erro na alocacao da matriz.\n");
        exit(0);
    }
    else
    {
        for(i = 0; i < (N+1); i++)
        {
            tabela[i] = (int*)malloc((W+1)*sizeof(int));
            if(tabela[i] == NULL)
            {
                printf("Erro na alocacao da matriz.\n");
                exit(0);
            }
        }
    }

    return tabela;
}

int knapsack(int W, int* p, int* b, int N)
{
    int i = 0;
    int w = 0;

    int** tabela; //tabela[elemento][peso]
    tabela = cria_tabela(W, N);

    //Preenchendo a matriz de casos
    for(i = 0; i <= W; i++)
        tabela[0][i] = 0;

    for(i = 1; i <= N; i ++)
        tabela[i][0] = 0;

    for(i = 1; i <= N; i++)
    {
        for(w = 1; w <= W; w++)
        {
            if(p[i-1] <= w) //Podemos inserir o elemento na mochila. i-1 porque no vetor os lementos tem os indices decrescidos em 1
            {
                //Achar o max
                if( (tabela[i-1][w - p[i-1]] + b[i-1]) > tabela[i-1][w]) //De fato pego o elemento
                    tabela[i][w] = tabela[i-1][w - p[i-1]] + b[i-1];
                else //Nao pego o elemento
                    tabela[i][w] = tabela[i-1][w];
            }
            else
                tabela[i][w] = tabela[i-1][w];
        }
    }

    imprime_matriz(tabela, N+1, W+1);

    //A resposta que queremos eh quando temos todos o elementos e o peso da mochila (i = N e w = W)
    return tabela[N][W];
}
