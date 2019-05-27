#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar fantasma
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idMusico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
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
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID, Orquesta arrayOrquesta[], int sizeOrq, Instrumento arrayInstrumento[], int sizeIns)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int auxInstrumento;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idMusico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nALTA MUSICO\n\nIngrese nombre musico:\n ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("\nIngrese apellido musico:\n ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            utn_getSignedInt("\nIngrese edad: (18-90)\n","\nError",1,sizeof(int),18,90,2,&array[posicion].edadMusico);
            system("cls");
            orquesta_listar(arrayOrquesta,sizeOrq);
            utn_getUnsignedInt("\nIngrese ID de orquesta:\n","Error",1,sizeof(int),1,1000,3,&array[posicion].idOrquesta);
            if(orquesta_buscarID(arrayOrquesta,sizeOrq,array[posicion].idOrquesta,&posicion)==-1)
                {
                    printf("\nNo existe este ID\n");
                }
                else
                    {
                        array[posicion].idOrquesta;
                    }
            system("cls");
            instrumento_listar(arrayInstrumento, sizeIns);
            utn_getUnsignedInt("\nIngrese ID instrumento:\n","Error",1, sizeof(int),1,1000,3,&array[posicion].idInstrumento);
            if(instrumento_buscarID(arrayInstrumento,sizeIns,array[posicion].idInstrumento,&posicion)==-1)
                {
                    printf("\nNo existe este ID\n");
                }
                else
                    {
                        array[posicion].idInstrumento;
                    }

            retorno=0;
        }
                printf("ALTA OK");
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray, int size)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
//        musico_listar(array,size,arrayInstrumento, sizeIns);
        utn_getSignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idMusico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
//            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}
    int musico_bajaOrquesta(Musico array[], int size,int idOrquesta)
    {

    }
//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idMusico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idMusico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
//                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[],int sizeOrq)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    int i;
    int idOrquesta;                                                                                   //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {

        for(i=0;i<sizeArray;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
                {
                printf("\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n",
                       array[i].idMusico,array[i].varString,array[i].varLongString);
                }
        }

        utn_getSignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta

                utn_getChar("\nModificar: \nA-Edad\n B- Orquesta\n S(salir)\n","\nError\n",'a','z',1,&opcion);
                switch(toupper(opcion))
                {
                    case 'A':
                        utn_getSignedInt("Modificar edad:\n","\nError",1,sizeof(int),18,90,1,&array[posicion].edadMusico);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        orquesta_listar(arrayOrquesta,sizeOrq);
                        utn_getUnsignedInt("\Modificar ID:\n","Error",1,sizeof(int),1,1000,3,&array[posicion].idOrquesta);
                if(orquesta_buscarID(arrayOrquesta,sizeOrq,array[posicion].idOrquesta,&posicion)==-1)
                {
                    printf("\n No existe este ID\n");
                }
                else
                    {
                        array[posicion].idOrquesta=idOrquesta;
                    }

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
/** \brief Ordena por campo XXXXX los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico array[],int size)                              //cambiar fantasma
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];                               //cambiar campo varString
    int bufferId;
    int bufferIsEmpty;

    int bufferInt;                                              //cambiar buffer int
//    float bufferFloat;                                          //cambiar buffer varFloat
    char bufferLongString[TEXT_SIZE];                           //cambiar campo varLongString

    if(array!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,array[i].varString);                      //cambiar campo varString
            bufferId=array[i].idMusico;                                   //cambiar campo id
            bufferIsEmpty=array[i].isEmpty;

            bufferInt=array[i].varInt;                                //cambiar campo varInt
//            bufferFloat=array[i].varFloat;                            //cambiar campo varFloat
            strcpy(bufferLongString,array[i].varLongString);          //cambiar campo varLongString


            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,array[j].varString)<0)         //cambiar campo varString                 //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                                                               //buffer < campo ascendente   buffer > campo descendente
                strcpy(array[j + 1].varString,array[j].varString);          //cambiar campo varString
                array[j + 1].idMusico=array[j].idMusico;                                //cambiar campo id
                array[j + 1].isEmpty=array[j].isEmpty;

                array[j + 1].varInt=array[j].varInt;                        //cambiar campo varInt
 //               array[j + 1].varFloat=array[j].varFloat;                    //cambiar campo varFloat
                strcpy(array[j + 1].varLongString,array[j].varLongString);  //cambiar campo varLongString

                j--;
            }
            strcpy(array[j + 1].varString,bufferString);                     //cambiar campo varString
            array[j + 1].idMusico=bufferId;                                        //cambiar campo id
            array[j + 1].isEmpty=bufferIsEmpty;

            array[j + 1].varInt=bufferInt;                                                        //cambiar campo varInt
//            array[j + 1].varFloat=bufferFloat;                                                    //cambiar campo varFloat
            strcpy(array[j + 1].varLongString,bufferLongString);                                  //cambiar campo varLongString
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size, Instrumento arrayInstrumento[], int sizeIns)                      //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {

                        printf("\n ID: %d\n NOMBRE: %s\n APELLIDO: %s\n EDAD: %d\n Nombre de instrumento: %d\nORQUESTA: %d\n",
                       array[i].idMusico,array[i].varString,array[i].varLongString,array[i].edadMusico,array[i].idInstrumento, array[i].idOrquesta);
            }
        }
        retorno=0;
    }
    return retorno;
}

void harcodearMusicos(Musico array[],int size, int* contadorID)
{
        int i;
    char apellidos[][20]= {"Amus1","Amus2","Amus3","Amus4","Amus5","Amus6"};
    char nombres[][20]={"Mus1","Mus2","Mus3","Mus4","Mus5","Mus6"};
    int edad[]={30,20,25,27,22,35};
    int idOrq[]={1,2,4,4,1,3};
    int idIns[]={2,4,2,1,3,4};

    for(i=0; i<size; i++)
    {
        (*contadorID)++;
        array[i].idMusico= *contadorID;
        strcpy(array[i].varString,nombres[i]);
        strcpy(array[i].varLongString,apellidos[i]);
        array[i].edadMusico=edad[i];
        array[i].idInstrumento= idIns[i];
        array[i].idOrquesta= idOrq[i];
        array[i].isEmpty=0;
    }

}
