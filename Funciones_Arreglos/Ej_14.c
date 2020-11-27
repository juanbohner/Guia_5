#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAX_STR 							361
#define AMOUNT_N 							361
#define pi 									3.14159265

#define MSG_ERROR_NOT_A_NUMBER 				"Se ingreso algo distinto de un numero"
#define MSG_ERROR_NOT_ENOUGH_MEMORY			"El muesteo es mayor a la cantidad de memoria que tiene el arreglo."
#define MSG_ERROR_EOF						"Se le paso a la funcion de lectura EOF."
#define MSG_MAX_ERRORS						"Ocurrio un error desconocido."	
#define MSG_NULL_POINTER 					"La funcion recibio un puntero NULL"

#define MSG_ENTER_VALUE 					"Introduzca el valor de la "
#define MSG_APLITUDE 						"Amplitud (A)"
#define MSG_FREQUENCY 						"Freciencia (f)"
#define MSG_PHI								"Fase (phi)"


typedef enum{
		OK,
		ERROR_NULL_POINTER					= 1,
		ERROR_NOT_A_NUMBER					= 2,
		ERROR_EOF							= 3,
		ERROR_NOT_ENOUGH_MEMORY				= 4,
		MAX_ERRORS
} status_t;

status_t sample_sinusoid (double values [], size_t length, double * amplitud, double * frecuencia, double * phi);

status_t obtencion_dato( double *amplitud);

status_t impresion_array(double arr[], size_t length);

int main(void)
{
	double arr[MAX_STR];
	size_t t;

	double A, f, phi;

	status_t st;

	/*Obtener la Amplitud*/
	printf("%s%s\n", MSG_ENTER_VALUE, MSG_APLITUDE);

	st = obtencion_dato (&A );

	switch (st)
	{
		case OK:
			break;

		case ERROR_NULL_POINTER:
			{
				fprintf(stderr, "%s\n", MSG_NULL_POINTER);
				return ERROR_NULL_POINTER;
				break;
			}
		case ERROR_NOT_A_NUMBER:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_A_NUMBER);
				return ERROR_NOT_A_NUMBER;
				break;
			}

		case ERROR_EOF:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_EOF);
				return ERROR_EOF;
				break;
			}

		case ERROR_NOT_ENOUGH_MEMORY:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_ENOUGH_MEMORY);
				return ERROR_NOT_ENOUGH_MEMORY;
				break;
			}
		default :
			{
				fprintf(stderr, "%s\n", MSG_MAX_ERRORS);
				return MAX_ERRORS;
				break;
			}
	}

	/*Obtener la frecuencia*/
	printf("%s%s\n", MSG_ENTER_VALUE, MSG_FREQUENCY);

	st = obtencion_dato( &f);

	switch (st)
	{
		case OK:
			break;

		case ERROR_NULL_POINTER:
			{
				fprintf(stderr, "%s\n", MSG_NULL_POINTER);
				return ERROR_NULL_POINTER;
				break;
			}
		case ERROR_NOT_A_NUMBER:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_A_NUMBER);
				return ERROR_NOT_A_NUMBER;
				break;
			}

		case ERROR_EOF:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_EOF);
				return ERROR_EOF;
				break;
			}

		case ERROR_NOT_ENOUGH_MEMORY:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_ENOUGH_MEMORY);
				return ERROR_NOT_ENOUGH_MEMORY;
				break;
			}
		default :
			{
				fprintf(stderr, "%s\n", MSG_MAX_ERRORS);
				return MAX_ERRORS;
				break;
			}
	}


	/*Obtener a PHI*/
	printf("%s%s\n", MSG_ENTER_VALUE, MSG_PHI);
	st = obtencion_dato( &phi);

	switch (st)
	{
		case OK:
			break;

		case ERROR_NULL_POINTER:
			{
				fprintf(stderr, "%s\n", MSG_NULL_POINTER);
				return ERROR_NULL_POINTER;
				break;
			}
		case ERROR_NOT_A_NUMBER:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_A_NUMBER);
				return ERROR_NOT_A_NUMBER;
				break;
			}

		case ERROR_EOF:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_EOF);
				return ERROR_EOF;
				break;
			}

		case ERROR_NOT_ENOUGH_MEMORY:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_ENOUGH_MEMORY);
				return ERROR_NOT_ENOUGH_MEMORY;
				break;
			}
		default :
			{
				fprintf(stderr, "%s\n", MSG_MAX_ERRORS);
				return MAX_ERRORS;
				break;
			}
	}


	/*Obtener el muestreo de la funcion seno*/
	if((st = sample_sinusoid(arr, MAX_STR, &A, &f, &phi)) != OK)
	{
		fprintf(stderr, "%s\n", MSG_NULL_POINTER);
		return ERROR_NULL_POINTER;
	}

	/*Imprimir el arreglo con los muestreos*/
	if((st = impresion_array(arr, MAX_STR)) != OK)
	{
		fprintf(stderr, "%s\n", MSG_NULL_POINTER);
		return ERROR_NULL_POINTER;
	}


	return OK;
	
}

status_t obtencion_dato( double * A)
{
	int st, c;
	double num;

	if( A == NULL)
		return ERROR_NULL_POINTER;

	if ( !(st = scanf("%lf", &num)))
		return ERROR_NOT_A_NUMBER;

	if (st == EOF)
		return ERROR_EOF;
	
	while ((c=getchar()) != '\n' );

	*A = num;

	return OK;
}

status_t sample_sinusoid (double values [], size_t length, double * A, double * f, double * p)
{
	size_t t;
	if(values == NULL || A == NULL || f == NULL || p == NULL)
		return ERROR_NULL_POINTER;


	for(t = 0; t < length; t++)
	{
		/*La funcion sin funciona con angulos en radianes.*/
		values [t] = ((*A) * sin ((2 * pi * (*f) *((double) t /180)) + *p));
	}

	return OK;
}

status_t impresion_array(double arr[], size_t length)
{
	size_t t;

	if(arr == NULL)
		return ERROR_NULL_POINTER;

	for( t = 0 ; t < AMOUNT_N	 ; t++ )
	{
		printf("%lf,\n",arr[t]);
	}
	printf("\n");
	return OK;
}