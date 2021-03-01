#include "progs.h"

/*
    Desenvolva um metodo recursivo (e programe-o) para calcular o numero de diferentes
    modos nos quais um inteiro n pode ser escrito como uma soma, sendo cada um dos
    operandos menor que n.

    Resumo: Encontre todas as particoes de um numero.
*/

void particoes(int* v, int n, int fim)
{
    //O numero maximo de digitos necessarios para escrever uma particao de n
    //sao n digitos (caso do 1+1+1+...+1 = n)

    //O vetor vai de 0,...,n-1

    int i;

    if(n == 0)
        imprime(v, fim);
    else
    {
        for(i = 1; i <= n; i++)
        {
            v[fim] = i;
            particoes(v, n-i, fim+1);
        }
    }
}

