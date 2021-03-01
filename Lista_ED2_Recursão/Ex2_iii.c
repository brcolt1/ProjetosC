#include "programas.h"

/* Soma e multplicacao de dois numeros por incrementos sucessivos. Ex 2-iii e iv -L1*/

int soma( int x, int y )
{
    if( y == 0 )
        return x;

    x++;

    return soma( x, y-1 );
}

/*
int main()
{
    int x = 0;
    int y = 0;

    printf( "x = " ); scanf( "%d", &x );
    printf( "\ny = " ); scanf( "%d", &y );
    printf( "\n%d\n", soma( x, y ) );

    return 0;
}
*/
