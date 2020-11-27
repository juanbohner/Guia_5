#include <stdio.h>

#define MAX_NUM_OF_COEF 10

#define MSG_ERROR_NOT_A_NUMBER 				"Se ingreso algo distinto de un numero"
#define MSG_ERROR_NOT_ENOUGH_COEFFICIENTS	"El grado ingresado es mayor a la cantidad de coeficientes que tiene el arreglo."
#define MSG_ERROR_EOF						"Se le paso a la funcion de lectura EOF."
#define MSG_MAX_ERRORS						"Ocurrio un error desconocido."	
#define MSG_NULL_POINTER 					"La funcion recibio un puntero NULL"

#define MSG_ENTER_GRADE 					"Introduzca el grado del polinomio"
#define MSG_GRADO_ERROR 					"El grado del polinomio es muy grande para este programa. Introduzca uno igual o menor a:"
#define MSG_ENTER_X 						"Introduzca el valor de la variable independiente x puntualmente."



#define MSG_RESULTADO_PUNTUAL 				"Resultado puntual del polinomio en x = : "
#define MSG_ES 								"Es: "

typedef enum{
		OK,
		ERROR_NULL_POINTER					= 1,
		ERROR_NOT_A_NUMBER					= 2,
		ERROR_EOF							= 3,
		ERROR_NOT_ENOUGH_COEFFICIENTS		= 4,
		MAX_ERRORS
} status_t;

status_t obtencion_de_x( double * x);

status_t obtencion_de_grado( size_t * n);

double evaluate_poli(const double coef[], size_t grade, double x);

int main(void)
{
	/*Los coeficientes estan ordenados desde el coeficiente de un polinomio de grado 0, hasta el de grado MAX_NUM_OF_COEF.*/
	const double coeficientes [MAX_NUM_OF_COEF] = 
	{0,1,2,3,4,5,6,7,8,9};
	size_t grado;
	double x;

	status_t st;
	


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


	/*Obtencion y validacion de x*/
	printf("%s\n", MSG_ENTER_X);

	st = obtencion_de_x(&x);

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
	printf("%s%lf\t%s%lf\n", MSG_RESULTADO_PUNTUAL, x, MSG_ES, evaluate_poli(coeficientes, grado, x));


	return OK;
}



/* Funcion para obtener variable x*/
status_t obtencion_de_x( double * x)
{
	int st, c;
	double num;

	if( x == NULL)
		return ERROR_NULL_POINTER;

	if ( !(st = scanf("%lf", &num)))
		return ERROR_NOT_A_NUMBER;

	if (st == EOF)
		return ERROR_EOF;
	
	while ((c=getchar()) != '\n' );

	* x = num;

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

/*Aplicando regla de horner para obtener el valor del polinomio en el el punto x.*/
double evaluate_poli(const double coef[], size_t grade, double x)
{
	size_t i;
	double resultado;
	
	for (resultado = 0, i = 0; i < grade; i++)
	{
 		resultado = resultado * x + coef[grade-i-1];
	}
	

	return resultado;
}
