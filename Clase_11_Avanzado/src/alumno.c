/*
 * alumno.c
 *
 *  Created on: 25 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0

#define SIZE_NOMBRE 51
#define SIZE_LASTNAME 51
#define QTY_ALUMNOS 1000

// Prototipos:
static int generateNewId(void);
static int releaseId(int idToRelease);
static int compareElements(Alumno currentAlumno, Alumno nextAlumno, int order, int sort);
static int freeIds[QTY_ALUMNOS];
static int len = 0;
static int IdsEmpty = TRUE;

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all the positions of the array
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int alumno_initAlumnos(Alumno* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i= 0;i<len;i++)
		{
			pArrayList[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Add in a existing list of alumnos the values received as parameters in the first empty position
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param index int Receives content of bufferAlumno
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int alumno_addAlumno(Alumno* pArrayList, int len, int index)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(pArrayList != NULL && len > 0 && index >= 0 && index <= len && pArrayList[index].isEmpty == TRUE)
	{
		if
		(
		utn_getName("\nName of alumno:\n","Error, please type a correct name.\n",bufferAlumno.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferAlumno, �por qu� ac� no y en las otras s� el &?
			&&
		utn_getName("\nLast name of alumno:\n","Error, please type a correct last name.\n",bufferAlumno.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferAlumno, �por qu� ac� no y en las otras s� el &?
			&&
		utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferAlumno.salary,2, 0, 999999)==0
			&&
		utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferAlumno.sector, 2, 0, 999999)==0
		)
		{
			bufferAlumno.id = generateNewId();
			pArrayList[index] = bufferAlumno;
			pArrayList[index].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Remove a Alumno by ID (put isEmpty Flag in TRUE)
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param index int Position in the array that changes between TRUE and FALSE value determined by isEmpty flag.
* \param id int Receives the ID that will be removed from the system.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a alumno] - (0) if Ok
*
*/
int alumno_removeAlumno(Alumno* pArrayList, int len, int index, int id)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0 && index < len && pArrayList[index].isEmpty == FALSE)
	{
		pArrayList[index].isEmpty = TRUE;
		releaseId(id);
		retorno = 0;
	}
	printf("\nYou just removed the following ID: %d\n",id);
	return retorno;
}

