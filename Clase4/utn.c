#include <stdio.h>
#include <stdlib.h>

int utn_getnumber(int*puntero,int min,int max,char* msg,char* msgError,int vueltas)
{
    int numero;
    int retorno;

    while(vueltas>0){
        printf("%s",msg);
        if(scanf("%d", &numero)==1){
    if(numero>min && numero<max){
        break;
    }
        printf(msgError);
    vueltas--;
    }
    if(vueltas==0){
        retorno=-1;
    }else{

    (*puntero)=numero;
    retorno=0;
    }
    }
    return retorno;

}
