#include <stdio.h>

#define MAX_NUM_OF_COEF 10
#define AMOUNT 15

#define MSG_ERROR_NOT_A_NUMBER 				"Se ingreso algo distinto de un numero"
#define MSG_ERROR_NOT_ENOUGH_COEFFICIENTS	"El grado ingresado es mayor a la cantidad de coeficientes que tiene el arreglo."
#define MSG_ERROR_EOF						"Se le paso a la funcion de lectura EOF."
#define MSG_MAX_ERRORS						"Ocurrio un error desconocido."	
#define MSG_NULL_POINTER 					"La funcion recibio un puntero NULL"

#define MSG_ENTER_GRADE 					"Introduzca el grado del polinomio"
#define MSG_GRADO_ERROR 					"El grado del polinomio es muy grande para este programa. Introduzca uno igual o menor a:"
#define MSG_ERROR_NOT_ENOUGH_MEMORY			"No hay suficiente memoria"



#define MSG_RESULTADO_PUNTUAL 				"Resultado puntual del polinomio en x = : "
#define MSG_ES 								"Es: "

typedef enum{
		OK,
		ERROR_NULL_POINTER					= 1,
		ERROR_NOT_A_NUMBER					= 2,
		ERROR_EOF							= 3,
		ERROR_NOT_ENOUGH_COEFFICIENTS		= 4,
		ERROR_NOT_ENOUGH_MEMORY				= 5,
		MAX_ERRORS
} status_t;


status_t obtencion_de_grado( size_t * n);

double evaluate_poli(const double coeficientes[], size_t grade, double x);

status_t sample_poli (double coeficientes[], size_t grade, double muestras[], size_t cantidad, double inicio, double fin); 

int main(void)
{
	/*Los coeficientes estan ordenados desde el coeficiente de un polinomio de grado 0, hasta el de grado MAX_NUM_OF_COEF.*/
	double coeficientes [MAX_NUM_OF_COEF] = 
	{0,1,2,3,4,5,6,7,8,9};

	double muestras [MAX_NUM_OF_COEF];

	size_t grado;
	double x;

	status_t st;
	
	double fin = 6, inicio = 2;


	/*Obtencion y validacion del grado*/
	printf("%s\n", MSG_ENTER_GRADE);
	
	st = obtencion_de_grado( &grado );

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

		case ERROR_NOT_ENOUGH_COEFFICIENTS:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_ENOUGH_COEFFICIENTS);
				return ERROR_NOT_ENOUGH_COEFFICIENTS;
				break;
			}
		default :
			{
				fprintf(stderr, "%s\n", MSG_MAX_ERRORS);
				return MAX_ERRORS;
				break;
			}
	}


	/*Calcular el valor del polinomio*/
	st = sample_poli(coeficientes, grado, muestras, AMOUNT,  inicio, fin);

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

		case ERROR_NOT_ENOUGH_MEMORY:
			{	
				fprintf(stderr, "%s\n", MSG_ERROR_NOT_ENOUGH_MEMORY);
				return 	ERROR_NOT_ENOUGH_COEFFICIENTS;
				break;
			}

		default :
			{
				fprintf(stderr, "%s\n", MSG_MAX_ERRORS);
				return MAX_ERRORS;
				break;
			}
	}


	return OK;
}


/*Funcion para obtener el grado. Empieza en grado 0 hasta MAX_NUM_OF_COEF*/
status_t obtencion_de_grado( size_t * n)
{
	int st, c;
	size_t num;

	if( n == NULL)
		return ERROR_NULL_POINTER;

	if ( !(st = scanf("%ld", &num)))
		return ERROR_NOT_A_NUMBER;
	
	if (st == EOF)
		return ERROR_EOF;
		
	while ((c=getchar()) != '\n' );
	
	if (num > MAX_NUM_OF_COEF)
		return ERROR_NOT_ENOUGH_COEFFICIENTS;

	* n = num + 1;

	return OK;
}


status_t sample_poli (double coef[], size_t grade, double muestras[], size_t cantidad, double inicio, double fin)
{
	size_t i, j;
	double resultado;
	double x;

	if(coef == NULL || muestras == NULL)
		return ERROR_NULL_POINTER;

	if(fin > cantidad)
		return ERROR_NOT_ENOUGH_MEMORY;

	for (x = inicio, j = 0; x < fin; x++, j++)
	{
		for (resultado = 0, i = 0; i < grade; i++)
		{
			resultado = resultado * x + coef[grade-i-1];
		}
		muestras[j] = resultado;
	}
	putchar('[');

	for(i = 0; i < fin; i++)
	{
		printf("%lf", muestras[i]);
		if( i < fin - 1)
		{
			printf(",\t");
		}
	}
	printf("]\n");
}