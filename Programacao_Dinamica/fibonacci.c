#include "progs.h"

int Fib(int n)
{
    if(n <= 2)
        return 1;
    return Fib(n-1) + Fib(n-2);
}

void inicializa_memo(int* memo)
{
    int i = 0;
    for(i = 0; i < INFINITO; i++)
        memo[i] = -1;
}

int fib(int n, int* memo)
{
    if(memo[n] != -1)
        return memo[n];
    else
    {
        int fn = -1;

        if(n <= 2)
            fn = 1;

        else
            fn = fib(n-1, memo) + fib(n-2, memo);

        memo[n] = fn;

        return fn;
    }
}
