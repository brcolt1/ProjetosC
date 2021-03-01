#include "progs.h"

int cont = 0;
int cTroca = 0;
int cComp = 0;

int main()
{
    //int v[] = {1, 2, 3, 4, 5, 6, 9, 20, 22, 23, 28, 32, 34, 39, 40, 42, 76, 87, 99, 112};
    //int v[] = {74, 69, 64, 63, 51, 50, 49, 42, 41, 34, 32, 29, 28, 22, 16, 8, 6, 5, 3, 1};
    //int v[] = {7, 7, 7, 7, 7, 1, 1, 9, 9, 0, 4, 4, 4, 5, 4, 5, 7, 1};
    //int v[] = {6, 2, 7, 6, 4};
    //int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int v[] = {1,1,1,1,1,1,1,1,1,1,1};
    /*
    int v[500];
    int i;
    for(i = 0; i < 500; i++)
        v[i] = rand()%1000;
    */
    //Tamanho do vetor
    int T = sizeof(v) / sizeof(int);

    printf("Vetor original:\n");
    printVetor(v, T);

    //bubbleSort(v, T);
    //mergeSort(v, 0, T - 1);
    //quickSort(v, 0, T - 1);
    //selectionSort(v, T);
    //heapSort(v, T);
    insertionSort(v, T);
    //shellSort(v, T);
    //countingSort(v, T);
    //radixSort(v, T);
    //bubbleCustomizado(v, 0, T-1);
    //insertionCustomizado(v, 0, T - 1);
    //quick_bubble(v, 0, T - 1, T);
    //quick_insertion(v, 0, T - 1, T);


    printf("\nVetor ordenado:\n");
    printVetor(v, T);

    printf("\ncont = %d\ncComp = %d\ncTroca = %d", cont, cComp, cTroca);

    return 0;
}

