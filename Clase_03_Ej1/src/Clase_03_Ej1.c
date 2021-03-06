/*
 ============================================================================
 Hacer un programa que pida un n�mero al usuario, despu�s que pida una operaci�n (+, -, /, *),
 despu�s que pida otro n�mero. Seg�n la operaci�n ingresada, se llamar� a una funci�n
 que ejecute la operaci�n sumar(), restar(), multiplicar() o dividir().
 Y luego mostrar al usuario el resultado. El mostrar resultado no puede estar dentro de
 las funciones que se crean para hacer la operaci�n. En la funci�n dividir, validar no dividir por cero.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
// Solo en Linux, para el __fpurge usar #include <stdio ext.h>

// Prototipos de funciones
int sumar (int operador1,int operador2);
int restar (int operador1,int operador2);
int multiplicar (int operador1,int operador2);
float dividir (int operador1,int operador2);

int main(void) {

	setbuf(stdout,NULL); // Solo en Windows

	int num1;
	int num2;
	char operacion;
	int resultadoInt;
	float resultadoFloat;

	printf("Ingrese un n�mero: \n");
	fflush(stdin); // Solo en Windows
	// Si es Linux = __fpurge(stdin);
	scanf("%d", &num1);

	printf("Ingrese una operaci�n: (+, -, * o /)\n ");
	fflush(stdin); // Solo en Windows
	// Si es Linux = __fpurge(stdin);
	scanf("%c", &operacion);

	printf("Ingrese otro n�mero: \n");
	fflush(stdin); // Solo en Windows
	// Si es Linux = __fpurge(stdin);
	scanf("%d", &num2);

	switch(operacion){
	case '+':
		resultadoInt = sumar(num1,num2);
		break;
	case '-':
		resultadoInt = restar(num1,num2);
		break;
	case '*':
		resultadoInt = multiplicar(num1,num2);
		break;
	case '/':
		resultadoFloat = dividir(num1,num2);
		printf("El resultado es %f", resultadoFloat);
		break;
	}

	if(operacion!='/'){
		printf("El resultado es %d", resultadoInt);
	}

	return EXIT_SUCCESS;
}

// Declaraci�n de funciones, (antes de ver el tema de punteros y bibliotecas)
int sumar(int operador1,int operador2){
	int resultado;
	resultado = operador1 + operador2;
	return resultado;
}

int restar(int operador1,int operador2){
	int resultado;
	resultado = operador1 - operador2;
	return resultado;
}

int multiplicar(int operador1,int operador2){
	int resultado;
	resultado = operador1 * operador2;
	return resultado;
}

float dividir(int operador1,int operador2){
	float resultado;
	resultado = (float)operador1 / operador2; // Castear.
	return resultado;
}
