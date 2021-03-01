#include "programas.h"

//Forma iterativa
int maxSubArraySumI(int v[], int size)
{
    int i = 0;
    int j = 0;
    int maior = 0;
    int maiorAux = 0;

    if(size >= 2)
    {
        for(i = 0; i < size; i++)
        {
            maiorAux = v[i];

            if(maiorAux > maior)
                maior = maiorAux;

            for(j = i + 1; j < size; j++)
            {
                maiorAux += v[j];

                if(maiorAux > maior)
                {
                    maior = maiorAux;

                }
            }
        }

        return maior;
    }

    else
        return v[0];
}

//Forma divisão e consquista

int maior(int a, int b, int c)
{
    int v[3] = {a, b, c};
    int i = 0;
    int maior = a;

    for(i = 0; i < 3; i++)
    {
        if(v[i] > maior)
            maior = v[i];
    }

    return maior;
}

int somaPassandoPeloMeio(int v[], int e, int m, int d)
{
    int soma = 0;
    int somaEsq = -2000000;
    int somaDir = -2000000;
    int i = 0;

    //Menor soma a esquerda
    for(i = m; i >= e; i--)
    {
        soma += v[i];

        if(soma > somaEsq)
            somaEsq = soma;
    }

    soma = 0;

    //Menor soma a direita
    for(i = m + 1; i <= d; i++)
    {
        soma += v[i];

        if(soma > somaDir)
            somaDir = soma;
    }

    return somaEsq + somaDir;
}

int maiorSomaSubvetor(int v[], int e, int d)
{
    if(e == d)
        return v[e];

    else
    {
        int m = (e + d) / 2;

        int maxSomaEsq = maiorSomaSubvetor(v, e, m);
        int maxSomaDir = maiorSomaSubvetor(v, m+1, d);
        int maxSomaAtraves = somaPassandoPeloMeio(v, e, m, d);

        return maior(maxSomaEsq, maxSomaDir, maxSomaAtraves);
    }
}
