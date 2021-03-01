#include "progs.h"

int main()
{
    //int v[] = {1, 2, 3, 4, 5};
    //int tamV = sizeof(v) / sizeof(int);

    /*EXERCICIO 2

    int soma = somaVet(v, 0, tamVet - 1);

    printf("Vetor: {");

    imprime(v, tamVet);

    printf("\nSoma = %d\n", soma);
    */

    /*EXERCICIO 7
    permutacoes(v, 0, tamV);
    */

    /*EXERCICIO 12*/
    printf("Digite um numero: ");

    int n;
    scanf("%d", &n);
    int* v;

    v = (int*)malloc(n*sizeof(int));

    if(v == NULL)
    {
        printf("Erro na criacao do vetor!\n");
        exit(0);
    }

    particoes(v, n, 0);

    free(v);

    return 0;
}
