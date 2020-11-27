#include <stdio.h>

long calculo_factorial(size_t num);

int main(void)
{
	long factorial;

	size_t numero;
	numero = 10;

	factorial = calculo_factorial (numero);
	printf("%ld\n", factorial);
	
	return 0;
}

long calculo_factorial (size_t num)
{
	size_t i;
	long factorial = 1;
	for (i = 1; i <= num; i++)
	{
		factorial *= i;
	}
	return factorial;
}