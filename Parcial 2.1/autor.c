#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "autor.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array autor Array of autor
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int autor_Inicializar(Autor arrayAutor[], int sizeAutor)                                    //cambiar autor
{
    int retorno=-1;
    if(arrayAutor!= NULL && sizeAutor>0)
    {
        for(;sizeAutor>0;sizeAutor--)
        {
            arrayAutor[sizeAutor-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un arrayAutor
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param posicion int* Puntero a la posicion del arrayAutor donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int autor_buscarEmpty(Autor arrayAutor[], int sizeAutor, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(arrayAutor!= NULL && sizeAutor>=0 && posicion!=NULL)
    {
        for(i=0;i<sizeAutor;i++)
        {
            if(arrayAutor[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un arrayAutor y devuelve la posicion en que se encuentra
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param posicion int* Puntero a la posicion del arrayAutor donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarID(Autor arrayAutor[], int sizeAutor, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(arrayAutor!= NULL && sizeAutor>=0)
    {
        for(i=0;i<sizeAutor;i++)
        {
            if(arrayAutor[i].isEmpty==1)
                continue;
            else if(arrayAutor[i].idAutor==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un arrayAutor y devuelve la posicion en que se encuentra
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param posicion int* Puntero a la posicion del arrayAutor donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int autor_buscarInt(Autor arrayAutor[], int sizeAutor, int valorBuscado, int* posicion)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(arrayAutor!= NULL && sizeAutor>=0)
    {
        for(i=0;i<sizeAutor;i++)
        {
            if(arrayAutor[i].isEmpty==1)
                continue;
            else if(arrayAutor[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}*/

//String
/** \brief Busca un string en un arrayAutor
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param posicion int* Puntero a la posicion del arrayAutor donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int autor_buscarString(Autor arrayAutor[], int sizeAutor, char* valorBuscado, int* indice)                    //cambiar autor
{
    int retorno=-1;
    int i;
    if(arrayAutor!=NULL && sizeAutor>=0)
    {
        for(i=0;i<sizeAutor;i++)
        {
            if(arrayAutor[i].isEmpty==1)
                continue;
            else if(strcmp(arrayAutor[i].varNombre,valorBuscado)==0)                                        //cambiar campo varNombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un arrayAutor
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param contadorIDautor int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int autor_alta(Autor arrayAutor[], int sizeAutor, int* contadorIDautor)                          //cambiar autor
{
    int retorno=-1;
    int posicion;
    if(arrayAutor!=NULL && sizeAutor>0 && contadorIDautor!=NULL)
    {
        if(autor_buscarEmpty(arrayAutor,sizeAutor,&posicion)==-1)                          //cambiar autor
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorIDautor)++;
            arrayAutor[posicion].idAutor=*contadorIDautor;                                                       //campo ID
            arrayAutor[posicion].isEmpty=0;
            //utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&arrayAutor[posicion].varInt);           //mensaje + cambiar campo varInt
            //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&arrayAutor[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("Nombre:\n ","\nError",1,TEXT_SIZE,1,arrayAutor[posicion].varNombre);                      //mensaje + cambiar campo varNombre
            utn_getTexto("Apellido:\n ","\nError",1,TEXT_SIZE,1,arrayAutor[posicion].varApellido);                 //mensaje + cambiar campo varApellido
            printf("\n ID: %d\n Nombre: %s\n apellido: %s\n",
                    arrayAutor[posicion].idAutor,arrayAutor[posicion].varNombre,arrayAutor[posicion].varApellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del arrayAutor por ID
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_baja(Autor arrayAutor[], int sizeArray)                                      //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;
    if(arrayAutor!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(autor_buscarID(arrayAutor,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            arrayAutor[posicion].isEmpty=1;
            arrayAutor[posicion].idAutor=0;                                                                   //cambiar campo id
           // arrayAutor[posicion].varInt=0;                                                               //cambiar campo varInt
            //arrayAutor[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(arrayAutor[posicion].varNombre,"");                                                   //cambiar campo varNombre
            strcpy(arrayAutor[posicion].varApellido,"");                                               //cambiar campo varApellido
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del arrayAutor que contengan el valor buscado
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \param valorBuscado int Valor a buscar en el arrayAutor
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int autor_bajaValorRepetidoInt(Autor arrayAutor[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(arrayAutor!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(arrayAutor[i].idAutor==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                arrayAutor[i].isEmpty=1;
                arrayAutor[i].idAutor=0;                                                                   //cambiar campo id
               // arrayAutor[i].varInt=0;                                                               //cambiar campo varInt
                //arrayAutor[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(arrayAutor[i].varNombre,"");                                                   //cambiar campo varNombre
                strcpy(arrayAutor[i].varApellido,"");                                               //cambiar campo varApellido
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int autor_modificar(Autor arrayAutor[], int sizeArray)                                //cambiar autor
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(arrayAutor!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(autor_buscarID(arrayAutor,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n",
                       posicion, arrayAutor[posicion].idAutor,arrayAutor[posicion].varNombre,arrayAutor[posicion].varApellido);
                utn_getChar("\nModificar:\nA- Modificar nombre\nB- Modificar apellido\n S(salir)","\nError",'A','Z',1,&opcion);
                switch(toupper(opcion))
                {
//                   case 'A':
//                       utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&arrayAutor[posicion].varInt);           //mensaje + cambiar campo varInt
//                       break;
//                   case 'B':
//                      utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&arrayAutor[posicion].varFloat);             //mensaje + cambiar campo varFloat
//                        break;
                    case 'A':
                        utn_getName("\nIngrese nuevo nombre:\n","\nError",1,TEXT_SIZE,1,arrayAutor[posicion].varNombre);                      //mensaje + cambiar campo varNombre
                        break;
                    case 'B':
                        utn_getTexto("\nIngrese nuevo apellido:\n","\nError",1,TEXT_SIZE,1,arrayAutor[posicion].varApellido);             //mensaje + cambiar campo varApellido
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un arrayAutor
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int autor_ordenarPorString(Autor arrayAutor[],int sizeAutor)                              //cambiar autor
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varNombre
    int bufferId;
    int bufferIsEmpty;

//    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varApellido

    if(arrayAutor!=NULL && sizeAutor>=0)
    {
        for (i = 1; i < sizeAutor; i++)
        {
            strcpy(bufferString,arrayAutor[i].varNombre);                      //cambiar campo varNombre
            bufferId=arrayAutor[i].idAutor;                                   //cambiar campo id
            bufferIsEmpty=arrayAutor[i].isEmpty;

//            bufferInt=arrayAutor[i].varInt;                                //cambiar campo varInt
 //           bufferFloat=arrayAutor[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,arrayAutor[i].varApellido);          //cambiar campo varApellido


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,arrayAutor[j].varNombre)<0)         //cambiar campo varNombre                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<arrayAutor[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(arrayAutor[j + 1].varNombre,arrayAutor[j].varNombre);          //cambiar campo varNombre
                arrayAutor[j + 1].idAutor=arrayAutor[j].idAutor;                                //cambiar campo id
                arrayAutor[j + 1].isEmpty=arrayAutor[j].isEmpty;

//                arrayAutor[j + 1].varInt=arrayAutor[j].varInt;                        //cambiar campo varInt
//               arrayAutor[j + 1].varFloat=arrayAutor[j].varFloat;                    //cambiar campo varFloat
                strcpy(arrayAutor[j + 1].varApellido,arrayAutor[j].varApellido);  //cambiar campo varApellido

                j--;
            }
            strcpy(arrayAutor[j + 1].varNombre,bufferString);                     //cambiar campo varNombre
            arrayAutor[j + 1].idAutor=bufferId;                                        //cambiar campo id
            arrayAutor[j + 1].isEmpty=bufferIsEmpty;

//            arrayAutor[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
 //           arrayAutor[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(arrayAutor[j + 1].varApellido,bufferLongString);                                  //cambiar campo varApellido
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un arrayAutor
* \param arrayAutor autor Array de autor
* \param sizeAutor int Tamaño del arrayAutor
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int autor_listar(Autor arrayAutor[], int sizeAutor)                      //cambiar autor
{
    int retorno=-1;
    int i;
    if(arrayAutor!=NULL && sizeAutor>=0)
    {
        for(i=0;i<sizeAutor;i++)
        {
            if(arrayAutor[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n Nombre: %s\n Apellido: %s",
                       arrayAutor[i].idAutor,arrayAutor[i].varNombre,arrayAutor[i].varApellido);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


