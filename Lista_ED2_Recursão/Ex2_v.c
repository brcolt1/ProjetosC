#include "programas.h"

//Gerar a soma 1+ 1/2+ 1/3+ ... + 1/N

float soma_inversa(float n)
{
    if(n == 1.0)
        return 1.0;

    return (1.0 / n + soma_inversa(n - 1));
}

/*int main()
{
    float n = 0;

    printf("N = "); scanf("%f", &n);

    printf("\n1+ 1/2+ 1/3+ ... + 1/N = %f\n", soma_inversa(n));

    return 0;
}
*/
