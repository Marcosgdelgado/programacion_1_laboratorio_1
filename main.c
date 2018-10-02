#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idsector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

int menu();
void inicializarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam);
void bajaEmpleado(eEmpleado lista[], int tam);
void ModificarEmpleado(eEmpleado lista[], int tam);
void harcodearEmpleados(eEmpleado empleado[]);
//void ordenarEmpleadosXlegajo(empleado lista[], int tam);

int main()
{
    char seguir = 's';

    eSector sectores[];{
    {1,"RRHH"};
    {2,"Sistemas"};
    {3,"Administracion"};
    {4,"Tesoreria"};

    strlwr(cadena);
    char cadena[20];

    }
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    harcodearEmpleados(empleados);
    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM);
            break;
        case 2:
            bajaEmpleado(empleados,TAM);
            break;
        case 3:
            ModificarEmpleado(empleados, TAM);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(empleados, TAM);
            break;
        case 5:
            ordenarEmpleadosXlegajo(empleados, TAM);
            system("pause");
            break;
        case 6:
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
    printf(" 6- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{

    printf("%d %s %c %.2f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo);
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{

    system("cls");
    printf("Legajo Nombre Sexo Sueldo\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i]);
        }
    }
    system("pause");
}


int buscarLibre(eEmpleado lista[], int tam)
{

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


int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].legajo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaEmpleado(eEmpleado lista[], int tam)
{
    int indice;
    int legajo;
    int existe;
    eEmpleado nuevoEmpleado;

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
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        existe = buscarEmpleado(lista, tam, legajo);

        if( existe != -1)
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;



          }
    }

}


void bajaEmpleado(eEmpleado lista[], int tam)
{

    int legajo;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

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

void ModificarEmpleado(eEmpleado lista[], int tam)
{
    int legajo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

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
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }





}

void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++){
        for(int j= i+1; j < tam; j++){

            if( lista[i].legajo > lista[j].legajo){
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }
        }
    }

    printf("Empleados oredenados con exito!!!\n\n");


}

void harcodearEmpleados(eEmpleado empleado[]){

eEmpleado x[]=
{


    {1111,"Juan",'m',23000},
    {2222,"Lucas",'m',20000},
    {3333,"Ana",'f',25000},
    {4444,"Sol",'f',30000},

};

for(int i=0; i<4 ;i++){
    empleado[i]=x[i];
}

}

void obtenerSector (eSector sectores[], int tam, int idsector, char cadena[])
{

}eSector
