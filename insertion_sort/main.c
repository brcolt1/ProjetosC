#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 128000

void insertionSort(int A[], int n)
{
    int cont = 0;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        cont = cont + 6;

        key = A[i];
        j = i - 1;

        /* Move elements of A[0..i-1], that are
        greater than key, to one position ahead
        of their current position */

        while (j >= 0 && A[j] > key)
        {
            cont = cont + 5;

            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;

        cont = cont + 2;
    }

    printf( "\n%d\n", cont );
}

int main()
{
    int A[ N ];
    int i = 0;

    for( i = 0; i < N; i++)
        A[i] = N-i;

    insertionSort( A, N );

    return 0;
}


