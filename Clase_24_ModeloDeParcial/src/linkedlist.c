/*
 * linkedlist.c
 *
 *  Created on: 17 nov. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = ERROR;

	if (this != NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                       (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pAuxNode = NULL;
	int i;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pAuxNode = this->pFirstNode; //indice 0
		for (i = 0; i < nodeIndex; i++)
		{
			pAuxNode = pAuxNode->pNextNode;
		}
	}
	return pAuxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
 {
	int returnAux = ERROR;
	Node* newNode;
	Node* prevNode;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		newNode = (Node*) malloc(sizeof(Node));
		if (newNode != NULL)
		{
			newNode->pElement = pElement;
			if (nodeIndex == 0) //si es el primer nodo
			{
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode;
			} else {
				prevNode = getNode(this, nodeIndex - 1); //obtengo el nodo anterior
				if (prevNode != NULL)
				{
					newNode->pNextNode = prevNode->pNextNode; //me guardo el next node en el nuevo
					prevNode->pNextNode = newNode; //pNextNode = ESTE NODO
				}
			}
			this->size++; //INCREMENTO
			returnAux = SUCCESS;
		}
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = ERROR;
	if (this != NULL)
	{
		returnAux = addNode(this, ll_len(this), pElement); //Agrega un nodo al final // retorna 0 si ok
	}
	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                          (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	Node* pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNodeAux = getNode(this, index);
		if (pNodeAux != NULL)
		{
			returnAux = pNodeAux->pElement;
		}
	}
	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = ERROR;
	Node* pNodeAux;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNodeAux = getNode(this, index);
		if (pNodeAux != NULL)
		{
			pNodeAux->pElement = pElement;
			returnAux = SUCCESS;
		}
	}
	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = ERROR;
	Node* pNodeAux;
	Node* pPrevNode;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNodeAux = getNode(this, index);
		if (pNodeAux != NULL)
		{
			if (index == 0)
			{
				this->pFirstNode = pNodeAux->pNextNode;
			} else {
				pPrevNode = getNode(this, index - 1);
				if (pPrevNode != NULL)
				{
					pPrevNode->pNextNode = pNodeAux->pNextNode;
				}
			}
			free(pNodeAux);
			this->size--;
			returnAux = SUCCESS;
		}
	}
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = ERROR;

	if (this != NULL)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			if (ll_remove(this, i) == 0)
			{
				returnAux = SUCCESS;
			} else {
				returnAux = ERROR;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = ERROR;

	if (this != NULL)
	{
		if (ll_clear(this) == 0)
		{
			free(this);
			returnAux = SUCCESS;
		}
	}
	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = ERROR;
	int i;
	void* pElementAux;

	if (this != NULL)
	{
		for (i = 0; i < ll_len(this); i++)
		{
			pElementAux = ll_get(this, i);
			if (pElementAux == pElement)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 0) Si la lista NO esta vacia
 *                      ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux = ERROR;

	if (this != NULL)
	{
		if (ll_len(this) == 0) //si esta vacia
		{
			returnAux = TRUE;
		} else {
			returnAux = FALSE;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = ERROR;

	if (this != NULL && index >= 0 && index <= ll_len(this))
	{
		returnAux = addNode(this, index, pElement);//retorna 0 si ok
	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                          (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* returnAux = NULL;
	void* pElementAux;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pElementAux = ll_get(this, index);
		if (pElementAux != NULL)
		{
			if (ll_remove(this, index) == SUCCESS)
			{
				returnAux = pElementAux;
			}
		}
	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 *                      ( 1) Si contiene el elemento
 *                      ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = ERROR;

	if (this != NULL)
	{
		if (ll_indexOf(this, pElement) != ERROR) //si indexOf me retorna un valor positivo es que encuentra un indice osea el elemento existe
		{
			returnAux = TRUE; //contiene el elemento
		} else {
			returnAux = FALSE; //no contiene el elemento
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 *          estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 *                      ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 *                      ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = ERROR;
	void* pElement;
	int i;

	if (this != NULL && this2 != NULL)
	{
		returnAux = TRUE; // si no entra al if, retorna 1, no encontro ningun elemento que no estuviera en la lista
		for (i = 0; i < ll_len(this2); i++)
		{
			pElement = ll_get(this2, i);
			if (pElement != NULL && ll_contains(this, pElement) == FALSE) //si el elemento no esta
			{
				returnAux = FALSE;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 *                              o (si el indice from es menor a 0 o mayor al len de la lista)
 *                              o (si el indice to es menor o igual a from o mayor al len de la lista)
 *                       (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	int i;
	void* pElement;

	if (this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this) && from < to)
	{
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL)
		{
			for (i = from; i < to; i++)
			{
				pElement = ll_get(this, i);
				if (pElement != NULL)
				{
					ll_add(cloneArray, pElement);
				}
			}
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 *                              (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;

	if (this != NULL)
	{
		cloneArray = ll_subList(this, 0, ll_len(this));
	}
	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = ERROR;
	int i;
	int disorderedState = TRUE;
	int criteria;
	void* pElement;
	void* pElement2;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		while (disorderedState)
		{
			disorderedState = FALSE;
			for (i = 0; i < ll_len(this) - 1; i++)
			{
				pElement = ll_get(this, i);
				pElement2 = ll_get(this, i + 1);
				criteria = pFunc(pElement, pElement2);
				if ((order == 1 && criteria == 1)
						|| (order == 0 && criteria == -1))
				{
					ll_set(this, i, pElement2);
					ll_set(this, i + 1, pElement);
					disorderedState = TRUE;
				}
			}
		}
		returnAux = SUCCESS;
	}
	return returnAux;
}


/*******************************************/

int ll_map(LinkedList* this, Function pFunc)
{
	int returnAux = ERROR;
	int i;
	void* pElemento;

	if (this != NULL && pFunc != NULL)
	{
		for (i = 0; i < ll_len(this); i++)
		{
			pElemento = ll_get(this, i);
			if(pElemento != NULL)
				pFunc(pElemento);
		}
		returnAux = SUCCESS;
	}
	return returnAux;
}

int ll_filter(LinkedList * this, Function pFunc)
{
	int returnAux = ERROR;
	void* pAux;
	int criteria;
	int i;

	if (this != NULL && pFunc != NULL)
	{
		for (i = ll_len(this) - 1; i >= 0; i--)
		{
			pAux = ll_get(this, i);
			if (pAux != NULL)
			{
				criteria = pFunc(pAux);
				if (criteria == FALSE)
				{
					if (ll_remove(this, i))
					{
						returnAux = SUCCESS;
					}
				}
			}
		}
	}
	return returnAux;
}

int ll_reduceInt(LinkedList* this, Function pFunc)
{
	void *pAux;
	int i;
	int acum = 0;

	if (this != NULL && pFunc != NULL)
	{
		for (i = 0; i < ll_len(this); i++)
		{
			pAux = ll_get(this, i);
			if (pAux != NULL)
			{
				acum = acum + pFunc(pAux);
			}
		}
	}
	return acum;
}

float ll_reduceFloat(LinkedList* this, FunctionReduceFloat pFunc)
{
	void *pAux;
	int i;
	float acum = 0;

	if (this != NULL && pFunc != NULL)
	{
		for (i = 0; i < ll_len(this); i++)
		{
			pAux = ll_get(this, i);
			if (pAux != NULL)
			{
				acum = acum + pFunc(pAux);
			}
		}
	}
	return acum;
}
