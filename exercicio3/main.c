#include <stdio.h>
#include <stdlib.h>

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

int maiorSomaVetor(int v[], int e, int d)
{
    if(d - e == 0) //Só um elemento no vetor
        return v[e];
    else
    {
        int soma = 0;
        int maiorSoma = 0;

        for(int i = e; i<=d; i++)
        {
            soma += v[i];
            if(soma > maiorSoma)
                maiorSoma = soma;
        }

        int somaSubDir = maiorSomaVetor(v, e+1, d); //Esse subvetor é o vetor avançando pela esquerda
        int somaSubEsq = maiorSomaVetor(v, e, d-1); //Esse subvetor é o vetor recuando pela direita

        return maior(maiorSoma, somaSubDir, somaSubEsq);
    }
}

int main()
{
    int v[] = {1, -1, 4, -5, 5};
    int size = sizeof(v) / sizeof(int);

    int somaMax = maiorSomaVetor(v, 0, size - 1);

    printf("Soma maxima = %d\n", somaMax);

    return 0;
}

