#include <stdio.h>
#include <stdlib.h>
int sumar1(int a,int b);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("ingrese numero: ");
    fflush(stdin);
    scanf("%d", &num1);
    printf("ingrese otro numero: ");
    fflush(stdin);
    scanf("%d", &num2);

    resultado = sumar1;

    printf("El resultado es: %d", resultado);

    return 0;
}


int sumar1(int a, int b){
 return a+b;
}
