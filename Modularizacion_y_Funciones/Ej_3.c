#include <stdio.h>

#define STATUS_MESSAGE_OK "OK"
#define STATUS_MESSAGER_ERROR_NULL_POINTER "La funcion recibio un puntero nulo"

typedef unsigned int uint;
typedef enum {
    OK,
    ERROR_NULL_POINTER
} status_t;

status_t transform_seconds_to_h_m_s(uint total_seconds, uint *h, uint *m, uint *s);

int main(void)
{
	uint hora, minutos, segundos;

	uint segundos_total = 10000;
	
	status_t st;
	
	char *status_messages[] = {STATUS_MESSAGE_OK, STATUS_MESSAGER_ERROR_NULL_POINTER};

	st = transform_seconds_to_h_m_s(segundos_total, &hora, &minutos, &segundos);

	if (st)
	{
		fprintf(stderr, "%s\n", STATUS_MESSAGER_ERROR_NULL_POINTER);
		return ERROR_NULL_POINTER;
	}
	printf ("H: %d\tM: %d\tS: %d\n", hora, minutos, segundos);

	return OK;
}

status_t transform_seconds_to_h_m_s(uint total_seconds, uint *h, uint *m, uint *s)
{
	if (h == NULL || m == NULL || s == NULL)
	{
        return ERROR_NULL_POINTER;
    }
	*h = total_seconds /3600;
	*m = (total_seconds % 3600) / 60;
	*s = total_seconds % 60;

	return OK;

}
