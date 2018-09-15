#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[20];
    char aux[50];


    printf("ingrese su nombre: ");
    gets(aux);

    while( strlen(aux)> 19){
        printf("Error, nombre demasiado largo. Re ingrese nombre.");
        gets(aux);
    }

    strcpy(nombre, aux);

    printf("Usted se llama: %s\n", nombre);






    return 0;
}
