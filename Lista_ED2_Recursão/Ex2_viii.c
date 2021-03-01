#include "programas.h"

int ex_viii(int n)
{
    if(n == 1)
        return 1;

    if(n == 2)
        return 2;

    return ( 2 * ex_viii(n - 1) + 3 * ex_viii(n - 2) );
}
