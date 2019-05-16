#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libro.h"
#include "autor.h"
 //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libro Array of libro
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libro_Inicializar(Libro arrayLibro[], int size)                                    //cambiar libro
{
    int retorno=-1;
    if(arrayLibro!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            arrayLibro[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un arrayLibro
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param posicion int* Puntero a la posicion del arrayLibro donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libro_buscarEmpty(Libro arrayLibro[], int size, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(arrayLibro!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(arrayLibro[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un arrayLibro y devuelve la posicion en que se encuentra
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param posicion int* Puntero a la posicion del arrayLibro donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarID(Libro arrayLibro[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(arrayLibro!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayLibro[i].isEmpty==1)
                continue;
            else if(arrayLibro[i].idLibro==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un arrayLibro y devuelve la posicion en que se encuentra
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param posicion int* Puntero a la posicion del arrayLibro donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int libro_buscarInt(Libro arrayLibro[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(arrayLibro!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayLibro[i].isEmpty==1)
                continue;
            else if(arrayLibro[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
*/
//String
/** \brief Busca un string en un arrayLibro
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param posicion int* Puntero a la posicion del arrayLibro donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int libro_buscarString(Libro arrayLibro[], int size, char* valorBuscado, int* indice)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(arrayLibro!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayLibro[i].isEmpty==1)
                continue;
            else if(strcmp(arrayLibro[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}*/

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un arrayLibro
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libro_alta(Libro arrayLibro[],Autor arrayAutor[], int size, int* contadorID, int sizeAutor)                          //cambiar libro
{
    int retorno=-1;
    int posicion;
    int posaux;
    if(arrayLibro!=NULL && size>0 && contadorID!=NULL)
    {
        if(libro_buscarEmpty(arrayLibro,size,&posicion)==-1)                          //cambiar libro
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayLibro[posicion].idLibro=*contadorID;                                                       //campo ID
            arrayLibro[posicion].isEmpty=0;
//            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&arrayLibro[posicion].varInt);           //mensaje + cambiar campo varInt
//            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&arrayLibro[posicion].varFloat);             //mensaje + cambiar campo varFloat
//            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,arrayLibro[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("Titulo:\n ","\nError",1,TEXT_SIZE,1,arrayLibro[posicion].varLongString);                                                                                                                //mensaje + cambiar campo varLongString
            printf("\n ID Libro: %d\n Titulo: %s\n",
                   arrayLibro[posicion].idLibro,arrayLibro[posicion].varLongString);
            autor_listar(arrayAutor,sizeAutor);
            arrayLibro[posaux].idAutor= utn_getSignedInt("\n\nSeleccione ID autor:","ERROR",1,sizeAutor,1,sizeAutor,3,arrayAutor);


            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del arrayLibro por ID
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_baja(Libro arrayLibro[], int sizeArray)                                      //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;
    if(arrayLibro!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libro_buscarID(arrayLibro,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            arrayLibro[posicion].isEmpty=1;
            arrayLibro[posicion].idLibro=0;                                                                   //cambiar campo id
 //           arrayLibro[posicion].varInt=0;                                                               //cambiar campo varInt
 //           arrayLibro[posicion].varFloat=0;                                                             //cambiar campo varFloat
 //           strcpy(arrayLibro[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(arrayLibro[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del arrayLibro que contengan el valor buscado
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \param valorBuscado int Valor a buscar en el arrayLibro
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_bajaValorRepetidoInt(Libro arrayLibro[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(arrayLibro!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(arrayLibro[i].idLibro==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                arrayLibro[i].isEmpty=1;
                arrayLibro[i].idLibro=0;                                                                   //cambiar campo id
//                arrayLibro[i].varInt=0;                                                               //cambiar campo varInt
 //               arrayLibro[i].varFloat=0;                                                             //cambiar campo varFloat
  //              strcpy(arrayLibro[i].varString,"");                                                   //cambiar campo varString
                strcpy(arrayLibro[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libro_modificar(Libro arrayLibro[], int sizeArray)                                //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(arrayLibro!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libro_buscarID(arrayLibro,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       posicion, arrayLibro[posicion].idLibro,arrayLibro[posicion].varLongString);
                utn_getChar("\nModificar:D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
 /*                   case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&arrayLibro[posicion].varInt);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&arrayLibro[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                   case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,arrayLibro[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
*/                     case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,arrayLibro[posicion].varLongString);             //mensaje + cambiar campo varLongString
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
/** \brief Ordena por campo XXXXX los elementos de un arrayLibro
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libro_ordenarPorString(Libro arrayLibro[],int size)                              //cambiar libro
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(arrayLibro!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
//            strcpy(bufferString,arrayLibro[i].varString);                      //cambiar campo varString
            bufferId=arrayLibro[i].idLibro;                                   //cambiar campo id
            bufferIsEmpty=arrayLibro[i].isEmpty;

//            bufferInt=arrayLibro[i].varInt;                                //cambiar campo varInt
//            bufferFloat=arrayLibro[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,arrayLibro[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
           // while ((j >= 0) && strcmp(bufferString,arrayLibro[j].varLongString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<arrayLibro[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
//                strcpy(arrayLibro[j + 1].varString,arrayLibro[j].varString);          //cambiar campo varString
                arrayLibro[j + 1].idLibro=arrayLibro[j].idLibro;                                //cambiar campo id
                arrayLibro[j + 1].isEmpty=arrayLibro[j].isEmpty;

                //arrayLibro[j + 1].varInt=arrayLibro[j].varInt;                        //cambiar campo varInt
               // arrayLibro[j + 1].varFloat=arrayLibro[j].varFloat;                    //cambiar campo varFloat
                strcpy(arrayLibro[j + 1].varLongString,arrayLibro[j].varLongString);  //cambiar campo varLongString

                j--;
            }
//            strcpy(arrayLibro[j + 1].varString,bufferString);                     //cambiar campo varString
            arrayLibro[j + 1].idLibro=bufferId;                                        //cambiar campo id
            arrayLibro[j + 1].isEmpty=bufferIsEmpty;

//            arrayLibro[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
//            arrayLibro[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(arrayLibro[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un arrayLibro
* \param arrayLibro libro Array de libro
* \param size int Tamaño del arrayLibro
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libro_listar(Libro arrayLibro[], int size)                      //cambiar libro
{
    int retorno=-1;
    int i;
    if(arrayLibro!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayLibro[i].isEmpty==1)
                continue;
            else
                printf("\n ID libro: %d\n Titulo: %s \n ID autor: %d\n",
                       arrayLibro[i].idLibro,arrayLibro[i].varLongString,arrayLibro[i].idAutor);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


