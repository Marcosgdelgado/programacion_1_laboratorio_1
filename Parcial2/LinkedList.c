#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
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
    int returnAux = -1;
    if(this!= NULL)
    {
        returnAux = this -> size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;

    int i;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        pNode = this->pFirstNode;
            for(i=0;i<nodeIndex;i++)
            {
                pNode = pNode->pNextNode;
            }

    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
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
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = malloc(sizeof(Node));
    Node* gNode= getNode(this,nodeIndex);
    Node* lastNode;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
         newNode->pElement = pElement;
//       if(gNode == NULL && nodeIndex == 0)
       if(gNode == NULL)
       {
           if(nodeIndex==0)
           {
               this->pFirstNode = newNode;
                returnAux =0;
            }else
            {
                lastNode=getNode(this,this->size-1);
                lastNode->pNextNode=newNode;
                returnAux=0;
            }
       }
       else
       {
           if(nodeIndex==0)
           {
               newNode->pNextNode=this->pFirstNode;
               this->pFirstNode=newNode;
                returnAux=0;
           }
           else
           {
               newNode->pNextNode = gNode->pNextNode;
               newNode->pElement=gNode->pElement;
               gNode->pNextNode=newNode;
               gNode->pElement=pElement;
               returnAux=0;
           }
       }
        this->size = ll_len(this)+1;
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
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
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this!=NULL)
    {
        addNode(this,len,pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node * gNode =getNode(this,index);
    if(this!=NULL)
    {
            if(this!=NULL && index>=0 && index<ll_len(this))
            {
                returnAux = gNode->pElement;
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
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* gNode= getNode(this,index);
    //if(this!=NULL)
    //{
        if(this!=NULL && index>=0 && index<ll_len(this))
        {
            gNode->pElement= pElement;
            returnAux=0;
        }
    //}
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* gNode = getNode(this,index);
    Node* auxFirst;
    Node* prevNode;
    Node* lastNode;
        if(this!=NULL && index>=0 && index<ll_len(this))
        {
            if(this->pFirstNode==NULL && index ==0)
            {
                returnAux=0;

            }else if (this->pFirstNode!=NULL && index==0)
            {
                auxFirst = this->pFirstNode;
                this->pFirstNode = auxFirst->pNextNode;
                free(auxFirst);
                this->size--;
                returnAux=0;


            }else //if(this->pFirstNode!=NULL && index<ll_len(this))
            {
                 prevNode=getNode(this,index-1);
                 prevNode->pNextNode=gNode->pNextNode;
                 free(gNode);
                 this->size--;
                returnAux=0;
            }
        }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
       {
            for(i=0;i<ll_len(this);i++)
                {
                    ll_remove(this,i);
                        returnAux=0;
                }
       }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        this->pFirstNode = NULL;
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* gNode;
       //if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
       if (this!=NULL)
       {
            for(i=0;i<ll_len(this);i++)
            {
               gNode = getNode(this,i);
                if(gNode-> pElement == pElement)
                {
                    returnAux = i;
                }

            }
       }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

        if (this!=NULL)
        {
            if(ll_len(this)== 0)
            {
                returnAux=1;
            }else
                {
                    returnAux=0;
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
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
        Node* aNode;
        if(this!=NULL && index>=0 && index<=ll_len(this))
        {
            aNode= addNode(this,index,pElement);
            returnAux=0;
        }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* gNode= getNode(this,index);
    Node* elemento;
    if(this!=NULL&& index && index>=0 && index<ll_len(this))
    {
        elemento->pElement= gNode->pElement;
        ll_remove(this,index);
        returnAux= elemento->pElement;

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

        if (this!=NULL)
        {
            if(ll_indexOf(this,pElement)>=0)
            {
                returnAux=1;
            }else
            {
                returnAux=0;
            }
        }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
        if(this!=NULL && this2!=NULL)
        {
            Node* pNode=NULL;
            returnAux=0;
                for(i=0;i<ll_len(this2);i++)
                {
                    pNode=getNode(this2,i);
                    returnAux=ll_contains(this,pNode->pElement);
                    if(returnAux==0)
                    {
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
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    if(this!=NULL)
    {
        if((from>=0 && from< ll_len(this))&& (to> from && to<=ll_len(this)))
        {
            cloneArray=ll_newLinkedList();
            Node* pNode= (Node*)malloc(sizeof(Node*));
            for(i=from;i<to; i++)
            {
                pNode=getNode(this,i);
                ll_add(cloneArray,pNode->pElement);
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
        if(this!=NULL)
        {
            cloneArray=ll_newLinkedList();
            cloneArray=ll_subList(this,0,ll_len(this));
        }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux;

    if(this != NULL && pFunc !=NULL && (order ==0 || order == 1))
    {
        for(int i=0;i<ll_len(this);i++)
        {
            for(int j=i+1;j<ll_len(this);j++)
            {
                if(order==1)
                {
                    if(pFunc(ll_get(this,i),ll_get(this,j))>0)
                    {
                       aux=ll_get(this,i);
                       ll_set(this,i, ll_get(this,j));
                       ll_set(this,j,aux);
                    }
                }
                else
                {
                    if(pFunc(ll_get(this,i),ll_get(this,j))<0)
                    {
                       aux=ll_get(this,i);
                       ll_set(this,i, ll_get(this,j));
                       ll_set(this,j,aux);
                    }
                }
            }
        }
            returnAux=0;
    }
    return returnAux;
}

int ll_map(LinkedList*  this, int (*pFunc)(void*))
{
    int retorno=-1;
    int i;
    void* auxElement;

    if(this!=NULL && pFunc!=NULL)
    {
        retorno=0;
        for(i=0;i<ll_len(this); i++)
        {
            auxElement=ll_get(this,i);
            if(auxElement!=NULL)
            {
                if(!pFunc(auxElement))
                {
                    retorno=1;
                }
            }
        }
    }
return retorno;
}

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* cloneArray= NULL;
    Node* auxNode;
    int i;
    if(this!=NULL && pFunc!=NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0; i<ll_len(this);i++)
        {
            auxNode=ll_get(this,i);
            if(!pFunc(auxNode))
            {
                ll_add(cloneArray, auxNode);
            }
        }
    }
    return cloneArray;
}
