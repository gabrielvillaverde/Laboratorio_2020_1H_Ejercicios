/*
 ============================================================================
Una funci�n que tenga dos par�metros y sume dos n�meros y devuelva el resultado.
La otra funci�n que tenga tres par�metros, un par�metro para guardar resultados y dos que son los n�meros para sumar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int funcionSumar(int parametroUno, int parametroDos);
int segundaFuncionSumar(int parametroUno, int parametroDos, int resultado);

int main(void) {

	setbuf(stdout,NULL); // Para que la consola no imprima todo de una.

	int numeroIngresadoUno;
	int numeroIngresadoDos;
	int resultadoUno;
	int resultadoDos = 0; // Para la segundaFuncionSumar

	printf("Ingrese el primer n�mero:\n");
	scanf("%d",&numeroIngresadoUno);

	printf("Ingrese el segundo n�mero:\n");
	scanf("%d",&numeroIngresadoDos);

	resultadoUno = funcionSumar(numeroIngresadoUno, numeroIngresadoDos);
	printf("El resultado Uno en la funci�n main es: %d\n", resultadoUno);

	segundaFuncionSumar(numeroIngresadoUno, numeroIngresadoDos, resultadoDos);
	printf("El resultado Dos en la funci�n main es: %d\n, porque le est� pasando la copia de la variable, y no el valor verdadero", resultadoDos);

	return EXIT_SUCCESS;
}

int funcionSumar(int parametroUno, int parametroDos){

	int resultado = parametroUno + parametroDos;

	return resultado;
}

int segundaFuncionSumar(int parametroUno, int parametroDos, int *pResultadoDos){

	resultadoDos = parametroUno + parametroDos;
	printf("El resultado Dos dentro de la segundaFuncionSumar es: %d\n", resultadoDos);

	return resultadoDos;
}
