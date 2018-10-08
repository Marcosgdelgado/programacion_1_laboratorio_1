#include "AbmCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializarJuego(eJuegos lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarJuego(eJuegos unEmpleado, eJuego sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idJuegos, descSector);

    printf("%4d  %10s  %6.2f  %10s\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.importe, descSector);
}

void mostrarJuegos(eJuegos lista[], int tam, eJuego sectores[], int tamSector)
{

    system("cls");
    printf("id  tipo  importe   Codigo\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarJuego(lista[i], sectores, tamSector);
        }
    }

    printf("\n\n");


}


int buscarLibre(eJuegos lista[], int tam)
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


int buscarJuego(eJuegos lista[], int tam, int id)
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

void altaJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector)
{
    int indice;
    int id;
    int existe;
    int idJuegos;
    eJuegos nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta Juego ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &id);

        existe = buscarJuego(lista, tam, id);

        if( existe != -1)
        {

            printf("Ya existe un Juego con el id %d\n", id);
            //  mostrarJuego(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoEmpleado.id = id;

            printf("Ingrese tipo de juego: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese importe: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.importe);

            listarSectores(sectores, tamSector);
            printf("\nIngrese ID: ");
            scanf("%d", &idJuegos);

            nuevoEmpleado.idJuegos = idJuegos;


            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
    }

}


void bajaJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector)
{

    int id;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja Juego ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarJuego(lista, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun Juego de id %d\n\n", id);
        system("pause");
    }
    else
    {
        mostrarJuego(lista[indice], sectores, tamSector);

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

void ModificarJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector)
{
    int id;
    int indice;
    char seguir;
    float nuevoimporte;

    system("cls");
    printf("  *** Modificar  Juego ***\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarJuego(lista, tam, id);

    if( indice == -1)
    {
        printf("No hay ningun juego con id %d\n\n", id);
        system("pause");
    }
    else
    {
        mostrarJuego(lista[indice], sectores, tamSector);

        printf("\nModifica importe? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo importe: ");
            scanf("%f", &nuevoimporte);
            lista[indice].importe = nuevoimporte;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }





}

void ordenarJuegosXID(eJuegos lista[], int tam)
{
    eJuegos auxEmpleado;
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

    printf("Juegos ordenados con exito!!!\n\n");


}

void harcodearJuegos(eJuegos empleados[])
{

    eJuegos x[]=
    {

        {1111, "juan", 'm', 23000,1,0},
        {2222, "luis", 'm', 18000, 1, 0},
        {1234, "ana", 'f', 21000, 5,0},
        {5643, "melisa", 'f', 24000, 2, 0},
        {2312, "mia", 'f', 34000, 3, 0},
        {7768, "mauro", 'm', 32000,5, 0},
        {1324, "alberto", 'm', 26000, 4,0},
        {9876, "valentina", 'f', 32000,5, 0}

    };

    for(int i=0; i < 8; i++)
    {

        empleados[i] = x[i];
    }




}

void listarSectores(eJuego sectores[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);

    }
    printf("\n\n");
}

void obtenerSector(eJuego sectores[], int tam, int idJuegos, char cadena[])
{

    for(int i=0; i < tam; i++)
    {

        if( sectores[i].id == idJuegos)
        {
            strcpy(cadena, sectores[i].descripcion);
        }
    }

}

void listarJuegosXID(eJuegos x[],int tam, eJuego sectores[], int tamSector)
{
    int idJuegos;
    char descripcion[20];
    int flag = 0;

    system("cls");
    printf("  *** Listado de Juegos ***\n\n");

    listarSectores(sectores, tamSector);
    printf("Ingrese ID: ");
    scanf("%d",&idJuegos);

    obtenerSector(sectores, tam, idJuegos, descripcion);

    system("cls");
    printf("Juegos id %s\n\n", descripcion);
    for(int i=0; i< tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].idJuegos == idJuegos)
        {
            mostrarJuego(x[i], sectores, tamSector);
            flag = 1;
        }
    }

    printf("\n\n");

    if(flag == 0)
    {
        printf("No hay Juegos que mostrar\n\n");
    }

}

void ordenarXJuegoYNombre(eJuegos x[],int tam, eJuego sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eJuegos auxEmpleado;

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            obtenerSector(sectores, tamSector, x[i].idJuegos, descripcionI);
            obtenerSector(sectores, tamSector, x[j].idJuegos, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
    printf("\nJuegos ordenados con exito!!!\n\n");

}

void mostrarJuegosMasGanadores(eJuegos x[],int tam, eJuego sectores[], int tamSector)
{
    float maximporte;
    char descripcion[20];
    int flag;
    int flag2;

    system("cls");
    printf("\n*** Juegos que mas ganan por id ***\n\n");

    for(int i=0; i < tamSector; i++)
    {

        obtenerSector(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n", descripcion);
        printf("--------------\n\n");
        flag = 0;
        flag2 = 0;
        for(int j=0; j < tam; j++)
        {
            if( (x[j].importe > maximporte && x[j].isEmpty == 0 && x[j].idJuegos == sectores[i].id) || flag == 0)
            {
                maximporte = x[j].importe;
                flag = 1;
            }

            if( x[j].isEmpty == 0 && x[j].idJuegos == sectores[i].id)
            {
                flag2 = 1;
            }

        }

        if(flag2 == 0)
        {
            printf("Sector Vacio\n");
        }
        else
        {

            for(int j=0; j < tam; j++)
            {
                if( x[j].importe == maximporte && x[j].isEmpty == 0)
                {
                    mostrarJuego(x[j], sectores, tamSector);
                }
            }

        }

        printf("\n\n");
    }
}

