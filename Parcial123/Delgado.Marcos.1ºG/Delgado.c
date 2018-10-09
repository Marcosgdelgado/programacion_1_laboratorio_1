
#include "Delgado.h"
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

void mostrarJuego(eJuegos unEmpleado, eCategoria sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idJuegos, descSector);

    printf("%4d  %10s  %6.2f  %10s\n", unEmpleado.id, unEmpleado.nombre, unEmpleado.importe, descSector);
}

void mostrarJuegos(eJuegos lista[], int tam, eCategoria sectores[], int tamSector)
{

    system("cls");
    printf("Codigo  Importe  Categoria\n\n");

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

void altaJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector)
{
    int indice;
    int id;
    int existe;
    int idJuegos;
    eJuegos nuevoJuego;

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

            nuevoJuego.id = id;

            /*printf("Ingrese tipo de juego: ");
            fflush(stdin);
            gets(nuevoJuego.nombre);*/
            printf("Ingrese importe: ");
            fflush(stdin);
            scanf("%f", &nuevoJuego.importe);

            listarSectores(sectores, tamSector);

            printf("\nIngrese descripcion: ");
            scanf("%d", &idJuegos);

            nuevoJuego.idJuegos = idJuegos;


            nuevoJuego.isEmpty = 0;

            lista[indice] = nuevoJuego;

        }
    }

}


void bajaJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector)
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

void ModificarJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector)
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

        {1111, "Spiderman", 'm', 23000,1,0},
        {2222, "Mortal Kombat", 'm', 18000, 1, 0},
        {1234, "NFS", 'f', 21000, 5,0},
        {5643, "FIFA 19", 'f', 24000, 2, 0},
        {2312, "PES 2019", 'f', 34000, 3, 0},
    };

    for(int i=0; i < 8; i++)
    {

        empleados[i] = x[i];
    }




}

void listarSectores(eCategoria sectores[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);

    }
    printf("\n\n");
}

void obtenerSector(eCategoria sectores[], int tam, int idJuegos, char cadena[])
{

    for(int i=0; i < tam; i++)
    {

        if( sectores[i].id == idJuegos)
        {
            strcpy(cadena, sectores[i].descripcion);
        }
    }

}

void listarJuegosXID(eJuegos x[],int tam, eCategoria sectores[], int tamSector)
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

void ordenarXJuegoYNombre(eJuegos x[],int tam, eCategoria sectores[], int tamSector)
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

void mostrarJuegosMasGanadores(eJuegos x[],int tam, eCategoria sectores[], int tamSector)
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


int buscarLibreCliente(eCliente lista[], int tam)
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
