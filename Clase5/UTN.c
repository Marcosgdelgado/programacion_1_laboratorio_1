#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int*puntero,int min,int max,char* msg,char* msgError,int vueltas)
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
void mostrarArrays(char vec[],int tam){

for(int i=0 ;i < tam; i++)
{
    printf("%c  ", vec[i]);
}
}

int utn_getarrayInt(    int* pArrayResultados,
                        int limite,
                        const char *mensaje,
                        const char *mensajeError,
                        int minimo,
                        int maximo,
                        int reintentos)
{
    int i;
    int buffer;
    int ret;
    for(i=0;i<limite;i++)
    {
        ret= utn_getNumero(&buffer,mensaje,mensajeError,minimo,maximo,reintentos);
        if(ret){
            break;
        }
        *(pArrayResultados+i)=buffer;
        }
    return ret;
}

int calcularpromedio(int * pArrayInt, int limite, float * pResultado){
    int i;
    int acumulador=0;
    for (i=0; i=limite; i++){
        acumulador+= pArrayInt[i];
    }
    *pResultado = (float)acumulador/limite;
    return 0;
    }

void main(void){

int vec[MAX],i,mayor,menor,num,flag;

for(i=0;i<MAX;i++){

    printf("ingrese N: ");
    scanf()
}
}
/*if(a[i]>a[i+1]){

int buffer;

buffer = a[i];
a[i]=a[a+1];
a[i+1]=buffer;
}*/
