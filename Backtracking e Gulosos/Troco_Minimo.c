#include "progs.h"

/*ALGORITMO GULOSO!!!*/

//A funcoa retorna o numero minimo de moedas para retorna um troco.
//Coloquei as moedas disponiveis em um vetor moeda[] de tamanho tamM
//moeda[1, 2, 5, 10, 20]

void imprime_moedas(int* moedas, int tamM)
{
    int i = 0;

    printf("[");
    for(i = 0; i < tamM-1; i++)
        printf("%d,", moedas[i]);
    printf("%d]\n", moedas[tamM-1]);
}

extern int qnt;

void qnt_Troco(int troco, int* moedas, int tamM)
{
    if(troco == 0)
        return;

    if(tamM == -1)
    {
        qnt = 0;
        printf("Nao foi possivel devolver o troco");
        return;
    }

    if(troco - moedas[tamM-1] >= 0)
    {
        qnt++;
        qnt_Troco(troco - moedas[tamM-1], moedas, tamM);
    }
    else
    {
        qnt_Troco(troco, moedas, tamM-1);
    }
}

/*IMPLEMENTACAO ALTERNATIVA DO METODO GULOSO

int qnt_Troco(int* moeda, int tamM, int troco)
{
    int i;
    int aux;
    int qnt = 0;

    for(i = tamM-1; i >=0; i--)
    {
        //Quantidade de vezes que uma moeda pode contribuir com o troco
        aux = troco / moeda[i];
        troco -= aux * moeda[i];
        qnt += aux;
    }

    return qnt;
}
*/

/*BACKTRACKING*/

int qnt_TrocoB(int* moeda, int tamM, int troco)
{
    int min_moedas = INF;
    int i;

    if(troco == 0)
        return 0;

    int compara;

    for(i = 0; i < tamM; i++)
    {
        if(troco >= moeda[i])
        {
            compara = 1 + qnt_TrocoB(moeda, tamM, troco - moeda[i]);

            if(min_moedas > compara)
                min_moedas = compara;
        }
    }

    return min_moedas;
}

//IMPLEMENTANDO COM PD

int* inicia_pd(int troco)
{
    int* pd = (int*)malloc((troco+1)*sizeof(int));

    int i;

    pd[0] = 0;

    for(i = 1; i <= troco; i++)
    {
        pd[i] = -1;
    }

    return pd;
}

int qnt_TrocoPD(int* moeda, int tamM, int troco, int* pd)
{
    int min_moedas = INF;
    int i;

    if(pd[troco] != -1) //Aqui ja inclui 0 na posicao 0
        return pd[troco];

    int compara;

    for(i = 0; i < tamM; i++)
    {
        if(troco >= moeda[i])
        {
            compara = 1 + qnt_TrocoB(moeda, tamM, troco - moeda[i]);

            if(min_moedas > compara)
                min_moedas = compara;
        }
    }

    pd[troco] = min_moedas;

    return min_moedas;
}


