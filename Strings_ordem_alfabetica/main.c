/*****************************************************
 *  Ler 2 palavras e coloca-las em ordem alfabética. *
 ****************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char p1[20] = ""; //Guardara a palavra original
    char p2[20] = "";
    char p1Aux[20] = ""; //Guardara a palavra modificada
    char p2Aux[20] = "";
    int i = 0;

    printf("Digite a primeira palavra: ");
    scanf("%s", p1);

    printf("Digite a segunda palavra: ");
    scanf("%s", p2);

    //Copiando as strings
    strcpy(p1Aux, p1);
    strcpy(p2Aux, p2);

    //E interessante transformar todas as letras em minusculas
    //P1
    while(p1Aux[i] != '\0')
    {
        p1Aux[i] = tolower(p1Aux[i]);
        i++;
    }

    i = 0;

    //P2
    while(p2Aux[i] != '\0')
    {
        p2Aux[i] = tolower(p2Aux[i]);
        i++;
    }

    int comparador = strcmp(p1Aux, p2Aux);

    if(comparador == 0)
        printf("Palavras iguais\n");
    else if(comparador < 0)
        printf("\nOrdem alfabetica: %s, %s\n", p1, p2);
    else //comparador > 0
        printf("\nOrdem alfabetica: %s, %s\n", p2, p1);

    return 0;
}
