#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

#define TAM 10



int menu();
void cargarSectores(eSector sectores[]);
void listarComidas(eComida c[], int tam);
int main()
{
    char seguir = 's';

    eSector sectores[5];
    eComida comidas[5];


    cargarSectores(sectores);
    Employee empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    harcodearEmpleados(empleados);


    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM, sectores, 5);
            break;
        case 2:
            bajaEmpleado(empleados,TAM);
            break;
        case 3:
            ModificarEmpleado(empleados, TAM);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, 5);
            break;
        case 5:
            ordenarEmpleadosXid(empleados, TAM);
            system("pause");
            break;
        case 6:
            listarComidas(comidas, TAM);
            system("pause");
            break;
        case 7:
            printf("Salir");
            system("pause");
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

int menu()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Baja\n");
    printf(" 3- Modificacion\n");
    printf(" 4- Listar Empleados\n");
    printf(" 5- Ordenar Empleados\n");
    printf(" 6- Listar comida\n");
    printf(" 7- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void cargarSectores(eSector sectores[]){

     char seguir = 's';

    eSector sec[]={
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };
    for(int i=0; i<5; i++){

        sectores[i] = sec[i];
    }

}
void cargarComidas(eComida comidas[]){


    eComida food[]={
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Empanadas"},
        {4, "Pizza"},
        {5, "Albondigas"}
    };
    for(int i=0; i<5; i++){

        comidas[i] = food[i];
    }
}

void listarComidas(eComida c[], int tam){


    printf("\nLista de comidas\n\n");

        for(int i=0; i<tam; i++){
            printf("%d   %10s \n", c[i].id, c[i].descripcion);
        }
     printf("\n\n");

}
