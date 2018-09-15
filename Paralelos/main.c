#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

void ordenar(int[], int[], int[],int[], char[], char[], int);
int main()
{
 int legajo[TAM];
 int pp[TAM];
 int sp[TAM];
 float promedio[TAM];
 char sexos[TAM];
 char nombres[TAM][20];


   /* for(int i=0; i<TAM; i++)
    {
        printf("Ingresar legajo: ");
        scanf("%d", &legajo[i]);
        printf("Ingresar nota primer parcial: ");
        scanf("%d", &pp[i]);
        printf("Ingresar nota segundo parcial: ");
        scanf("%d", &sp[i]);
        printf("Ingresar sexo: ");
        fflush(stdin);
         scanf("%c", &sexos[i]);
        printf("Ingresar nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        promedio[i]= (float)(pp[i]+sp[i])/2;
        printf("su promedio es: %f\n", promedio);
    }
    */
     int legajo[]= {1234 , 4321 };
     int pp[]= {10 , 5};
     int sp[]= {2,9};
     float promedio[] = {7.5, 5.5};
     char sexos[]= {'m','m'}
     char nombres[][20]={"marcos","Carlos"};




    system("cls");
        printf("legajo pp sp sexo nombre promedio \n\n");
    for(int i=0; i <TAM ;i++)
    {
        printf("%2d %3d %3d %2c %3s %2f \n", legajo[i], pp[i], sp[i], sexos[i], nombres[i], promedio [i]);

    }


    ordenar(legajo, nombres, sexos, pp, sp, promedio, TAM);

    for(int i=0; i <TAM ;i++)
    {
        printf("%2d %3d %3d %2c %3s %2f \n", legajo[i], pp[i], sp[i], sexos[i], nombres[i], promedio [i]);

    }

    printf("\n\n");
    return 0;
}


void ordenar(int leg[], int pp[], int sp[],int prom[], char sex[], char nom[], int tam )
{
    int auxint;
    float auxfloat;
    char auxchar[20];

    for (int i=0; i<tam -1; i++){

        for(int j= i+1; j <tam; j++){
            if(prom[i]<prom[j]){
                auxint=leg[i];
                leg[i]=leg[j];
                leg[j]=auxint;

                auxint=pp[i];
                pp[i]=pp[j];
                pp[j]=auxint;

                auxint=sp[i];
                sp[i]=sp[j];
                sp[j]=auxint;

                auxfloat=prom[i];
                prom[i] =prom [j];
                prom[j]=prom;

                /*auxchar=sex[i];
                sex [i]=sex[j];
                sex[j]=auxchar;*/

                strcpy(auxchar, nom[i]);
                strcpy(nom[i],nom[j]);
                strcpy(nom[j],auxchar);

            }
        }

    }






}
