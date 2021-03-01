#include "progs.h"
#define TRUE 1
#define FALSE 0

/*BACKTRACKING*/
extern int cont;

//Funcao diz se podemos inserir uma rainha em dada posicao
int seguro(int** tab, int N, int lin, int col)
{
    int i;
    int j;

    //Verificando a linha
    for(i = 0; i < N; i++)
    {
        if(tab[lin][i] == 1)
            return FALSE;
    }

    //Verificando coluna
    for(i = 0; i < N; i++)
    {
        if(tab[i][col] == 1)
            return FALSE;
    }

    //Diagonal principal
    //Acima
    for(i = lin, j = col; i >= 0 && j>= 0; i--, j--)
    {
        if(tab[i][j] == 1)
            return FALSE;
    }
    //Abaixo
    for(i = lin, j = col; i < N && j < N; i++, j++)
    {
        if(tab[i][j] == 1)
            return FALSE;
    }

    //Diagonal secundaria
    //Acima
    for(i = lin, j = col; i >= 0 && j < N; i--, j++)
    {
        if(tab[i][j] == 1)
            return FALSE;
    }
    //Abaixo
    for(i = lin, j = col; i < N && j >= 0; i++, j--)
    {
        if(tab[i][j] == 1)
            return FALSE;
    }

    return TRUE;
}

int** cria_Tab(int n)
{
    int** tab = (int**)malloc(n*sizeof(int*));

    if(tab == NULL)
    {
        printf("Erro na criacao da tabela!\n");
        exit(0);
    }

    int i;
    int j;

    for(i =0; i < n; i++)
    {
        tab[i] = (int*)malloc(n*sizeof(int));

        if(tab[i] == NULL)
        {
            printf("Erro na criacao da tabela!\n");
            exit(0);
        }
        else //Preenche com zero
        {
            for(j = 0; j < n; j++)
                tab[i][j] = 0;
        }
    }

    return tab;
}

void libera_Tab(int** tab, int n)
{
    int i;
    for(i = 0; i < n; i++)
        free(tab[i]);
    free(tab);
}

void imprime_Tab(int** tab, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        printf("\n");
        for(j = 0; j < n; j++)
        {
            if(tab[i][j] == 1)
                printf("1 ");
            else
                printf("0 ");
        }
    }

    printf("\n\n");
}

void N_Rainhas(int** tab, int n, int col)
{
    if(n == col)//Lembrando que a matriz vai de 0 a N-1
    {
        cont++;
        printf("Solucao #%d: \n\n", cont);
        imprime_Tab(tab, n);
    }
    else
    {
        int i;

        //Testar todas as posicoes
        for(i = 0; i < n; i++)
        {
            if(seguro(tab, n, i, col))
            {
                tab[i][col] = 1;
                N_Rainhas(tab, n, col+1);
                tab[i][col] = 0; //Backtracking
            }
        }
    }
}
