#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ARR_LENGTH 15

typedef enum{
	OK,
	ERROR_NULL_POINTER,
	MAX_ERROR
} status_t;

/*Otener un arreglo aleatorio*/
status_t arreglo_aleatorio(float arr[], size_t n);

/*Impresion de un arreglo*/
status_t impresion_arreglo(float arr[], size_t n);

int main(void)
{
	float random_arr[MAX_ARR_LENGTH];

	arreglo_aleatorio(random_arr, MAX_ARR_LENGTH);
	
	impresion_arreglo (random_arr, MAX_ARR_LENGTH);

	return 0;
	
}

status_t arreglo_aleatorio(float v[], size_t n)
{
	size_t i;

	if(v == NULL)
        return ERROR_NULL_POINTER;


	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		v[i] = (rand() % 2);
		/*Obtiene numeros double  0.000000 hasta el 1.000000. Si el numero random es par da 0, si es impar da 1. */
	}
	return OK;
}

status_t impresion_arreglo(float v[], size_t n)
{
	size_t i;

	if(v == NULL)
		return ERROR_NULL_POINTER;
	
	putchar('[');
	
	for(i = 0; i < n; i++)
	{
		printf("%lf", v[i]);
		if(i < n-1)
			printf(",\t");
	}
	
	putchar(']');
	
	putchar('\n');
	
	return OK;
}