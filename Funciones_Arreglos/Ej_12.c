#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MONTHS 					12
#define MAX_CHAR 					11


#define MONTH_ENERO_ID				1
#define MONTH_DICIEMBRE_ID			12

#define MAX_STR_LECTURA				10



#define MSG_ERROR_NOT_A_NUMBER 		"Lo que se ingreso no es un numero."
#define MSG_ERROR_INVALID_NUMBER	"Se ingreso un numero invalido"
#define MSG_ERROR_NULL_POINTER		"Se detecto un puntero nulo"
#define MSG_NOT_ABLE_TO_READ		"Se cerro el flujo."
#define MSG_ERROR_READING_VALUE		"No se pudo leer correctamente el valor ingresado."



typedef enum {
	MONTH_ENERO 					= 1,
	MONTH_FEBRERO 					= 2,
	MONTH_MARZO 					= 3,
	MONTH_ABRIL 					= 4,
	MONTH_MAYO 						= 5,
	MONTH_JUNIO						= 6,
	MONTH_JULIO						= 7,
	MONTH_AGOSTO					= 8,
	MONTH_SEPTIEMBRE				= 9,
	MONTH_OCTUBRE					= 10,
	MONTH_NOVIEMBRE					= 11,
	MONTH_DICIEMBRE					= 12
} month_t;

typedef enum{
	OK,
	ERROR_NOT_A_NUMBER				= 1,
	ERROR_NULL_POINTER				= 2,
	ERROR_NOT_ABLE_TO_READ			= 3,
	ERROR_INVALID_NUMBER			= 4,
	ERROR_READING_VALUE				= 5,
	MAX_ERRORS
} status_t;


const char * errors [MAX_ERRORS] = { "\n", MSG_ERROR_NOT_A_NUMBER, MSG_ERROR_NULL_POINTER, MSG_NOT_ABLE_TO_READ, MSG_ERROR_INVALID_NUMBER, MSG_ERROR_READING_VALUE};

const char  * array_of_ptrs_2_months_str [MAX_MONTHS] = {"ENERO", "FEBRERO","MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};


/*Hacer la traduccion*/
status_t get_month_description (month_t month, char str[]);

/*Para obtener lo que hay que traducir del usuario*/
status_t obtencion_mes (month_t * mes_ingresado);

int main(void)
{

	month_t mes;
	char string [MAX_CHAR];
	/*int num_ingresado;*/
	status_t st;

	st = obtencion_mes (&mes);

	if(st != OK)
	{
		fprintf(stderr, "%s%s\n", "Error:", errors[st]);
		return st; 
	}



	if((st = get_month_description (mes, string) != OK))
	{
		fprintf(stderr, "%s\t%d\n", "Error de tipo:", st);
		return st;
	}
	fputs(string, stdout);
	putchar('\n');

	return OK;
}


status_t obtencion_mes( month_t * num_ingresado)
{

	char str_lectura[MAX_STR_LECTURA];
	char * temp;

	if(fgets(str_lectura, MAX_STR_LECTURA+2, stdin) == NULL)
		return ERROR_READING_VALUE;

	*num_ingresado = (month_t) strtod(str_lectura, &temp);

	if (*temp && *temp != '\n')
        return ERROR_NOT_A_NUMBER;
	
	if(*num_ingresado >=  MONTH_ENERO_ID  && *num_ingresado <=  MONTH_DICIEMBRE_ID)
		return OK;


	return ERROR_INVALID_NUMBER;
		
}

status_t get_month_description (month_t month, char str[])
{
	char *p_2_str_copiado;
	const char **p_2_array_of_ptrs_2_months_str;

	if (str == NULL)
		return ERROR_NULL_POINTER;
	if (*array_of_ptrs_2_months_str == NULL)
		return ERROR_NULL_POINTER;
	if (*errors == NULL)
		return ERROR_NULL_POINTER;
	

	/*El puntero p esta apuntando a la direccion de memoria del arreglo string de la main que es donde vamos a hacer la copia.*/
	p_2_str_copiado = str;
	p_2_array_of_ptrs_2_months_str = array_of_ptrs_2_months_str;

	strcpy(p_2_str_copiado, *(p_2_array_of_ptrs_2_months_str + month -1));
	/*
	Hacemos que el que el nombre del arreglo de punteros a const char(que nos da la direccion del primer puntero del arreglo, 
	basicamente el nombre es como un puntero), para ir al puntero que apunta a la palabra que resperesenta al mes que queramos, 
	que esta adentro de ese arreglo de punteros, le tenemos que sumar el valor del mes leido y restarle 1 (ya que arranca en 
	la posicion 0 los arreglos y el mes leido arranca con 1) Luego aplicndo el *, indicamos que qeremos copiar a lo que esta 
	apuntando ese puntero donde estamos parados, lo cual va a ser la palabra que representa a ese mes en particular.(un string).
	 Luego la copiamos a donde esta apuntando el puntero p(que es string).
	*/
	
	return OK;
}