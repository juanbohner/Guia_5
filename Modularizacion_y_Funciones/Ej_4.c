#include <stdio.h>
#include <math.h>

typedef enum{
	OK,
	ERROR
} status_t;

double distancia_2_puntos_coordenadas_cartesianas(float Punto_1_x, float Punto_1_y, float Punto_2_x, float Punto_2_y);

int main(void)
{
	float P_1_x = 3.1415, P_1_y = 2.3, P_2_x = 23, P_2_y = 47;

	printf("%lf\n", distancia_2_puntos_coordenadas_cartesianas(P_1_x, P_1_y, P_2_x, P_2_y));

	return OK; 
}

double distancia_2_puntos_coordenadas_cartesianas(float x_1, float y_1, float x_2, float y_2)
{
	return sqrt(((x_2 - x_1)*(x_2 - x_1)) + ((y_2 - y_1)*(y_2 - y_1))); 
}