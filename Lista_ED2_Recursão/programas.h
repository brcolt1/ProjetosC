#ifndef PROGRAMAS_H_INCLUDED
#define PROGRAMAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int soma( int x, int y );
int func( int n );
int func2( int n );
float soma_inversa(float n);
float soma_vi(float n);
int busca_b(int v[], int x, int baixo, int alto);
int ex_viii(int n);
int mdc(int x, int y);
int potencia(int x, int n);
void inverte_str(char str[], int e, int d);
int soma_vet(int v[], int size);
int prod_vet(int v[], int size);
int palindromo(char word[], int e, int d);
int maxSubArraySumI(int v[], int size);
int somaPassandoPeloMeio(int v[], int e, int m, int d);
int maiorSomaSubvetor(int v[], int e, int d);
int maior(int a, int b, int c);

#endif // PROGRAMAS_H_INCLUDED
