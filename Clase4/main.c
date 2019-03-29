#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
 int number;
 //int cantidad;

 utn_getnumber(&number ,0,100,"Ingresa: ", "no! error\n\n",5);

 printf("%d", number);
 //printf("%d", cantidad);
 //prueba();

    return 0;
}
