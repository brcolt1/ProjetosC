#include "programas.h"

/*
int main()
{
    int v[] = {-1 , 1, 1, 1, 1};
    int size = sizeof(v) / sizeof(int);
    int i = 0;

    printf("Vetor: ");
    for(i = 0; i < size; i++)
        printf("%d ", v[i]);

    printf("\n");

    printf("Soma = %d Produto = %d\n", soma_vet(v, size), prod_vet(v, size));

    return 0;
}
*/

int soma_vet(int v[], int size)
{
    if(size == 0)
        return 0;

    return v[size - 1] + soma_vet(v, size - 1);

}

int prod_vet(int v[], int size)
{
    if(size == 0)
        return 1;

    return v[size - 1] * prod_vet(v, size - 1);
}
