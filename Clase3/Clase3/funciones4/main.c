#include <stdio.h>

#include <stdlib.h>

//prototipo
int sumar4( );

int main()
{
    int resultado;

    resultado =  sumar4();

     printf("El resultado de la suma es %d\n\n", resultado);

    return 0;
}
// desarrollo
int sumar4( ){

int num1;
int num2;
int rta;


   printf("Ingrese un numero: ");
    scanf("%d", &num1);
   printf("Ingrese otro numero: ");
    scanf("%d", &num2);

rta = num1 + num2;

return rta;



}
