#include <stdio.h>
#include <string.h>

int main()
{
	char carac = 'b';
	
	switch(carac)
	{
		case 'b':
		printf("b\n");
		break;

		case 'a':
		printf("acertou\n");
		break;

		default:
		printf("ERRO\n");
		
	}
	
	
	return 0;
}
