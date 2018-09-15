#include <stdio.h>
#include <stdlib.h>

#define TAM 2


int main()
{
    int legajos[TAM];
    int pp[TAM];
    int sp[TAM];
    float promedios[TAM];
    char sexos[TAM];
    char nombres[TAM][20];

    int autoLeg = 1200;


    for(int i= 0; i < TAM; i++){

     /*   printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);*/

        legajos[i] = autoLeg;
        autoLeg++;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese nota primer parcial: ");
        scanf("%d", &pp[i]);

        printf("Ingrese nota segundo parcial: ");
        scanf("%d", &sp[i]);

        promedios[i] = (float) (pp[i] + sp[i]) / 2;

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);
    }


    system("cls");

    printf(" Legajo        Nombre        sexo  1Parcial   2Parcial Promedio\n\n");

     for(int i= 0; i < TAM; i++){

         printf("  %4d        %10s      %c       %2d         %2d      %3.2f\n", legajos[i], nombres[i], sexos[i], pp[i], sp[i], promedios[i]);

     }   auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = pp[i];
                pp[i] = pp[j];
                pp[j] = auxInt;

                auxInt = sp[i];
                sp[i] = sp[j];
                sp[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                strcpy( auxCad, nombres[i]);
                strcpy( nombres[i], nombres[j]);
                strcpy( nombres[j], auxCad);
            }

     printf("\n\n");



    return 0;
}






