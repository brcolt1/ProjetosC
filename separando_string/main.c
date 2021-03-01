/*************************************************************
*Fazer um programa em C que lê uma string contendo palavras  *
*separadas por um espaço em branco e as imprime uma abaixo   *
*das outras.                                                 *
*************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100] = "algo";
    char palavra[20] = "algo";
    int i = 0;
    int j = 0;

    printf("Digite uma frase:");
    fgets(frase, 100, stdin);

    printf("\n");

    //Sabemos que a frase acabou ao encontrarmos um '\0'
    while(frase[i] != '\0')
    {
        if(frase[i] != ' ' && frase[i] != '\n')
        {
            palavra[j] = frase[i];
            j++;
        }
        else
        {
            palavra[j] = '\0';
            printf("%s\n", palavra);
            j = 0;
        }

        i++;
    }

    return 0;
}
