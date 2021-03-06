/*
 ============================================================================
Ejercicio sin asignar funciones ni bibliotecas en otros archivos.
Pedir dos n�meros al usuario y dividir.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciones
int dividir (float* pResultado, int operador1, int operador2);

int main(void) {

	setbuf(stdout,NULL); // Windows

	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nNumero 1: ");
	scanf("%d",&numero1);

	printf("\nNumero 2: ");
	scanf("%d",&numero2);

	respuesta = dividir(&resultado, numero1, numero2);
	if(respuesta == 0){
		printf("El resultado es: %f\n", resultado);
	}
	else{
		printf("No es posible dividir por cero\n");
	}
	return EXIT_SUCCESS;
}

int dividir (float* pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && operador2 != 0){
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}
