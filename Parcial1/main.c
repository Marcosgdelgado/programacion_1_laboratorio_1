#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.H"
#define CANTIDADCLIENTES 9
#define CANTIDADJUEGOS  4

int main()
{   int bandera = 0;
    int menu,idCliente;
    Cliente clientes[CANTIDADCLIENTES];
    abmCliente_init(clientes, CANTIDADCLIENTES);

   do
    {
       get_validInt("MENU\n\n1:Alta Cliente\n2:Modificar Cliente\n3:Baja cliente\n4:Mostrar Cliente \n5: Salir \n ","Ingrese una opcion correcta",&menu,0,9,2);
       fflush(stdin);
       printf("\n %d",menu);
        switch(menu)
        {

        case 1:
            system("cls");
            printf("Cliente Alta\n");
            abmCliente_alta(clientes, CANTIDADCLIENTES);

            break;
        case 2:
            system("cls");
            printf("Ingrese un Codigo de Cliente a Modificar: ");
            scanf("%d", &idCliente);
            fflush(stdin);
            abmCliente_mostrar(clientes, idCliente);
            fflush(stdin);
            abmCliente_modificacion(clientes, CANTIDADCLIENTES, idCliente);
            abmCliente_mostrar(clientes, idCliente);

            break;
        case 3:
            system("cls");
            printf("Ingrese un Codigo de Cliente a Bajar: ");
            scanf("%d", &idCliente);
            abmCliente_baja(clientes, CANTIDADCLIENTES, idCliente);

            break;
        case 4:
            system("cls");
            abmCliente_mostrar(clientes, idCliente);
            break;
        case 5:
            printf("Salir....");
            bandera=1;

            break;
    }
    }while(bandera != 1);

        return 0;
    }
