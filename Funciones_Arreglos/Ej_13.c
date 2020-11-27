#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LENGTH 					15
#define MAX_RANDOM_VALUE			50
#define EXTREMO_MAX_ID 				0
#define EXTREMO_MIN_ID 				1


#define MSG_MAX_VALUE				"El maximo valor del arreglo es:"
#define MSG_MIN_VALUE				"El minimo valor del arreglo es:"


#define MSG_SELECT_MAX 				"para obtener el maximo. "
#define MSG_SELECT_MIN				"para obtener el minimo. "
#define MSG_ENTER 					"Inrese"
#define MSG_THE_RANDOM_ARRAY_IS		"El arreglo aleatorio es el siguiente:"


/*#define MSG_TYPE_ERROR 				"Error del tipo:"*/
#define MSG_ERROR_NOT_A_NUMBER 		"Lo que se ingreso no es un caracter."
#define MSG_ERROR_INVALID_NUMBER	"Se ingreso un numero invalido"
#define MSG_ERROR_NULL_POINTER		"Se detecto un puntero nulo"
#define MSG_NOT_ABLE_TO_READ		"Se cerro el flujo."

typedef enum {
		EXTREMO_MAX,
		EXTREMO_MIN
} extremo_t;

typedef enum{
		OK 						= 0,
		ERROR_NOT_A_NUMBER		= 1,
		ERROR_NULL_POINTER		= 2,
		ERROR_NOT_ABLE_TO_READ	= 3,
		ERROR_INVALID_NUMBER	= 4,
		MAX_ERRORS
} status_t;

const char * errors [MAX_ERRORS] = { "\n", MSG_ERROR_NOT_A_NUMBER, MSG_ERROR_NULL_POINTER, MSG_NOT_ABLE_TO_READ, MSG_ERROR_INVALID_NUMBER};


/*Otener un arreglo de numeros del tipo double aleatorios*/
status_t generar_arreglo_aleatorio(double arr[], size_t n);


/*Impresion de un arreglo de numeros del tipo double*/
status_t impresion_arreglo(double arr[], size_t n);


/*Para obtener si se desea el max o el min*/
status_t seleccionar_max_min (extremo_t * max_or_min);


/*Devolver el max o el minimo de un arreglo.*/
double find_max_or_min_value(double arr[], size_t length, extremo_t extremo);


int main(void)
{	
	
	double arr[MAX_LENGTH];
	double value;
	status_t st;
	extremo_t extremo;

	printf("%s %d %s%s %d %s\n\n", MSG_ENTER, EXTREMO_MAX_ID, MSG_SELECT_MAX, MSG_ENTER, EXTREMO_MIN_ID,MSG_SELECT_MIN);

	/*Llenar el arreglo arr de numeros aleatoreos entre 0 y 50.*/
	st = generar_arreglo_aleatorio(arr, MAX_LENGTH);

	if(st != OK)
	{
	fprintf(stderr, "%s%s\n", "Error:", errors[st]);
	return st; /* informar lo informado */
	}

	
	/*Imprimir el arreglo generado*/
	st = impresion_arreglo(arr, MAX_LENGTH);

	if(st != OK)
	{
	fprintf(stderr, "%s%s\n", "Error:", errors[st]);
	return st; 
	}

	/*Obtener si se quiere el maximo o el minimo*/
	st = seleccionar_max_min (&extremo);

	if(st != OK)
	{
	fprintf(stderr, "%s%s\n", "Error:", errors[st]);
	return st; 
	}


	/*Impresion  y devoluvion del maximo o el min en funcion de lo que indique el usuario.*/
	switch(extremo)
	{
		case EXTREMO_MAX:
			value = find_max_or_min_value(arr, MAX_LENGTH, extremo);
			printf("%s\t%f\n", MSG_MAX_VALUE, value);
			break;
		

		case EXTREMO_MIN:
			find_max_or_min_value(arr, MAX_LENGTH, extremo);
			printf("%s\t%f\n", MSG_MIN_VALUE, value);
			break;
		

		default:
			value = find_max_or_min_value(arr, MAX_LENGTH, extremo);
			printf("%s\t%f\n", MSG_MAX_VALUE, value);
			break;
	}

	return OK;
}



status_t generar_arreglo_aleatorio(double v[], size_t n)
{
	size_t i;

	if(v == NULL)
        return ERROR_NULL_POINTER;


	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		v[i] = (rand() % MAX_RANDOM_VALUE);
		/*Obtiene numeros double desde el 0.000000 hasta el 50.00000*/
	}
	return OK;
}



/*Impresion por linea*/
status_t impresion_arreglo(double v[], size_t n)
{
	size_t i;

	if(v == NULL)
		return ERROR_NULL_POINTER;
	
	for(i = 0; i < n; i++)
	{
		printf("%f\n", v[i]);
	}
	
	return OK;
}




status_t seleccionar_max_min( extremo_t * max_or_min)
{
	/*Obtengo el numero para saber si es el caso del MAX o el MIN*/
	int num, st, c;
	
	if ( !(st = scanf("%d", &num)))
	{
		fprintf(stderr, "%s\n", MSG_ERROR_NOT_A_NUMBER);
		return ERROR_NOT_A_NUMBER;
	}
	if (st == EOF)
		return ERROR_NOT_ABLE_TO_READ;

	while ((c=getchar()) != '\n' && c != EOF);
	if (c == EOF)
		return ERROR_NOT_ABLE_TO_READ;
	
	if( max_or_min == NULL)
		return ERROR_NULL_POINTER;

	if(num == EXTREMO_MAX_ID  || num == EXTREMO_MIN_ID)
	{
		*max_or_min = num;
		return OK;
	}

	return ERROR_INVALID_NUMBER;
	
}



double find_max_or_min_value(double arr[], size_t length, extremo_t extremo)
{
	double valor;
	size_t i;

	valor = arr[0];
	
	
	switch(extremo)
	{
		case EXTREMO_MAX:
			for(i = 1; i < length; i++)
			{
				if(arr[i] > valor)
				{
					valor = arr[i];
				}
			}
			break;
		
		
		case EXTREMO_MIN:
			for(i = 1; i < length; i++)
			{
				if(arr[i] < valor)
				{
					valor = arr[i];
				}
			}
			break;

	}
	return valor;
}