#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tam_num 10

int main()
{
    int numero;
    int numero2;
    getNumero(&numero,"Ingrese un numero: ","ERROR\n",&numero2,"Ingrese segundo numero: ",0,10,3);
    printf("%d",numero);
    printf("\n%d",numero2);
    return 0;
}



