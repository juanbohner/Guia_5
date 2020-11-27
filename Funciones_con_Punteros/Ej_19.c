#include <stdio.h>

#define MAX_STR 15

typedef enum{
	TRUE,
	FALSE
}bool_t;

bool_t is_empty_string (const char *string);

int main(void)
{
	const char str[MAX_STR] = "Hola";
	bool_t estado;
	estado = is_empty_string(str);

	switch(estado)
	{
		case TRUE:
		{
			printf("La cadena NO esta vacia\n");
			break;
		}
		case FALSE:
		{
			printf("La cadena esta vacia\n");
			break;
		}
	}		
	return 0;
}

bool_t is_empty_string (const char *string)
{
	if ( *string == '\0')
		return FALSE;
	else
		return TRUE;
}