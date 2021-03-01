#include "programas.h"

/*
int main()
{
    int x = 0;
    int y = 0;

    printf("x = "); scanf("%d", &x);
    printf("\ny = "); scanf("%d", &y);

    printf("\nmdc(%d, %d) = %d\n", x, y, mdc(x, y));

    return 0;
}
*/

int mdc(int x, int y)
{
    if(x % y == 0)
        return y;
    else
        return mdc(y, x % y);
}
