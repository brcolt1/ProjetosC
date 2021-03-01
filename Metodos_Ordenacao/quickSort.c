#include "progs.h"

/**********************************************************************************
*As duas funcoes de particionamento retornam a posicao correta do pivot no vetor  *
*e particionam o vetor.                                                           *
*A esquerda do pivot estao os elementos menores que ele; a direita, maiores.      *
*A particao Hoare pega o elemento do meio como pivot; o Lomuto, o elemento mais a *
*direita.                                                                         *
**********************************************************************************/
int part_Hoare(int v[], int esq, int dir)
{
    extern int cont;

    int i = esq;
    int j = dir;
    int indice = (esq + dir) / 2;
    int pivot = v[indice];
    cont += 6;

    do
    {
        cont++;

        //Achar um elemento a esquerda que seja maior ou igual ao pivot
        while(v[i] < pivot)
        {
            i++;
            cont += 2;
        }

        //Achar um elemento a direita que seja menor ou igual ao pivot
        while(v[j] > pivot)
        {
            j--;
            cont += 2;
        }

        cont++;
        if(i >= j)
        {
            if(v[i] == pivot)
                return i;

            else if(v[j] == pivot)
                return j;

            cont++;
        }

        trocar(v, i, j);
        i++;
        j--;
        cont += 4;

    }while(i <= j);

    cont++;
    if(v[i] == pivot)
        return i;

    else if(v[j] == pivot)
        return j;

    return -1;
}

int part_Lomuto(int v[], int esq, int dir)
{
    extern int cont;
    extern int cTroca;
    extern int cComp;

    //Elementos a esquerda de i sao menores ou iguais ao pivot
    //Elementos a direta de j sao maiores que o pivot
    int i = esq;
    int j = esq;
    int pivot = v[dir];
    cont += 4;

    while(j != dir)
    {
        cComp++;
        if(v[j] <= pivot)
        {
            trocar(v, i, j); cTroca++;
            i++;
            cont += 2;
        }

        j++;
        cont += 4;
    }

    //Assim, o lugar apropriado para o pivot sera a posicao i
    trocar(v, i, dir);

    return i;
}

void quickSort(int v[], int esq, int dir)
{
    extern int cont;

    cont++;
    if(esq < dir)
    {
        //p eh a posicao correta do pivot
        //int p = part_Hoare(v, esq, dir);
        int p = part_Lomuto(v, esq, dir);
        quickSort(v, esq, p - 1);
        quickSort(v, p + 1, dir);
    }
}

//Exercicio de ED2
//2. Modifique o programa do quicksort de modo que, se um subvetor for pequeno, a classificacao por bolha seja usada.

void quick_bubble(int* v, int esq, int dir, int tamanhoV)
{
    extern int cont;

    cont++;
    if(esq < dir)
    {
        //Um conjunto sera considerado pequeno se representar 10% do total do vetor
        if((dir - esq) <=  0.5*tamanhoV)
            bubbleCustomizado(v, esq, dir);
        else
        {
            //p eh a posicao correta do pivot
            //int p = part_Hoare(v, esq, dir);
            int p = part_Lomuto(v, esq, dir);
            quick_bubble(v, esq, p - 1, tamanhoV);
            quick_bubble(v, p + 1, dir, tamanhoV);
        }
    }
}

void quick_insertion(int* v, int esq, int dir, int tamanhoV)
{
    extern int cont;

    cont++;
    if(esq < dir)
    {
        //Um conjunto sera considerado pequeno se representar 10% do total do vetor
        if((dir - esq) <=  0.5*tamanhoV)
            insertionCustomizado(v, esq, dir);
        else
        {
            //p eh a posicao correta do pivot
            //int p = part_Hoare(v, esq, dir);
            int p = part_Lomuto(v, esq, dir);
            quick_bubble(v, esq, p - 1, tamanhoV);
            quick_bubble(v, p + 1, dir, tamanhoV);
        }
    }
}
