#include "programas.h"

// Exercício 6 - Lista 1

int func( int n )
{
    if( n == 0 )
        return 0;

    return ( n + func( n-1 ) );
}

int func2( int n )
{
    int i = 0;
    int num = 0;

    for( i = 0; i <= n; i++ )
        num += i;

    return num;
}

/*
int main()
{
    int i = 0;

    for( i = 0; i < 11; i++ )
        printf( "%d ", func( i ) );

    printf( "\n" );

    for( i = 0; i < 11; i++ )
        printf( "%d ", func2( i ) );

    return 0;
}
*/
