#include <stdio.h>

void bin(int n)
{
    if( n/2 != 0 )
        bin( n/2 );
    
    printf( "%d", n%2 );
}

int main()
{
    int n = 0;

    printf( "Digite um numero: ");
    scanf("%d", &n);

    printf( "\nO numero %d em binario vale: ", n);

    bin(n);

    printf( "\n" );

    return 0;
}