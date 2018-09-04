#include <stdio.h>
#include <stdlib.h>


void mostrarmsj(char msj[]);
int sumar(int a, int b);
    int main()
{
    char mensaje[25]="Ingrese un numero: ";

    printf("%d\n", sumar(10,5));

    mostrarmsj(mensaje);


    return 0;
}

void mostrarmsj(char msj[]){
    printf("%s\n\n", msj);

}
int sumar(int a, int b){
    return a+b;

}

