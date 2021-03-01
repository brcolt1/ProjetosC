#include "programas.h"

/*
int main()
{
    char str[] = "anotaram a data da maratona";
    int size = strlen(str);

    printf("String original: %s\n", str);

    inverte_str(str, 0, size - 1);

    printf("String invertida: %s\n", str);

    return 0;
}
*/

void inverte_str(char str[], int e, int d)
{
    if(e < d)
    {
        char aux = str[e];
        str[e] = str[d];
        str[d] = aux;

        inverte_str(str, e + 1, d - 1);
    }
}
