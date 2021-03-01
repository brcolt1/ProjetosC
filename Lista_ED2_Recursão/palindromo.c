#include "programas.h"

/*
int main()
{
    char word[100] = "bruninhogameplay1000";
    int size = strlen(word);

    if(palindromo(word, 0, size - 1) == 0)
        printf("'%s'\nPalindromo: SIM.\n", word);
    else
        printf("'%s'\nPalindromo: NAO.\n", word);

    return 0;
}
*/

//A funcao retorna zero se a palavra for palindroma.
int palindromo(char word[], int e, int d)
{
    if(e != d && e < d)
    {
        if(word[e] != word[d])
            return 1;

        return palindromo(word, e + 1, d - 1);
    }
    else
        return 0;
}
