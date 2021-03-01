#include "progs.h"

void bubbleSort(int v[], int T)
{
    extern int cont;
    extern int cTroca;
    extern int cComp;

    int i;
    bool houve_troca = true; //Se o vetor ja estiver ordenado, nao precisa fazer nada!!
    cont++;

    while(houve_troca)
    {
        houve_troca = false; cont++;

        cont++;
        for(i = 0; i < T - 1; i++)
        {
            cont+= 5;
            cComp++;
            if(v[i] > v[i+1])
            {
                trocar(v, i, i+1);
                houve_troca = true; cont++; cTroca++;
            }
        }
        T--; cont+= 2;
    }
}

//Para o exercicio 2. de ED2
void bubbleCustomizado(int* v, int inicio, int fim)
{
    extern int cont;

    int i = 0;
    bool houve_troca = true; //Se o vetor ja estiver ordenado, nao precisa fazer nada!!
    cont+= 2;

    while(houve_troca)
    {
        houve_troca = false; cont++;

        for(i = inicio; i < fim; i++)
        {
            cont+= 3;
            if(v[i] > v[i+1])
            {
                trocar(v, i, i+1);
                houve_troca = true; cont++;
            }
        }
        fim--; cont+= 2;
    }
}
