#ifndef PROGS_H_INCLUDED
#define PROGS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define INFINITO 1000000

int Fib(int n);
void inicializa_memo(int* memo);
int fib(int n, int* memo);

int** cria_tabela(int W, int N);
void imprime_matriz(int** m, int l, int c);
int knapsack(int W, int* p, int* b, int N);

#endif // PROGS_H_INCLUDED
