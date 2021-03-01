#include "progs.h"

void shellSort(int v[], int T)
{
    extern int cont;

    int i = 0;
    int j = 0;
    int temp = 0;
    int h = 1;
    cont += 4;

    //Determinando um valor inicial para h
    while(h < T - 1)
    {
        h = 3 * h + 1; //ou h = 2 * h + 1
        cont += 5;
    }

    while (h > 0)
    {
        cont++;
        for(i = h; i < T; i++)
        {
            temp = v[i];
            j = i;
            cont += 4;

            while (j >= h && temp <= v[j - h])
            {
                v[j] = v[j - h];
                j = j - h;
                cont += 7;
            }
            v[j] = temp; cont++;
        }

        h = (h - 1) / 3; //isso vem do inverso de h = 3*h+1;
                         //ou h = (h - 1) / 2
        cont += 3;
    }
}
