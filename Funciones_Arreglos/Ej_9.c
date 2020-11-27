#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ARR_LENGTH 15

typedef enum{
	OK,
	ERROR_NULL_POINTER,
	MAX_ERROR
} status_t;
/*Calcular el promedio aritmetico*/
double promedio_aritmetico(double arr[], size_t n);

/*Otener un arreglo aleatorio*/
status_t arreglo_aleatorio(double arr[], size_t n);

/*Impresion de un arreglo*/
status_t impresion_arreglo(double arr[], size_t n);


int main(void)
{
	double random_arr[MAX_ARR_LENGTH];

	arreglo_aleatorio(random_arr, MAX_ARR_LENGTH);
	
	impresion_arreglo (random_arr, MAX_ARR_LENGTH);

	printf("%lf\n", promedio_aritmetico(random_arr, MAX_ARR_LENGTH));

	return 0;
	
}

status_t arreglo_aleatorio(double v[], size_t n)
{
	size_t i;

	if(v == NULL)
        return ERROR_NULL_POINTER;


	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		v[i] = (double) (rand() % 50);
		/*Obtiene numeros double desde el 0.000000 hasta el 50.00000*/
	}
	return OK;
}

status_t impresion_arreglo(double v[], size_t n)
{
	size_t i;

	if(v == NULL)
		return ERROR_NULL_POINTER;
	
	putchar('[');
	
	for(i = 0; i < n; i++)
	{
		printf("%lf,\t", v[i]);
	}
	
	putchar(']');
	
	putchar('\n');
	
	return OK;
}

double promedio_aritmetico(double v[], size_t n)
{
	double resultado, promedio_aritmetico;
	size_t i;


	for(i = 0; i < n; i++)
	{
		resultado += v[i];
	}
	promedio_aritmetico = (double) (resultado / n);
	return promedio_aritmetico;
}