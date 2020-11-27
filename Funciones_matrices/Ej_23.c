#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define N		 					3
#define MAX_RANDOM_VALUE			9
#define MAX_MATRIX_TYPE				2
#define EXTREMO_MAX_ID 				0
#define EXTREMO_MIN_ID 				1


#define MSG_MAX_VALUE				"El maximo valor del arreglo es:"
#define MSG_MIN_VALUE				"El minimo valor del arreglo es:"


#define MSG_SELECT_MAX 				"para obtener el maximo. "
#define MSG_SELECT_MIN				"para obtener el minimo. "
#define MSG_ENTER 					"Inrese"
#define MSG_THE_RANDOM_ARRAY_IS		"El arreglo aleatorio es el siguiente:"

#define MSG_NOT_SYM_MATRIX			"La matrix no es symetrica"
#define MSG_SYM_MATRIX			"La matrix es symetrica"


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
	MATRIX_NOT_SYMMETRIC,
	MATRIX_SYMMETRIC
}matrix_t;

typedef enum{
		OK 						= 0,
		ERROR_NOT_A_NUMBER		= 1,
		ERROR_NULL_POINTER		= 2,
		ERROR_NOT_ABLE_TO_READ	= 3,
		ERROR_INVALID_NUMBER	= 4,
		MAX_ERRORS
} status_t;

const char * errors [MAX_ERRORS] = { "\n", MSG_ERROR_NOT_A_NUMBER, MSG_ERROR_NULL_POINTER, MSG_NOT_ABLE_TO_READ, MSG_ERROR_INVALID_NUMBER};

const char * matrix_type[MAX_MATRIX_TYPE] = {MSG_NOT_SYM_MATRIX, MSG_SYM_MATRIX};

/*Genrr una matriz cuadrada aleatoria*/
status_t generar_arreglo_aleatorio(int (*arr)[], size_t n);


/*Impresion de un arreglo de numeros del tipo double*/
status_t impresion_matrix(int (*arr)[], size_t n);

status_t transpose_matrix(int (*matrix_transpose)[N], int (*matrix_original)[N],size_t n);

matrix_t find_if_matrix_is_simetric(int (*matrix_transpose)[N], int (*matrix_original)[N],size_t n);

int main(void)
{
	int m[N][N];
	int m_t[N][N];
	status_t st;
	matrix_t matrix;

	int matr [N][N] = {
		{1,1,1},
		{1,1,1},
		{1,1,1}
	};
	int matr_t[N][N];



	st = generar_arreglo_aleatorio(m, N);
	if(st != OK)
	{
		fprintf(stderr, "%s%s\n", "Error del tipo:",errors[st]);
		return st;
	}
	st = impresion_matrix(m, N);
	if(st != OK)
	{
		fprintf(stderr, "%s%s\n", "Error del tipo:",errors[st]);
		return st;
	}

	st = transpose_matrix(m_t, m, N);
	if(st != OK)
	{
		fprintf(stderr, "%s%s\n", "Error del tipo:",errors[st]);
		return st;
	}

	matrix = find_if_matrix_is_simetric(m_t, m, N);
	printf("%s\n", matrix_type[matrix]);



	st = transpose_matrix(matr_t, matr, N);
	if(st != OK)
	{
		fprintf(stderr, "%s%s\n", "Error del tipo:",errors[st]);
		return st;
	}

	matrix = find_if_matrix_is_simetric(matr_t, matr, N);
	printf("%s\n", matrix_type[matrix]);
	


	return OK;
}


status_t generar_arreglo_aleatorio(int (*v)[N], size_t n)
{
	size_t i, j;

	if(v == NULL)
        return ERROR_NULL_POINTER;


	srand(time(NULL));

	 /* Assigning elements to the matrix */
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++) 
		{
           v[i][j] = (rand() % MAX_RANDOM_VALUE);
		/*Obtiene numeros double desde el 0.000000 hasta el 50.00000**/
        }
	}
	return OK;
}


status_t impresion_matrix(int (*v)[N], size_t n)
{
	size_t i, j;

	if(v == NULL)
		return ERROR_NULL_POINTER;
	
	for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++) 
		{
           printf("%d|\t",v[i][j]); 
        }
		putchar('\n');
	}
	
	return OK;
}


/* transpose of matrix a */
status_t transpose_matrix(int (*matrix_transpose)[N], int (*matrix_original)[N],size_t n)
{
	size_t i, j;
    
	if(matrix_original == NULL || matrix_transpose == NULL)
		return ERROR_NULL_POINTER;
     for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
		{
            matrix_transpose[j][i] = matrix_original[i][j];
        }
	}
	return OK;
}


matrix_t find_if_matrix_is_simetric(int (*matrix_transpose)[N], int (*matrix_original)[N],size_t n)
{
	size_t i, j;

	for(i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if(matrix_original[i][j] != matrix_transpose[i][j])
			{
				return MATRIX_NOT_SYMMETRIC;
			}
		}
	}
	return MATRIX_SYMMETRIC;
}