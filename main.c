#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float, float);
float resta(float, float);
float division(float, float);
float multiplicacion(float,float);

int main(void)
{
    char seguir='s';
    int opcion=0;
    float numero_uno;
    float numero_dos;
    float resultado;
    float i, factor=1;





    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=%.2f)\n", numero_uno);
        printf("2- Ingresar 2do operando (B=%.2f)\n", numero_dos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: printf("\nIngrese un numero: ");
                    fflush(stdin);
                    scanf("%f", &numero_uno);
                break;

            case 2: printf("\nIngrese un numero: ");
                    fflush(stdin);
                    scanf("%f", &numero_dos);
                break;

            case 3: printf("\nLa suma total es: %.2f\n\n", suma(numero_uno,numero_dos));
                    getch();

                break;

            case 4: printf("\nLa resta total es: %.2f\n\n", resta(numero_uno,numero_dos));
                    getch();
                break;

            case 5: while(numero_dos < 0  || numero_dos==0 )
                    {
                       printf("\nnumero es no valido, vuelva a intentar: ");
                       scanf("%f", &numero_dos);

                    }
                    printf("\nLa division total es: %.2f\n\n", division(numero_uno,numero_dos));
                    getch();
                break;

            case 6: printf("\nLa multiplicacion total es: %.2f\n\n", multiplicacion(numero_uno, numero_dos));
                    getch();
                break;

            case 7: while (numero_uno<0)
                {
                    printf("\nIngrese un numero entero:\n ");
                    scanf("%f", &numero_uno);
                }
                        for(i=1;i<=numero_uno;i++)
                        {
                            factor= factor*i;

                        }
                    printf("\nEl factor de:%.2f es %.2f\n",numero_uno, factor);
                    getch();
                break;

            case 8: printf("\nLa suma total es: %.2f\n\n", suma(numero_uno,numero_dos));

                    printf("\nLa resta total es: %.2f\n\n", resta(numero_uno,numero_dos));

                    printf("\nLa division total es: %.2f\n\n", division(numero_uno, numero_dos));

                    printf("\nLa multiplicacion total es: %.2f\n\n", multiplicacion(numero_uno, numero_dos));


                    while (numero_uno < 0)
                {
                    printf("\nIngrese un numero entero:\n ");
                    scanf("%f", &numero_uno);
                }
                        for(i=1;i<=numero_uno;i++)
                        {
                            factor= factor*i;

                        }
                    printf("\nEl factor de:%.2f es %.2f\n",numero_uno, factor);


                break;

            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
float suma(float numero_uno, float numero_dos)
    {   float retorno;
        retorno =numero_uno+numero_dos;
        return retorno;
    }

float resta(float numero_uno, float numero_dos)
{
    float retorno;
    retorno= numero_uno-numero_dos;
    return retorno;

}
float division(float numero_uno, float numero_dos)
{
     while(numero_dos < 0  || numero_dos==0 )
                    {
                       printf("\nnumero es no valido, vuelva a intentar: ");
                       scanf("%f", &numero_dos);

                    }
    float retorno;
    retorno= numero_uno/numero_dos;
    return retorno;

}
float multiplicacion(float numero_uno, float numero_dos)
{
    float retorno;
    retorno= numero_uno*numero_dos;
    return retorno;

}

float factoreo(float numero_uno)
{
    float retorno;
    retorno=numero_uno;
    return retorno;


}


