#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100

typedef enum{
	OK,
	ERROR_NULL_POINTER			= 1,

}status_t;

status_t left_trim(char *s);
status_t right_trim(char *s);
status_t trim(char *s);

int is_char(char c, char t) 
{
  return c == t;
  /*Si c es distonto de tm te devuelve 0. Si son iguales, te devuelve 1.*/
}

/*Quiero quitar los puntos a la izquierda y a la derecha.*/
int main(void) {
    char s[M] = "     hola  ";
	trim(s);
    puts(s);
    printf("L: %d \n", (int)strlen(s));
	/*Nos dice la longitud de la cadena tras haberla recortado.*/
    return 0;
} 

/*Quita espacios a la izquierda*/
status_t left_trim(char *s) {
    size_t i;

    if(s == NULL)
      return ERROR_NULL_POINTER;

	/*Cuento cuantos puntos hay a la izquierda de mi palabra. Con is_char veo si son iguales. con el i++ los cuento. Ya que al hacer en la condicion is_char('.', s[i]), lo que hace es ver cuando es distinto de 0. Esto pasa cuando lo que compara es cierto. Si s[i] es . entonces va a valer 1. Si no lo es, vale 0 y sale del cilo.*/
    for(i = 0; is_char(' ', *(s+i)); i++);
	



	/*Con el memmove muevo memoria. Recibe la direccion a donde la quiero mover. Direcciond e memoria desde donde voy a mover. Y luego que decir cuanto voy a mover. El cuanto es la longitud de mi cadena - la cantidad de puntos de la izquierda + 1 que es el '\0'.*/
    memmove(s, &(*(s+i)), strlen(s) - i + 1);
	
    
    return OK;
}

/*Quita espacios a la derecha*/
status_t right_trim(char *s) {
    int i;

	/*Validacion*/
    if(s == NULL)
      return ERROR_NULL_POINTER;


	/*Arranco contado desde el final. Veo cuantos son puntos. y voy decrementando.*/
    for(i = strlen(s) - 1; i >= 0 && is_char(' ', *(s+i)); i--);
	
	/*Le planco un \0 en la posicion donde encontre el ultimo .Pongo un i+1 porque el i-- me hace pararme en el proximo caracter (de derecha a izquiera) que no es un punto. Si pongo el + 1, vuelvo al ultimo punto.*/

    s[i+1] = '\0';
    
    return OK;
}

/*Quita los espacios de la derecha e izquierda*/
status_t trim(char *s) {
    status_t st;
    if(s == NULL)
      return ERROR_NULL_POINTER;
    
    st = right_trim(s);
    if(st != OK)
      return st;
    
    st = left_trim(s);
    if(st != OK)
      return st;

    return OK;
}