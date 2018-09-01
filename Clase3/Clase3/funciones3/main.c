#include <stdio.h>

#include <stdlib.h>

//prototipo
void sumar3( );

int main()
{

     sumar3();

    return 0;
}
// desarrollo
void sumar3( ){

  int num1;
int num2;
int rta;


   printf("Ingrese un numero: ");
    scanf("%d", &num1);
   printf("Ingrese otro numero: ");
    scanf("%d", &num2);

rta = num1 + num2;

printf("El resultado de la suma es %d\n\n", rta);

}
