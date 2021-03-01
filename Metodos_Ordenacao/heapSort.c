#include "progs.h"

void heapify(int arr[], int T, int i)
{
    extern int cont;

    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    cont += 7;

    // If left child is larger than root
    cont += 2;
    if (l < T && arr[l] > arr[largest])
    {
        largest = l;
        cont++;
    }

    // If right child is larger than largest so far
    cont += 2;
    if (r < T && arr[r] > arr[largest])
    {
        largest = r;
        cont++;
    }

    // If largest is not root
    cont++;
    if (largest != i)
    {
        trocar(arr, i, largest);

        // Recursively heapify the affected sub-tree
        heapify(arr, T, largest);
    }
}

void heapSort(int arr[], int T)
{
    extern int cont;

    // Build heap (rearrange array)
    //Faz isso no nivel anterior as folhas
    for (int i = T / 2 - 1; i >= 0; i--)
    {
        cont += 2;
        heapify(arr, T, i);
    }

    // One by one extract an element from heap
    for (int i = T - 1; i > 0; i--)
    {
        cont += 2;

        // Move current root to end
        trocar(arr, 0, i);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
