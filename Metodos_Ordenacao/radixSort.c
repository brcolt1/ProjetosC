#include "progs.h"

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countingRadix(int v[], int T, int exp)
{
    int output[T]; // output array
    int i;
    int count[10] = {0}; //O tamanho 10 se deve por existirem 10 digitos

    //Contamos quantas vezes o numero (v[i] / exp) % 10 aparece
    //Sendo que {0 <= (v[i] / exp) % 10 <= 10}
    for (i = 0; i < T; i++)
        count[ (v[i] / exp) % 10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = T - 1; i >= 0; i--)
    {
        output[count[ (v[i] / exp) % 10 ] - 1] = v[i]; //Veja que tem um v[i] ali dentro
        count[ (v[i] / exp) % 10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < T; i++)
        v[i] = output[i];
}

void radixSort(int v[], int T)
{
    // Find the maximum number to know number of digits
    int max = v[0];
    for (int i = 1; i < T; i++)
        if (v[i] > max)
            max = v[i];;

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; (max / exp) > 0; exp *= 10)
        countingRadix(v, T, exp);
}