/** \brief Finds an empty slot in the array to load an alumno
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param pIndex int* Pointer to an empty position in the index.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a alumno] - (0) if Ok
*
*/
int alumno_findEmpty(Alumno* pArrayList, int len, int* pIndex)
{
	int retorno = -1;
	if(pArrayList != NULL && pIndex != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Finds an alumno by ID
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param id int Receives the ID of the alumno
* \param pIndex int* Pointer to a loaded position in the index
* \return int Return (-1) if Error [Invalid length or NULL pointer received or alumno not found] - (0) if Ok
*/
int alumno_findAlumnoById(Alumno* pArrayList, int len, int* pIndex, int id)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				if(pArrayList[i].id == id) // Estaba poniendo pArrayList[id].id == id, ten�a que poner en vez de [id] era [i]
				{
					*pIndex = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Modifies the data of an alumno only if the index is loaded
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param index int Receives the index to which it will be assigned after modifications
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_modifyAlumno(Alumno* pArrayList, int len, int index)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if
	(
	utn_getName("\nName of alumno:\n","Error, please type a correct name.\n",bufferAlumno.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferAlumno, �por qu� ac� no y en las otras s� el &?
		&&
	utn_getName("\nLast name of alumno:\n","Error, please type a correct last name.\n",bufferAlumno.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferAlumno, �por qu� ac� no y en las otras s� el &?
		&&
	utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferAlumno.salary,2, 0, 999999)==0
		&&
	utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferAlumno.sector, 2, 0, 999999)==0
	)
	{
		bufferAlumno.id = pArrayList[index].id;
		pArrayList[index] = bufferAlumno;
		pArrayList[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/** \brief Prints the content of alumnos array
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \return int Return (-1) if Error [Invalid length or NULL pointer received or alumno not found] - (0) if Ok
*
*/
int alumno_printAlumnos(Alumno* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				printf("Name: %s - Last name: %s - Salary: %f - Sector: %d - ID: %d\n\n", pArrayList[i].name, pArrayList[i].lastName, pArrayList[i].salary, pArrayList[i].sector, pArrayList[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Sort the elements in the array of alumnos, the argument order indicate UP or DOWN order*
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int alumno_sortAlumnos(Alumno* pArrayList, int len, int order)
{
	int sort;
	if(order == 1)
	{
		sort = 1;
	}
	else if(order == 0)
	{
		sort = -1;
	}

	int retorno = -1;
	int i;
	int newLen;
	int flagSwap;
	Alumno bufferAlumno;
	if(pArrayList != NULL && len > 0)
	{
		newLen = len -1;
		do
		{
			flagSwap = 0;
			for(i=0;i<newLen;i++)
			{
				if(pArrayList[i+1].isEmpty == 0)
				{

					if(compareElements(pArrayList[i], pArrayList[i+1], order, sort))
					{
						flagSwap = 1;
						bufferAlumno=pArrayList[i];
						pArrayList[i]=pArrayList[i+1];
						pArrayList[i+1]=bufferAlumno;
					}

				}
			}
			newLen--;
			retorno=0;
		}while(flagSwap);
	}
	return retorno;
}

/** \brief Compare the elements of one alumno with the next
* \param currentAlumno Alumno indicates the first alumno to compare
* \param nextAlumno Alumno indicates the next alumno to compare
* \param order int [1] indicate UP - [0] indicate DOWN
* \param sort int indicate the order of lastName
* \return int Return (1) if Ok, (0) if Error
**/
static int compareElements(Alumno currentAlumno, Alumno nextAlumno, int order, int sort)
{
	if(strcmp(currentAlumno.lastName, nextAlumno.lastName) == sort)
	{
		return 1;
	}
	else if(strcmp(currentAlumno.lastName, nextAlumno.lastName) == 0)
	{
		if(order)
		{
			if(currentAlumno.sector > nextAlumno.sector)
			{
				return 1;
			}
			else
			{
			return 0;
			}
		}
		else
		{
			if(currentAlumno.sector < nextAlumno.sector)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
	return 0;
	}
}

/** \brief Calculate the total and average salary, and how many alumnos have a salary greater than average
* \param pArrayList Alumno* Pointer to array of alumnos
* \param len int Array lenght
* \param pTotalSalary float* Pointer to the total salary
* \param pAveragesalary float* Pointer to the average salary
* \param pGreaterThanAverage int* Pointer to the alumnos that have a greater salary than average
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int alumno_calculateTotalAndAverageSalary(Alumno* pArrayList, int len, float* pTotalSalary, float* pAverageSalary, int *pGreaterThanAverage)
{
	int i;
	int retorno = -1;
	int counter = 0;
	int aboveAverageCounter = 0;
	int salaryAcumulator = 0;

	if(pArrayList != NULL && pTotalSalary != NULL && pAverageSalary != NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				salaryAcumulator += pArrayList[i].salary;
				counter++;
			}
		}
		*pTotalSalary = salaryAcumulator;
		*pAverageSalary = (float)salaryAcumulator / counter;

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				if(pArrayList[i].salary > *pAverageSalary)
				{
					aboveAverageCounter++;
				}
			}
		}
		*pGreaterThanAverage = aboveAverageCounter;
		printf("Average wages: %f - Total wages: %f - Quantity of alumnos that are above the average wage: %d\n",*pAverageSalary,*pTotalSalary,*pGreaterThanAverage);
		retorno = 0;
	}
return retorno;
}

static int generateNewId(void)
{
	static int id=0;
	if(!IdsEmpty)
	{
		int aux = returnId();
		return aux;
	}
	else
	{
		id=id+1;
		return id;
	}
}

static int releaseId(int idToRelease)
{
	IdsEmpty = FALSE;
	freeIds[len] = idToRelease;
	len++;
	return 1;
}

int returnId()
{
	int aux;
	if(1 <= freeIds[0] && freeIds[0] <= QTY_ALUMNOS)
	{
		aux = freeIds[0];
		if(1 <= freeIds[0] && freeIds[0] <= QTY_ALUMNOS)
		{
			freeIds[0] = freeIds[1];
		}
		else
		{
			IdsEmpty = TRUE;
		}
	}
	return aux;

}
