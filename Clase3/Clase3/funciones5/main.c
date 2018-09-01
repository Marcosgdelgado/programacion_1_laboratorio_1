#include <stdio.h>
#include <stdlib.h>
#include "milibreria.h"

int main()
{

int edad;




   printf("Ingrese edad: ");
    scanf("%d", &edad);

    while( !validarRango(edad, 18, 65)){

             printf("Edad fuera de rango. Reingrese edad: ");
             scanf("%d", &edad);

    }


    printf("Edad valida\n");
    return 0;
}















