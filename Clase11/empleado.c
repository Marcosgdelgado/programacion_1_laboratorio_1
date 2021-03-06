#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"



void inicializarEmpleados(Employee lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(Employee unEmpleado, eSector sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idSector, descSector);

    printf("%4d %10s      %6.2f %10s\n", unEmpleado.id, unEmpleado.name, unEmpleado.salary, descSector);
}

void mostrarEmpleados(Employee lista[], int tam, eSector sectores[], int tamSector)
{

    system("cls");
    printf("id   Nombre     Sueldo    Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i], sectores, tamSector);
        }
    }
    system("pause");
}


int buscarLibre(Employee lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(Employee lista[], int tam, int id)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaEmpleado(Employee lista[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int id;
    int existe;
    int idSector;
    Employee nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta empleado ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &id);

        existe = buscarEmpleado(lista, tam, id);

        if( existe != -1)
        {

            printf("Ya existe un empleado con el id %d\n", id);
          //  mostrarEmpleado(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoEmpleado.id = id;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);

            fflush(stdin);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.salary);

            listarSectores(sectores, tamSector);
            printf("\nIngrese sector: ");
            scanf("%d", &idSector);

            nuevoEmpleado.idSector = idSector;


            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
    }

}


void bajaEmpleado(Employee lista[], int tam)
{

    int id;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun empleado de id %d\n\n", id);
        system("pause");
    }
    else
    {
       // mostrarEmpleado(lista[indice]);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {

            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

void ModificarEmpleado(Employee lista[], int tam)
{
    int id;
    int indice;
    char seguir;
    float nuevosalary;
    char newname[20];
    int newsector;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(lista, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun empleado de id %d\n\n", id);
        system("pause");
    }
    else
    {
      //  mostrarEmpleado(lista[indice]);

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);


        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevosalary);
            lista[indice].salary = nuevosalary;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");

        printf("\nModifica nombre? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo nombre: ");
            scanf("%s", newname);
            strcpy(lista[indice].name , newname);

            printf("Modificacion exitosa\n\n");
        }
        system("pause");

        printf("\nModifica Sector? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);


        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf(" 1 - RRHH\n 2- Ventas\n 3- Compras\n 4- Contables\n 5- Sistemas\n");
            printf("\nIngrese nuevo sector: ");

            scanf("%d", &newsector);
            lista[indice].idSector = newsector;

            printf("Modificacion exitosa\n\n");
        }
    }





}

void ordenarEmpleadosXid(Employee lista[], int tam)
{
    Employee auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {

            if( lista[i].id > lista[j].id)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }
        }
    }

    printf("Empleados oredenados con exito!!!\n\n");


}

void harcodearEmpleados(Employee empleados[])
{

    Employee x[]=
    {

        {1111, "juan", 'm', 23000,1,0},
        {2222, "luis", 'm', 18000, 1, 0},
        {1234, "ana", 'f', 21000, 5,0},
        {5643, "melisa", 'f', 24000, 2, 0},
        {2312, "mia", 'f', 34000, 3, 0},
        {7768, "mauro", 'm', 19000,5, 0},
        {1324, "alberto", 'm', 26000, 4,0},
        {9876, "valentina", 'f', 32000,5, 0}

    };

    for(int i=0; i < 8; i++)
    {

        empleados[i] = x[i];
    }




}

void listarSectores(eSector sectores[], int tam){

  printf("Id sector  Descripcion\n");
    for(int i=0; i< tam; i++){
      printf("%d   %10s\n", sectores[i].sectorid, sectores[i].descripcion);

    }
    printf("\n\n");
}

void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[]){

for(int i=0; i < tam; i++){

    if( sectores[i].sectorid == idSector){
        strcpy(cadena, sectores[i].descripcion);
    }
}

}
