#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ARR_LENGTH 15
#define MSG_DESVIO_ESTANDAR "El desvio estandar de los numeros del arreglo es:"

typedef enum{
	OK,
	ERROR_NULL_POINTER,
	MAX_ERROR
} status_t;
/*Calcular el promedio aritmetico*/
double calcular_desvio_estandar(double arr[], size_t n);

/*Otener un arreglo aleatorio*/
status_t arreglo_aleatorio(double arr[], size_t n);

/*Impresion de un arreglo*/
status_t impresion_arreglo(double arr[], size_t n);


int main(void)
{
	double random_arr[MAX_ARR_LENGTH];

	arreglo_aleatorio(random_arr, MAX_ARR_LENGTH);
	
	impresion_arreglo (random_arr, MAX_ARR_LENGTH);
	printf("\n%s:\t", MSG_DESVIO_ESTANDAR);
	printf("%lf\n", calcular_desvio_estandar(random_arr, MAX_ARR_LENGTH));

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
		v[i] = (rand() % 50);
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
		printf("%lf", v[i]);
		if(i < n-1)
			printf(",\t");
	}
	
	putchar(']');
	
	putchar('\n');
	
	return OK;
}

double calcular_desvio_estandar(double v[], size_t n)
{
	double resultado, promedio_aritmetico, sumatoria_desvio_estandar, desvio_estandar;
	size_t i;


	for(i = 0; i < n; i++)
	{
		resultado += v[i];
	}
	promedio_aritmetico = (double)resultado/n ;

	for (i = 0; i < n; i++)
	{
		sumatoria_desvio_estandar += ( (v[i] - promedio_aritmetico) * (v[i] - promedio_aritmetico));
	}

	desvio_estandar = sqrt(sumatoria_desvio_estandar/n); 
	return desvio_estandar;
}