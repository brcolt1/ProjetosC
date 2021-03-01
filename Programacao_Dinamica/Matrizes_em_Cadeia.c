#include "progs.h"

int custo_matriz(int** m, int* b)
{
    int i;
    int k; //Tamanho da subsequencia
    int j;
    int l;
    int custo;

    //Inicializar a matriz de custos
    for(i = 1; i <= n; i++)
        m[i][i] = 0;

    for(k = 2; k <= n; k++)
    {
        for(i = 1; i <= n-1; i++)
        {
            j = i + 1;
            m[i][j] = INFINITO;
            for(l = i+1; l <= j-1; l++)
            {
                custo = m[i][k] + m[k][j] + mimjmk;
                if(m[i][j] > custo)
                    m[i][j] = custo;
            }
        }
    }

    return m[1][n];
}
