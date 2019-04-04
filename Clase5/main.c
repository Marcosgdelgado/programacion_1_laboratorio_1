#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"
#define Tam_array 3

int main()
{

 int i;
 int array[Tam_array];
 float promedio;
 int numberArray[3]={1,5,2};

 utn_getarrayInt(array, Tam_array,"Numero: ","error",0,100,3);

 for(i=0;i=Tam_array;i++)
 {
    printf("%d\n", array[i]);
 }
 calcularpromedio(array, Tam_array, &promedio);
 printf("%f\n", promedio);
 return 0;
}   //en arrays no es necesario usar &

    //numero=5;
    //numeros[10]=5;

    // &numeros[0] ==== numeros ===> trae desde el array 0
    //  &numeros[100]===> Obtiene numeros de memoria especificos
    //utn_getnumber(&numero,0,1000,"Ingrese un valor: ", "Error!",3);
    //printf("%d",numero);

    /*tamanio=numero;
    mostrarArrays(v[10],tamanio);*/
//        mostrarArrays();
/*int calcularpromedio(int * pArrayInt, int limite, float * pResultado){
    int i;
    int buffer;
    for (i=0; i=limite; i++){
        buffer= pArrayInt[i];
    }
    *pResultado = (float)buffer/limite;
    return 0;
}*/
