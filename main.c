#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarvector(int x[], int);

int main()

{
    int vec[TAM];
    char respuesta;
    int numero;
    int indice;

    for (int i=0; i<TAM ; i++){
         vec[i]=0;

        }

    do{
         printf("ingrese un numero: ");
         scanf("%d", &numero);

         printf("ingrese donde desea guardar numero en array: ");
         scanf("%d", &indice);

         vec[indice] = numero;

        printf("Desea continuar? ingrese s o n: ");
        fflush(stdin);
        scanf("%c", &respuesta);
      } while(respuesta=='s');

    buscavector()
      mostrarvector(vec,TAM);

    return 0;
}

void mostrarvector(int x[], int tam)
{
    for (int i=0; i< tam; i++){

        printf("%d ", x[i]);

    }
     printf("\n \n");
}

void buscavector( int vec[], int tam, int valor)
{
    int indece = -1;

    for (int i=0; i<tam ; i++)
    {
        if( vec[i] == valor)
        {
            indice = i;
            break;
        }

    }


}

