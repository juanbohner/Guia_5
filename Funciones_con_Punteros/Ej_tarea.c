#include <stdio.h>
#include <string.h>

#define M 			100
#define MAX_ERRORS 3								

#define MSG_ERROR_NULL_POINTER 			"NULL pointer"
#define MSG_OK							"OK"		

typedef enum {
    OK,
    ERROR_NULL_POINTER					= 1,
	MAX_ERRORs
} status_t;

const char * errors [MAX_ERRORS] = {	MSG_ERROR_NULL_POINTER,
										OK	
};

status_t phrase_reverse(char s[]);

status_t string_reverse ( char str[]);

int main(void)
{
	char s[M]= "hola mundo feliz feliz    "; 
	/*Quiero que la funcion me devuelva: 	feliz mundo hola*/

	/*Planteo lo siguiete:					hola mundo feliz 															0123456789|||||| 
													 10|||||
													  11||||
													   12|||
													    13||
													     14|
														  15
											zilef odnum aloh
											0123456789|||||| 
													 10|||||
													  11||||
													   12|||
													    13||
													     14|
														  15
	*/
	status_t st;

	st = phrase_reverse(s);
	if(st != OK)
	{
		fprintf(stderr,"%s%s", "Error de tipo:", errors[st]);
		return st;
	}

	puts(s);
	return 1;

}


status_t phrase_reverse (char *s)
{	
	char  reverse[M];
	size_t len, i, index, word_start, word_end;

	len   = strlen(s);
	index = 0;

	if(s == NULL)
		return ERROR_NULL_POINTER;

	/* checkea desde el final de s hasta el principio*/
    for(word_start = len - 1, word_end   = len - 1 ; word_start > 0; word_start--)
    {
        /*Si encontramos el principio de una palabra*/
        if(s[word_start] == ' ')
        {
            /*Agregar la palabra encontrada en el arreglo reverse*/
            for(i = word_start + 1; i <= word_end; i++, index++)
            {
                reverse[index] = s[i];
            }

			/*Agregar el espacio en reverse atras de la palbra que encontramos*/
            reverse[index++] = ' ';

			/*Word_end pasa a ser la posicion de el ultimo caracter de la proxima palabra(de atras para adelante), ya que antes wordStart antes estaba en el primer espacio (de atras para adelante)*/
            word_end = word_start - 1;
        }
    }

    /*Falta agregar la ultima palabra. La hacemos afuera de ciclo anterior ya que, wordStart no puede ser igual a 0.*/
    for(i=0; i<=word_end; i++, index++)
    {
        reverse[index] = s[i];
    }

    /*Falta agregar el caracter \0 al arreglo reverse copiado*/
    reverse[index] = '\0';
	
	strcpy(s, reverse);

	return OK;
}