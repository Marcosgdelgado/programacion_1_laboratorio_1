#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString(char *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos)
{
    char bufferStr[4096];
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    //strncpy(resultado, "1234",maximo);

    return 0;
}
int isValidNumber(char* cadena)
{
   int retorno=1;
   int i=0;

   if(cadena[i]== '-')
    {
        i++;
    }
   for(;cadena[i]!='\0';i++)
   { //if(i==0 && cadena[i]<= '0' || cadena[i]>='9'){}
       if(cadena[i]<= '0' || cadena[i]>='9')
       {
        retorno = 0;
       break;
       }
   }
return retorno;
}

int getNumber(int *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos)
{
    int retorno =-1;
    char bufferStr[4096];
    int bufferInt;

    if(resultado!= NULL && reintentos >= 0)
    {   // " ! " niega
        if(!getString(bufferStr,msg,msgError,1,6,1)&& isValidNumber(bufferStr))
        {
                bufferInt = atoi(bufferStr);
                if(bufferInt>=minimo && bufferInt<=maximo)
                {
                        retorno=0;
                        *resultado=bufferInt;
                }
        }
    }
return retorno;
}
