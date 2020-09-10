/*
 ============================================================================
Explicación de & y *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void otraFuncion(float* direccion);

int main(void) {
	setbuf(stdout,NULL);
	// & : La direccion de mem de la variable que tiene a la derecha.
	// int* b;  Indico que la variable va a guardar direcciones de mem.
	// *puntero : Accedo a la direccion y leo o escribo
	// *puntero = valor; // escribir
	//  variable = *puntero; // leer
	float a=55.5;
	//int* b;
	//b = &a;
	printf("direccion de a: %p\n",&a); // Antes estaba %u, ahora muestra hexa
	otraFuncion(&a);
	printf("\na vale:%f",a); // deberia dar 8
	return EXIT_SUCCESS;
}

void otraFuncion(float* direccion)
{
	printf("recibi en la funcion %p",direccion); // Antes estaba %u
	*direccion = 8.0;
}
