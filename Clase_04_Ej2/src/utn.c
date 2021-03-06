/*
 * utn.c
 *
 *  Created on: 3 sep. 2020
 *      Author: Hzkr
 */

/* Ejercicio: Desarrollar la funci�n utn_getNumero. */

#include <stdio.h>
#include <stdlib.h>


// Segunda forma

int utn_getNumero(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt; // Variable de intercambio con el usuario, donde leer� y guardar� el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			scanf("%d", &bufferInt); // Leo lo que recibo del usuario, y lo asigno a la direcci�n de memoria de bufferInt.
			if(bufferInt >= minimo && bufferInt <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al m�nimo, y menor/igual al m�ximo...
			{
				*pResultado = bufferInt; // Le asigno al puntero, lo que hay en bufferInt.
				retorno = 0; // Sali� todo bien, por eso el retorno devuelve 0.
				break; // Esto har�a que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y ser�a mayor o igual a 0.
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char * pResultado, char * mensaje, char * mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar; // Variable de intercambio con el usuario, donde leer� y guardar� el dato que el usuario ingresa.

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do // Me asegura que la primera vez se va a cumplir aunque reintentos venga cargado en 0.
		{
			printf("%s", mensaje); // Recibo un dato string, el mensaje del usuario.
			fflush(stdin); // __fpurge(stdin); en Linux. Esto va siempre antes de la lectura del scanf.
			scanf("%c", &bufferChar); // Leo lo que recibo del usuario, y lo asigno a la direcci�n de memoria de bufferInt.
			if(bufferChar >= minimo && bufferChar <= maximo) // Si lo que hay dentro de bufferInt es mayor/igual al m�nimo, y menor/igual al m�ximo...
			{
				*pResultado = bufferChar; // Le asigno al puntero, lo que hay en bufferInt.
				retorno = 0; // Sali� todo bien, por eso el retorno devuelve 0.
				break; // Esto har�a que deje de reintentar con la segunda forma.
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--; // Si viene en 1, lo decremento y ser�a mayor o igual a 0.
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/* // Primera forma

int utn_getNumero(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt; // Lo que leo con el scanf, lo guardo ac�.
	int contadorIntentos = 0;
	// Chequear que todos los punteros que recib�, no sean NULL.
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		do
		{
			if(contadorIntentos == reintentos){ // Verifica que el contador de intentos sea igual a reintentos.
				retorno = -2; // ...en tal caso, pone el retorno en -2 y sale. El retorno est� puesto as� para, en el main, devolver como resultado que se super� la cantidad de intentos.
				break;
			}

			printf("%s\n", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo){ // Verifica que sea mayor/igual que el m�nimo y que sea menor/igual que el m�ximo.
				retorno = 0; // ...en tal caso, pone el retorno en 0 para indicar que sali� todo bien.
				*pResultado = bufferInt; // El puntero de resultado se asigna a bufferInt.
				break;
			}
			else{
				printf("%s\n", mensajeError);
			}
			contadorIntentos++;
		}while(1);
	return retorno;
	}
}
*/
