#include "programas.h"

int busca_b(int v[], int x, int baixo, int alto)
{
    if(baixo > alto)
        return -1;

    int meio = (baixo + alto) / 2;

    return (x == v[meio]) ? meio : x < v[meio] ? busca_b(v, x, baixo, meio - 1) : busca_b(v, x, meio + 1, alto);
}
