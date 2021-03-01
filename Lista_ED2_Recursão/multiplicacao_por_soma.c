#include <stdio.h>

int multiplica( int x, int y )
{   
    if(y > x)
    {
        int aux = y;
        y = x;
        x = aux;
    }

    if( y == 0 )
        return 0;
    
    return ( x + multiplica( x, y-1 ) );
}

int main()
{   
    int x = 0;
    int y = 0;

    printf( "x = " ); scanf( "%d", &x );
    printf( "y = " ); scanf( "%d", &y );

    printf( "\nxy = %d\n", multiplica(x, y)); 
    
    return 0;
}