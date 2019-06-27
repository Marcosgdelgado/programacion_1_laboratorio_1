#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "LinkedList.h"

//void myPause(void)
//{
//    printf("...");
//    getchar();
//}

void clrscr(void)
{
    system("@cls||clear");
}

int utn_getString(  char *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attemps)
{
    int ret=-1;
    char bufferStr[4096];
    while(attemps>0)
    {
        printf(pMsg);
        fgets(bufferStr,sizeof(bufferStr),stdin);
        bufferStr[strlen(bufferStr)-1] = '\0';
        if( pResult != NULL &&
            strlen(bufferStr) >= min &&
            strlen(bufferStr) <= max)
        {
            strncpy(pResult,bufferStr,max);
            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        attemps--;
    }

    return ret;
}

int utn_isValidInt (char* string)
{
    int ret = 1;
    int i=0;
    if(string!=NULL)
    {
        if(string[i] == '-')
        {
            i++;
        }
        for(;string[i] != '\0';i++)
        {
            if(string[i] < '0' || string[i] > '9')
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_isValidFloat(char* string)
{
    int dotCounter=0;
    int singCounter=0;
    int ret=1;
    int i=0;
    if(string!=NULL)
    {
        for(;string[i] != '\0';i++)
        {
            if(string[i] == '-')
            {
                i++;
            }
            if(string[i]=='.')
            {
                if(singCounter>0&&i==1)
                {
                    ret=0;
                    break;
                }
                dotCounter++;
                i++;
            }
            if(((string[i]<'0' || string[i]>'9') && string[i]!='.') || dotCounter>1)
            {
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int utn_isValidName (char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalpha(string[i]) && string[i] != ' ')
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_isValidAddress (char* string)
{
    int ret=1;
    int i=0;
    for(;string[i] != '\0';i++)
    {
        if(!isalnum(string[i]))
        {
            ret=0;
            break;
        }
    }
    return ret;
}

int utn_getInt( int *pResult,
                char *pMsg,
                char *pMsgError,
                int min,
                int max,
                int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    int bufferInt;
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,1,7,10) &&
                utn_isValidInt(bufferStr))
            {
                bufferInt = atoi(bufferStr);
                if(bufferInt >= min && bufferInt <= max)
                {
                    ret = 0;
                    *pResult = bufferInt;
                    break;
                }
                else
                {
                    printf("%s",pMsgError);
                }
            }
        }
        attempts--;
    }
    return ret;
}

int utn_getFloat(   float *pResult,
                    char *pMsg,
                    char *pMsgError,
                    int min,
                    int max,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    float bufferFloat;
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,1,7,10) &&
                utn_isValidFloat(bufferStr))
            {
                bufferFloat = atoi(bufferStr);
                if(bufferFloat >= min && bufferFloat <= max)
                {
                    ret = 0;
                    *pResult = bufferFloat;
                    break;
                }
                else
                {
                    printf("%s",pMsgError);
                }
            }
        }
        attempts--;
    }
    return ret;
}

int utn_getName(    char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,minChars,maxChars,1) &&
                utn_isValidName(bufferStr)&&strlen(bufferStr)<=len)
            {
                strncpy(pResult,bufferStr,len);
                ret=0;
                break;
            }
        }
        attempts--;
    }
    return ret;
}

int utn_getAddress( char *pResult,
                    int len,
                    char *pMsg,
                    char *pMsgError,
                    int minChars,
                    int maxChars,
                    int attempts)
{
    int ret = -1;
    char bufferStr[4096];
    while(attempts>0)
    {
        if(pResult != NULL)
        {
            if(!utn_getString(bufferStr,pMsg,pMsgError,minChars,maxChars,1) &&
                utn_isValidAddress(bufferStr)&&strlen(bufferStr)<=len)
            {
                strncpy(pResult,bufferStr,len);
                ret=0;
                break;
            }
        }
        attempts--;
    }
    return ret;
}
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14; //con guiones 13 elementos
    int minSize=11;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidCUIT(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return retorno;
}
