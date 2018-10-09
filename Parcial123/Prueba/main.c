#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


typedef struct
{
    int codigo;
    char nombre[20];
    char sexo;
    float telefono;
    int isEmpty;
} eCliente;

int menu();
void inicializarEmpleados(eCliente lista[], int tam);
void mostrarEmpleado(eCliente unEmpleado);
int buscarLibre(eCliente lista[], int tam);
int buscarEmpleado(eCliente lista[], int tam, int codigo);
void altaEmpleado(eCliente lista[], int tam);
void bajaEmpleado(eCliente lista[], int tam);
void ModificarEmpleado(eCliente lista[], int tam);

void mostrarEmpleados(eCliente lista[], int tam);


int main()
{
    char seguir = 's';

    eCliente empleados[TAM];
    inicializarEmpleados(empleados,TAM);

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
            system("pause");
            break;

        case 6:
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
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Empleados\n");
    printf(" 5-  Ordenar Empleados\n");
    printf(" 6- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void inicializarEmpleados(eCliente lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(eCliente unEmpleado)
{
   printf("%4d %10s   %2c    %f \n", unEmpleado.codigo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.telefono);
}

void mostrarEmpleados(eCliente lista[], int tam)
{

    system("cls");
    printf("Legajo   Nombre  Sexo   Sueldo   \n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i]);
        }
    }

    printf("\n\n");


}


int buscarLibre(eCliente lista[], int tam)
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


int buscarEmpleado(eCliente lista[], int tam, int codigo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigo == codigo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaEmpleado(eCliente lista[], int tam)
{
    int indice;
    int codigo;
    int existe;

    eCliente nuevoEmpleado;

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
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);

        existe = buscarEmpleado(lista, tam, codigo);

        if( existe != -1)
        {

            printf("Ya existe un empleado con el codigo %d\n", codigo);
            mostrarEmpleado(lista[existe]);

            system("pause");

        }
        else
        {

            nuevoEmpleado.codigo = codigo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("Ingrese telefono: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.telefono);

            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
    }

}


void bajaEmpleado(eCliente lista[], int tam)
{

    int codigo;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &codigo);

    indice = buscarEmpleado(lista, tam, codigo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de codigo %d\n\n", codigo);
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

void ModificarEmpleado(eCliente lista[], int tam)
{
    int codigo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &codigo);

    indice = buscarEmpleado(lista, tam, codigo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de codigo %d\n\n", codigo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice]);

        printf("\nModifica telefono? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo telefono: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].telefono = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }
}
