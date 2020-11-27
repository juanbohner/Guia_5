#include <stdio.h>
#include <string.h>

#define MAX_STR 15

typedef enum{
	OK,
	ERROR_NULL_POINTER		=1,
	MAX_ERRORS
}status_t;

status_t string_reverse ( char string[]);

int main(void)
{
	char str[MAX_STR] = "Hola";
	status_t st;
	st = string_reverse(str);

	switch(st)
	{
		case	OK:
		{
			break;
		}
		case ERROR_NULL_POINTER:
		{
			printf("ERROR NULL POINTER\n");
			break;
		}
		default:
			break;
	}		
	puts(str);
	return 0;
}

status_t string_reverse ( char str[])
{
	size_t i, j;
	char aux;

	if(str == NULL)
		return ERROR_NULL_POINTER;

	
	
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		aux = str[i];
        str[i] = str[j];
        str[j] = aux;
	}
	str [strlen(str)] = '\0';

	return OK;
}