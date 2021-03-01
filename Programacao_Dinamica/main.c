#include "progs.h"

int main()
{
    /* FIBONACCI

    int memo[INFINITO];
    inicializa_memo(memo);

    int n = 45;

    //printf("%d\n", Fib(n));
    printf("%d\n", fib(n, memo));
    */

    /* PROBLEMA DA MOCHILHA */

    //Peso maximo que a mochila carrega
    int W = 10;

    //Numero de elementos disponiveis
    int N = 3;

    //Vetor com os valores (beneficios) de cada elemento
    int b[] = {8, 5, 6};

    //Vetor com pesos de cada elemento
    int p[] = {5, 6, 2};

    int max = knapsack(W, p, b, N);

    printf("\nO maior benficio possivel eh: %d\n", max);

    return 0;
}
