/*
 ============================================================================
 Name        : Clase_04_Ej2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{

	setbuf(stdout,NULL); // SI O SI EN WINDOWS. De otra forma la consola imprime todo junto.

	int edad;
	int peso;
	char letra;
	int respuesta;

	respuesta = utn_getCaracter(&letra,"Letra?\n","Error, la letra debe ser desde A a J\n", 'A','J',1);
	if(respuesta == 0)
	{
		printf("\nLa letra es: %c", letra);
	}
	else{
		printf("\nError");
	}

	respuesta = utn_getNumero(&edad,"\nEdad?","Error, la edad debe ser 0 a 199\n", 0, 199, 2);
	if(respuesta == 0)
	{ // Si la respuesta est� bien, es decir, si obtuvo la edad entre 0 y 199.
		printf("La edad es: %d\n", edad);
	}
	else{
		printf("\nError");
	}

	respuesta = utn_getNumero(&peso,"Peso?\n","Error, el peso debe ser desde 0 a 500\n", 0, 500, 3);
	if(respuesta == 0)
	{
		printf("El peso es: %d", peso);
	}
	else{
		printf("\nError");
	}
	return EXIT_SUCCESS;
}
