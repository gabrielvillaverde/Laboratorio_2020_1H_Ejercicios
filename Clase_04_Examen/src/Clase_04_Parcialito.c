/*
 ============================================================================
 Solicitar al usuario que ingrese una serie de n�meros mayores o iguales a 0 e inferiores a 1000, la
 aplicaci�n finaliza al introducir el n�mero 1000 (IMPORTANTE: El 1000 no debe ser tenido en cuenta
 para dicho c�lculo). Una vez finalizado el ingreso de n�meros el programa deber� mostrar el
 promedio de dichos n�meros por pantalla. En el caso de ingresar mal un n�mero el programa debe
 dar 2 reintentos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int acumulador = 0; // A
	int numero; // B
	int contador = 0; // C
	float promedio; // D
	int respuesta;

	while(1) // E, el while es infinito hasta que el usuario ingrese el n�mero 1000. Este n�mero no se tiene en cuenta para acumular. La cantidad de reintentos es 2.
	{
		respuesta = utn_getNumero(&numero,"Ingrese un numero, si ingresa 1000 finaliza el ingreso:\n*","*Error\n",0,1000,2); // F
		if(respuesta == 0 && numero!= 1000) // G, si la respuesta sali� bien (0), y el n�mero no es 1000...
		{
			acumulador = acumulador + numero; // H...sigo acumulando.
			contador++; // ...aumento el contador.
		}
		else
		{
			break; // I
		}
	}
	promedio = (float)acumulador/contador; // J
	printf("\n El promedio es: %f", promedio);
	return 0;
}
