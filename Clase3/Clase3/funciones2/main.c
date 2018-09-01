#include <stdio.h>

#include <stdlib.h>

//prototipo
void sumar2(int op1, int op2);

int main()
{

    int num1;
    int num2;


    printf("Ingrese un numero: ");
    scanf("%d", &num1);

      printf("Ingrese otro numero: ");
      scanf("%d", &num2);

     sumar2(num1, num2);

    return 0;
}


// desarrollo
void sumar2(int op1, int op2){

int rta;

rta = op1 + op2;

printf("El resultado de la suma es %d\n\n", rta);

}

