#include "progs.h"

void countingSort(int v[], int T)
{
    int i, j, k;
    int max = v[0];

    //Achar maior elemento
    for(i = 0; i < T; i++)
        if(v[i] > max)
            max = v[i];
    max++;

    //Criando o vetor que armazena o numero de vezes que o numero aparece
    int count[max];
    for(i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    /*
    Ver quantas vezes o numero v[i] aparace em v.
    Como o indice em count[] corresponde ao numero v[i], cada
    vez que aparece v[i] no for, aumentaremos a quantidade registrada
    em count[]
    */
    for(i = 0; i < T; i++)
    {
        count[v[i]]++;
    }

    //Percorremos count[]
    for(i = 0, j = 0; j < max; j++)
    {
        //k contem quantas vezes apareceu o numero j - isto eh count[j]
        //Para o caso de termos o numero repetido, aumentamos i para avancarmos
        //em v[]
        for(k = count[j]; k > 0; k--)
        {
            v[i++] = j;
        }
    }

}

