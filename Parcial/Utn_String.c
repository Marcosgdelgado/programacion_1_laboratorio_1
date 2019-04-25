#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "Utn_String.h"

int validarLetra (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
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

int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    char arrayAuxiliar[20];
    while(intentos>0)
    {
        printf(pMsg);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
        //__fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && validarLetra(arrayAuxiliar)==0)
        {
            strncpy(pResult,arrayAuxiliar,max);

            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        intentos--;
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
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
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

/*int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos)
{
    char bufferStr[4000];

    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr) - 1] = '\0';

    // validar
    strncpy(pResultado,bufferStr,maximo);

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
}*/
