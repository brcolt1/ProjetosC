#include <stdio.h>

int ackerman( int m, int n )
{
    if(m == 0)
        return ( n+1 );

    if(m != 0 && n == 0)
        return ackerman(m-1, 1);

    else
        return ackerman( m-1, ackerman( m, n-1 ) );
}


int main()
{
    int m = 0;
    int n = 0;

    for( m = 0; m < 4; m++ )
    {
        for ( n = 0; n < 5; n++ )
        {
            printf( "%d ", ackerman( m, n ) );
        }
    }

    printf( "\n" );

    return 0;
}
