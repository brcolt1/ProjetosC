#ifndef PROGS_H_INCLUDED
#define PROGS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define INF 1000

void imprime(int* v, int sup);
void troca(int* v, int a, int b);
void permuta(int* v, int inf, int sup);

void imprime_comb(int* v, int* vb, int tam_v);
void comb(int* v, int* vb, int tam_v, int i);

void imprime_g(int* v, int tam_v);
void gera_N(int* v, int tam_v, int k);

int seguro(int** tab, int N, int lin, int col);
int** cria_Tab(int n);
void libera_Tab(int** tab, int n);
void imprime_Tab(int** tab, int n);
void N_Rainhas(int** tab, int n, int col);

void imprime_moedas(int* moedas, int tamM);
void qnt_Troco(int troco, int* moedas, int tamM);
//int qnt_Troco(int* moeda, int tamM, int troco);
int qnt_TrocoB(int* moeda, int tamM, int troco);
int* inicia_pd(int troco);
int qnt_TrocoPD(int* moeda, int tamM, int troco, int* pd);

#endif // PROGS_H_INCLUDED
