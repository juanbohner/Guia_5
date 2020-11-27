/*
1)
Una variable static adentro de una funcion hace que los valores de la variable que se declara adento de la funcion no se pierdan. (Cuando se crean variables adentro de una funcion, estas se pierden pq se mueren cuando se cierra la funcion. Para la static no se cumple lo anterior dicho. Se guarda en algun lado su valor.)
*/

#include <stdio.h>

int foo();
int foo_static();

int main(void)
{
    int i;

    for (i = 0; i < 10; ++i)
    { 
	    foo();
		printf("a = %d, static_a = %d\n", foo(), foo_static());
	}
	return 0;
}

int foo()
{
    int a = 10;
	return a += 5;
}
/*a para cada invocacion de la funcion foo devolvemos el valor de la variable tipo int, a, donde el return es: a = a + 5. Al terminar la funcion la variable a desaparece y resurge cuando invocamos a la funcion foo. (a es una variable local a foo.)(Osea que la variable a vale 5 para cada invocacion.)*/

int foo_static()
{
    static int static_a = 10;
	return static_a += 5;
}
/*a para cada invocacion de la funcion foo_static devolvemos el valor de la variable tipo static int ,static_a, donde el return es: a = a + 5. Al terminar la funcion la variable static_a NO desaparece, guarda su valor en algun lugar, entonces cuando la reinvocamos a la funcion foo_static, static_a ya tenia su valor original modificado. Le habiamos sumado su valor actual y 5. (Osea que la variable a_static_i = a_static_i-1 + 5 para cada invocacion.)*/