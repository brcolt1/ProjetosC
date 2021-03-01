#include "progs.h"

void selectionSort(int v[], int T)
{
    extern int cont;
    extern int cTroca;
    extern int cComp;

    int maior;
    int i;

    while(T > 0)
    {
        maior = T - 1;
        cont += 4;

        //Achar o maior
        for(i = 0; i < T - 1; i++)
        {
            cComp++;
            if(v[i] > v[maior])
            {
                maior = i;
                cont++;
            }
            cont += 5;
        }

        //Colocar o maior no final
        trocar(v, (T - 1), maior); //Trocar com o ultimo da lista
        cTroca++;

        T--; cont += 2;
    }
}
