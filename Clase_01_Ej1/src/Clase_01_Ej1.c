/*
 ============================================================================
 Pedir dos n�meros y sumarlos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL); // Solo en Windows

	int num1;
	int num2;
	int suma;

	printf("Ingrese un n�mero\n");
	scanf("%d", &num1);

	printf("Ingrese otro n�mero\n");
	scanf("%d", &num2);

	suma = num1 + num2;

	printf("La suma es %d", suma);
	return EXIT_SUCCESS;
}
