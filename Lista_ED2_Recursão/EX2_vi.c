#include "programas.h"

//Calcular 2/4 + 5/5 + 10/6 + ... + (n^2+1)/(n+3)

float soma_vi(float n)
{
    if(n == 1)
        return (n * n + 1.0) / (n + 3.0);

    return((n * n + 1.0) / (n + 3.0) + soma_vi(n - 1.0));
}

/*
int main()
{
    float n = 0;

    printf("N = "); scanf("%f", &n);

    printf("\nsoma = %f\n", soma_vi(n));

    return 0;
}
*/
