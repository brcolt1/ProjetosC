#include <stdio.h>
#include <stdlib.h>
#include "programas.h"

int main()
{
    int v[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(v) / sizeof(int);

    int somaMax = maiorSomaSubvetor(v, 0, size - 1);

    printf("Soma maxima = %d\n", somaMax);

    return 0;
}
