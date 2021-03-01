/*******************************************
 *Faca um programa que leia, exiba na tela *
 *e multilpique duas matrizes 3x3.         *
 ******************************************/

#include <stdio.h>

int main()
{
    //Definindo as matrizes
    float A[3][3];
    float B[3][3];
    int i = 0;
    int j = 0;

    //Matriz A
    printf("Digite os elementos da matriz A:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("a[%d][%d] = ", (i+1), (j+1));
            scanf("%f", &A[i][j]);
            printf("\n");
        }
    }

    //Matriz B
    printf("Digite os elementos da matriz B:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("b[%d][%d] = ", (i+1), (j+1));
            scanf("%f", &B[i][j]);
            printf("\n");
        }
    }

    //Exibindo as matrizes

    //A
    printf("Matriz A:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%.1f ", A[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");

    //B
    printf("Matriz B:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%.1f ", B[i][j]);
        }

        printf("\n");
    }

    //Matriz resultante da multiplicacao: C
    float C[3][3];
    int k = 0;
    i = 0;
    j = 0;

    //Zerando elementos da matriz C
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            C[i][j] = 0;
        }
    }

    //Multiplicacao
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    printf("\n");

    //Imprimir matriz C
    printf("Multiplicando A*B:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%.1f ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}
