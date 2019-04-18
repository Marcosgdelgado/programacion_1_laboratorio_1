#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LEN_LISTA    100

int Empleados_initArray(Empleado* pEmpleado,int limite)
{
    int retorno = -1;
    int i;
    if(pEmpleado != NULL && limite >= 0)
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado[i].isEmpty =1;
        }
    retorno = 0;
    }
    return retorno;
}
int Empleados_printDebugArray(Empleado* pEmpleado,int limite)
{
    int retorno = -1;
    int i;
    if(pEmpleado != NULL && limite >= 0)
    {
        for(i=0;i<limite;i++)
        {
           printf("\nID:%d-NOMBRE: %s",idEmpleado[i].pEmpleado);
        }
    }
    return retorno;
}
int Empleados_lugarLibre(Empleado* pEmpleado,int limite)
{
    int retorno = -1;
    int i;
    if(pEmpleado != NULL && limite >= 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty == 1)
            {
                retorno = i;
            }
        }
    }
    return retorno;
    return 0;
}
int Empleados_alta(Empleado* pEmpleado,int limite)
{
    return 0;
}
int Empleados_baja(Empleado* pEmpleado,int limite)
{
    return 0;
}
int Empleados_modificar(Empleado* pEmpleado,int limite)
{
    return 0;
}
int Empleados_ordenarNombre(Empleado* pEmpleado,int limite)
{
    return 0;
}

int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos)
{
    char bufferStr[20];

    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr) - 1] = '\0';
    // validar
    strncpy(pResultado,bufferStr,20);
    return 0;
}

int utn_isValidIntNumber(char* cadena)
{
    int i = 0;
    int ret = 1;

    if(cadena[i] == '-')
    {
        i++;
    }
    for(;cadena[i] != '\0'; i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            ret = 0;
            break;
        }

    }
    return ret;
}

int utn_getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos)
{
    int ret = -1;
    char bufferStr[4000];
    int bufferInt;

    if(pResultado != NULL &&
        reintentos >= 0) //FALTAN LOS DEMAS
    {
        if(!utn_getString(bufferStr,msg,msgError,1,6,1) &&
            utn_isValidIntNumber(bufferStr))// maximo y minimo van a estar determinados por la funcion principal
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                ret = 0;
            }
        }
    }

    return ret;
}

int buscarlibre(char lista[][20], int len,int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(lista[i][0]=='\0')
        {
        *pIndex=i;
        ret=0;
        break;
        }
    }
return ret;
}

int buscanombre(char* pNombre,char lista[][20],int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(pNombre, lista[i])==0)
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}
