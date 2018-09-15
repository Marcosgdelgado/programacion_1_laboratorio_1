#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

void ordenarAlumnos(int leg[], char nombres[][20], int pp[], int sp[], float prom[], char sex[], int tam);

int main()
{
    /*  int legajos[TAM];
      int pp[TAM];
      int sp[TAM];
      float promedios[TAM];
      char sexos[TAM];
      char nombres[TAM][20];#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

void ordenarAlumnos(int leg[], char nombres[][20], int pp[], int sp[], float prom[], char sex[], int tam);

int main()
{
    /*  int legajos[TAM];
      int pp[TAM];
      int sp[TAM];
      float promedios[TAM];
      char sexos[TAM];
      char nombres[TAM][20];


      for(int i= 0; i < TAM; i++){

          printf("Ingrese legajo: ");
          scanf("%d", &legajos[i]);

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
      }*/
    int legajos[] = {1234, 4323, 1128, 3243};
    int pp[]= {5, 6, 10, 9};
    int sp[] = {2, 4, 6, 8};
    float promedios[] = {3.5, 5, 8, 8.5};
    char sexos[] = {'f', 'm', 'f', 'm'};
    char nombres[][20] = {"Juana", "Luis", "Analia", "Jorge"};

    system("cls");

    printf(" Legajo        Nombre        sexo  1Parcial   2Parcial Promedio\n\n");

    for(int i= 0; i < TAM; i++)
    {

        printf("  %4d        %10s      %c       %2d         %2d      %3.2f\n", legajos[i], nombres[i], sexos[i], pp[i], sp[i], promedios[i]);

    }
    printf("\n\n");
    ordenarAlumnos(legajos, nombres,  pp, sp, promedios, sexos, TAM);




    printf(" Legajo        Nombre        sexo  1Parcial   2Parcial Promedio\n\n");

    for(int i= 0; i < TAM; i++)
    {

        printf("  %4d        %10s      %c       %2d         %2d      %3.2f\n", legajos[i], nombres[i], sexos[i], pp[i], sp[i], promedios[i]);

    }
    printf("\n\n");


    return 0;
}



void ordenarAlumnos(int leg[], char nombres[][20], int pp[], int sp[], float prom[], char sex[], int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[20];

    for(int i=0; i < tam -1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {
            if( sex[i] < sex[j])
            {

                auxInt = leg[i];
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
            else if(  sex[i] == sex[j]   && strcmp(nombres[i], nombres[j]) > 0)
            {
                auxInt = leg[i];
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
        }
    }

}




      for(int i= 0; i < TAM; i++){

          printf("Ingrese legajo: ");
          scanf("%d", &legajos[i]);

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
      }*/
    int legajos[] = {1234, 4323, 1128, 3243};
    int pp[]= {5, 6, 10, 9};
    int sp[] = {2, 4, 6, 8};
    float promedios[] = {3.5, 5, 8, 8.5};
    char sexos[] = {'f', 'm', 'f', 'm'};
    char nombres[][20] = {"Juana", "Luis", "Analia", "Jorge"};

    system("cls");

    printf(" Legajo        Nombre        sexo  1Parcial   2Parcial Promedio\n\n");

    for(int i= 0; i < TAM; i++)
    {

        printf("  %4d        %10s      %c       %2d         %2d      %3.2f\n", legajos[i], nombres[i], sexos[i], pp[i], sp[i], promedios[i]);

    }
    printf("\n\n");
    ordenarAlumnos(legajos, nombres,  pp, sp, promedios, sexos, TAM);




    printf(" Legajo        Nombre        sexo  1Parcial   2Parcial Promedio\n\n");

    for(int i= 0; i < TAM; i++)
    {

        printf("  %4d        %10s      %c       %2d         %2d      %3.2f\n", legajos[i], nombres[i], sexos[i], pp[i], sp[i], promedios[i]);

    }
    printf("\n\n");


    return 0;
}



void ordenarAlumnos(int leg[], char nombres[][20], int pp[], int sp[], float prom[], char sex[], int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    char auxCad[20];

    for(int i=0; i < tam -1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {
            if( sex[i] < sex[j])
            {

                auxInt = leg[i];
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
            else if(  sex[i] == sex[j]   && strcmp(nombres[i], nombres[j]) > 0)
            {
                auxInt = leg[i];
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
        }
    }

}







