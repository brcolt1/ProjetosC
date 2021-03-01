#ifndef PROGS_H_INCLUDED
#define PROGS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printVetor(int v[], int T);
void trocar(int v[], int a, int b);
void bubbleSort(int v[], int T);
void Merge(int v[], int e, int m, int d);
void mergeSort(int v[], int e, int d);
void quickSort(int v[], int esq, int dir);
int part_Hoare(int v[], int esq, int dir);
int part_Lomuto(int v[], int esq, int dir);
void selectionSort(int v[], int T);
void heapSort(int arr[], int T);
void heapify(int arr[], int T, int i);
void insertionSort(int v[], int T);
void shellSort(int v[], int T);
void countingSort(int v[], int T);
void countingRadix(int v[], int T, int exp);
void radixSort(int v[], int T);

void bubbleCustomizado(int* v, int inicio, int fim);
void quick_bubble(int* v, int esq, int dir, int tamanhoV);

void insertionCustomizado(int v[], int esq, int dir);
void quick_insertion(int* v, int esq, int dir, int tamanhoV);

#endif // PROGS_H_INCLUDED
