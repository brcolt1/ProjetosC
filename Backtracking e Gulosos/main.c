#include "progs.h"

int cont = 0;
int qnt = 0;

int main()
{
    /* PERMUTACOES
    int v[] = {1, 2, 3};
    int tam_vet = sizeof(v) / sizeof(int);

    permuta(v, 0, tam_vet - 1);
    */

    /*COMBINACOES
    int v[] = {1, 2, 3, 4, 5};
    int vb[] = {0, 0, 0, 0, 0}; //Inicialmente todos falsos
    int tam_v = sizeof(v) / sizeof(int);

    comb(v, vb, tam_v, 0);
    */

    /*GERADOR DE NUMEROS DE N DIGITOS
    int v[4];
    gera_N(v, 4, 0);
    */

    /*N-RAINHAS*/

    int n = 8;
    int** tab = cria_Tab(n);

    N_Rainhas(tab, n, 0);

    libera_Tab(tab, n);

    printf("\n\nTotal de solucoes: %d\n", cont);


    /*PROBLEMA DO TROCO MINIMO

    int moedas[] = {1, 4, 6};
    int tamM = sizeof(moedas) / sizeof(int);
    int troco = 8;

    //GULOSO
    qnt_Troco(troco, moedas, tamM);

    printf("Moedas disponiveis: ");
    imprime_moedas(moedas, tamM);

    printf("\nGuloso:\nNumero minimo para um troco de RS %d,00: %d moedas\n", troco, qnt);

    //BACKTRACKING
    int backtracking = qnt_TrocoB(moedas, tamM, troco);

    printf("\nBacktracking:\nNumero minimo para um troco de RS %d,00: %d moedas\n", troco, backtracking);

    //BACKTRACKING + PROGRAMACAO DINAMICA
    int* pd = inicia_pd(troco);

    int resp_pd = qnt_TrocoPD(moedas, tamM, troco, pd);

    printf("\nBacktracking + PD:\nNumero minimo para um troco de RS %d,00: %d moedas\n", troco, resp_pd);

    free(pd);

    */
    return 0;
}

