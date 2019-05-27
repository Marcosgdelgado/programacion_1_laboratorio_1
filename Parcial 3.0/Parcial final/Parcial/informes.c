#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h" //cambiar por nombre entidad

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarPorCriterio(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayMusico!=NULL && sizeMusico>=0 && arrayOrquesta!=NULL && arrayOrquesta>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeMusico;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayMusico[i].isEmpty==1 && strcmp(arrayMusico[i].varString,criterio)!=0)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            else
            {
                musico_buscarID(arrayOrquesta,arrayOrquesta,arrayMusico[i].idMusico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID Musico: %d\nID Orquesta: %d",
                       arrayMusico[i].idMusico,arrayOrquesta[j].idOrquesta);
            }
        }
        retorno=0;
    }
    return retorno;
}


int informar_OrquestaXmusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[], int sizeIns)
{
    int retorno=-1;
    int contador=0;
    int i;
    int j;

    if(arrayMusico!=NULL && sizeMusico>=0)
    {
        for(i=0;i<sizeMusico;i++)
        {
           if(arrayMusico[i].edadMusico > 30 && arrayMusico[i].isEmpty==0)
           {
               printf("\nID   Nombre  Apellido    EDAD  Instrumento     Orquesta\n %d   %s      %s          %d     %d\n", arrayMusico[i].idMusico, arrayMusico[i].varString,
                                                                                        arrayMusico[i].varLongString, arrayMusico[i].edadMusico,arrayMusico[i].idInstrumento,arrayMusico[i].idOrquesta);
           retorno = 0;
           }

        }
    }
    return retorno;
}


int informar_masMusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],int sizeOrquesta,Instrumento arrayInstrumento[], int sizeIns)
{
    int retorno=-1;
    int id;
    int i;
     if(arrayMusico!=NULL && sizeMusico>=0)
    {
            utn_getUnsignedInt("Ingrese ID","Error",1,sizeof(int),1,sizeMusico,3,&id);

    retorno =0;
    }
    return retorno;
}
int ListarxLugar(Orquesta arrayOrquesta[], int size)
{
    int retorno= -1;
    int i;
    char lugar[100];
    int posicion;

    orquesta_listar(arrayOrquesta,size);
    utn_getTexto("\nIngrese lugar:\n","Error!",1,100,2,lugar);

    for(i=0;i<size;i++)
    {
        if(arrayOrquesta[i].isEmpty==0)
        {
            if(!strcmp(arrayOrquesta[i].varLongString,lugar))
            {
                printf("\nIDOrquesta  Nombre    Tipo  Lugar\n %d       %s       %d     %s\n",
                        arrayOrquesta[i].idOrquesta,arrayOrquesta[i].varString,arrayOrquesta[i].tipoOrquesta,
                        arrayOrquesta[i].varLongString);
            }

        }
    }
    return retorno;
}
int listarXorquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta, Instrumento arrayInstrumento[], int sizeInstrumento)
{
    int retorno=-1;
    int auxId;
    int posicion;
    int i;
    char auxInstrumento;

    orquesta_listar(arrayOrquesta,sizeOrquesta);
    utn_getSignedInt("\nIngrese ID orquesta:\n","\nERROR!!\n",1,sizeof(int),1,sizeOrquesta,2,&auxId);
    if(orquesta_buscarID(arrayOrquesta,sizeOrquesta,auxId,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
    else
    {
       for(i=0;i<sizeMusico;i++)
       {
           if(arrayMusico[i].idOrquesta==auxId)
           {

               printf("\nMUSICO\nNombre: %s\nApellido: %s\nEdad: %d\nINSTRUMENTO\nNombre: %s\nTipo: ",
                   arrayMusico[i].varString,arrayMusico[i].varLongString,arrayMusico[i].edadMusico,auxInstrumento,arrayMusico[i].idInstrumento);
            switch(arrayMusico[i].idInstrumento)
            {
                case 1:
                printf("Cuerdas\n");
//                system("pause");
                break;
                case 2:
                printf("Viento-Madera\n");
//                system("pause");
                break;
                case 3:
                printf("Viento-Metal\n");
//                system("pause");
                break;
                case 4:
                printf("Percusion\n");
//                system("pause");
                break;

                default:
                    printf("Opcion incorrecta.\n");
            }
           }
       }
        retorno=0;
    }
   return retorno;
}

int imprimirCuerdas(Instrumento arrayInstrumento[],int sizeInstrumento,Musico arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int i;
    int j;
    for(i=0;i<sizeInstrumento;i++)
    {
        if(arrayInstrumento[i].tipoInstrumento==1)
        {
            for(j=0;j<sizeMusico;j++)
            {
                if(arrayInstrumento[i].idInstrumento==arrayMusico[j].idInstrumento)
                {
                    printf("\nMUSICO\nNombre: %s\nApellidos: %s\nEdad: %d\nINSTRUMENTO\nNombre: %s\nTipo:Cuerda\n",
                           arrayMusico[j].varString,arrayMusico[j].varLongString,
                           arrayMusico[j].edadMusico, arrayInstrumento[i].varString);
                }
            }

            retorno=0;
        }

    }

    return retorno;
}





