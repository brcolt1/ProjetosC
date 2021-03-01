#include "progs.h"

/*
    Escreva uma versao de um algoritmo que retorna a soma de todos os elementos de um
    vetor de inteiros usando a abordagem divisao e conquista.
*/

//v[] = {1, 2, 3, 4, 5}
//Soma  = 15

int somaVet(int* v, int inf, int sup)
{
    if(sup - inf == 0) //Ha um unico elemento no subvetor
        return v[sup];
    else
    {
        int meio = (sup + inf) / 2;
        int soma_inf = somaVet(v, inf, meio);
        int soma_sup = somaVet(v, meio + 1, sup);

        return soma_inf + soma_sup;
    }
}
