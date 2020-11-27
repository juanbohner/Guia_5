#include <stdio.h>

typedef enum{
	CELCIUS, 
	FAHRENHEIT
}temperature_t;

float conversion_temperatura(temperature_t tipo_temperatura, float valor_temperatura);

int main(void)
{
	float temperatura_origen = 23.45, temperatura_convertida;
	temperature_t tipo_escala_llegada = CELCIUS;

	temperatura_convertida = conversion_temperatura(tipo_escala_llegada, temperatura_origen);
	printf("%.3f\n", temperatura_convertida);
	return 0;
}
 float conversion_temperatura (temperature_t tipo,float value)
{	
	switch (tipo)
	{
		case CELCIUS:
			value = (value - 32)* (float) 5/9;
			return value;
		
		case FAHRENHEIT:
			value = (value * (float) 9/5) + 32;
			return value;
	}
}