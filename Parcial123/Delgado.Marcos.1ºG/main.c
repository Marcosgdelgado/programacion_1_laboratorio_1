#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Delgado.h"

#define TAM 10


int menu();
void cargarSectores(eCategoria sectores[]);
void cargarComidas(eComida comidas[]);
void listarComidas(eComida c[], int tam);
void altaAlmuerzo(eAlmuerzo a[], int tama, eComida c[], int tamc, eJuegos e[], int tame, eCategoria s[], int tams, int* pId);
int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam);
void inicializarAlmuerzos(eAlmuerzo lista[], int tam);
void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eJuegos e[], int tame);
void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eJuegos e[], int tame);
void cargarCategoria(eCategoria sectores[]);


int main()
{
    char seguir = 's';
    int idAlmuerzo = 1000;

    eCategoria sectores[5];
    eComida comidas[5];
    eAlmuerzo almuerzos[20];
    cargarCategoria(sectores);
    cargarComidas(comidas);
    inicializarAlmuerzos(almuerzos, 20);

    eJuegos empleados[TAM];
    inicializarJuego(empleados,TAM);
    harcodearJuegos(empleados);
    eCliente clientes[TAM];
    inicializarEmpleados(clientes,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaJuego(empleados, TAM, sectores, 5);
            break;
        case 2:
            bajaJuego(empleados,TAM, sectores, 5);
            break;
        case 3:
            ModificarJuego(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 4:
            mostrarJuegos(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 5:
            altaCliente(clientes, TAM);
            system("pause");
            break;
        case 6:
            bajaCliente(clientes, TAM);
            system("pause");
            break;
        case 7:
            modificarCliente(clientes, TAM);
            system("pause");
            break;
        case 8:
            mostrarClientes(clientes);
            system("pause");
            break;
        case 9:
            listarComidas(comidas, 5);
            system("pause");
            break;
        case 10:
            altaAlmuerzo(almuerzos, 20, comidas, 5, empleados, TAM, sectores, 5, &idAlmuerzo);
            system("pause");
            break;
        case 11:
            mostrarAlmuerzos(almuerzos, 20, comidas, 5, empleados, TAM);
            system("pause");
            break;
        case 20:
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
    printf(" 1-  Alta juego\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Juegos\n");
    printf(" 5-  Ordenar Juegos\n");
    printf(" 6-  Mostrar Juegos x Sector\n");
    printf(" 7-  Ordenar Juegos x Sector y Nombre\n");
    printf(" 8-  Listar Juegos ganadores\n");
    printf(" 9-  Listar Comidas\n");
    printf(" 10- Alta Almuerzo\n");
    printf(" 11- Mostrar Almuerzos\n");
    printf(" 20- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void cargarCategoria(eCategoria categorias[])
{
    eCategoria cat[]=
    {
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "Salon"},
        {5, "Magia"}
    };

    for(int i=0; i < 5; i++)
    {
        categorias[i] = cat[i];
    }
}

void cargarComidas(eComida comidas[])
{
    eComida food[]=
    {
        {1, "Milanesa"},
        {2, "Pizza"},
        {3, "Ensalada"},
        {4, "Pescado"},
        {5, "Lasagna"}
    };

    for(int i=0; i < 5; i++)
    {
        comidas[i] = food[i];
    }
}

void listarComidas(eComida c[], int tam)
{
    printf("\nLista de comidas\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",c[i].id, c[i].descripcion);
    }
    printf("\n\n");
}

void altaAlmuerzo(eAlmuerzo* a, int tama, eComida c[], int tamc, eJuegos e[], int tame, eCategoria s[], int tams, int* pId)
{
    int idAlmuerzo = *pId;
    int id;
    int idComida;
    efecha fecha;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    indice = buscarLibreAlmuerzo(a, tama);

    if(indice == -1)
    {
        printf("No se pueden cargar mas almuerzos\n\n");
    }
    else
    {
        nuevoAlmuerzo.id = idAlmuerzo;

        mostrarJuegos(e, tame, s, tams);

        printf("Ingrese id: ");
        scanf("%d", &id);

        nuevoAlmuerzo.idEmp = id;

        listarComidas(c, tamc);
        printf("Ingrese comida: ");
        scanf("%d", &idComida);

        nuevoAlmuerzo.idComida = idComida;

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlmuerzo.fecha = fecha;

        nuevoAlmuerzo.isEmpty = 0;

        a[indice] = nuevoAlmuerzo;

        *pId = idAlmuerzo + 1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam)
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

void inicializarAlmuerzos(eAlmuerzo lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eJuegos e[], int tame)
{
    int flag = 0;

    system("cls");
    printf("id   fecha   id   Nombre    Comida\n\n");

    for(int i=0; i < tama; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlmuerzo(a[i], c, tamc, e, tame);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados");
    }
    printf("\n\n");
}


void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eJuegos e[], int tame)
{
    char descComida[20];
    int indice;
    eJuegos empleado;

    obtenerDescComida(c, tamc, unAlmuerzo.idComida, descComida);
    indice = buscarJuego(e, tame, unAlmuerzo.idEmp);

    empleado = e[indice];

    printf("%4d %02d/%02d/%d  %d %10s  %10s\n", unAlmuerzo.id, unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio, empleado.id, empleado.nombre, descComida);
}

void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena)
{
    for(int i=0; i < tamc; i++)
    {
        if( c[i].id == idComida)
        {
            strcpy(cadena, c[i].descripcion);
        }
    }
}
