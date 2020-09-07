/*
 ============================================================================
 Pedir 5 numeros y mostrar el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int main(void) {

	setbuf(stdout,NULL); // Esto es para Windows, sino la consola imprime todo junto.

	int numero;
	int acumulador=0;
	float promedio;
	int respuestaScan;
	int i;

	for(i = 0; i < 5; i++){
		printf("\nIngrese un numero: ");
		respuestaScan = scanf("%d", &numero);
		while(respuestaScan == 0){
			printf("Error, reingrese el numero");
			// Linux: __fpurge(stdin); Adem�s, hay que agregar arriba (#include<stdio_ext.h>)
			fflush(stdin); // Para limpiar el buffer de la consola antes de quedarme esperando que se ingrese algo.
			respuestaScan = scanf("%d", &numero);
		}
		acumulador += numero;
	}
	promedio = (float)acumulador / i;
	printf("\nEl promedio es: %.2f", promedio);
	return EXIT_SUCCESS;
}


