#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"
#include "libro.h"
//cambiar por nombre entidad


#define QTY_TIPO 3

int main()
{
    int opcion;
    //int suboption;
    int contadorIdautor=0;                   //cambiar
    int contadorIdlibro=0;

    Autor arrayAutor[QTY_TIPO];
    Libro arrayLibro[QTY_TIPO];
    autor_Inicializar(arrayAutor,QTY_TIPO);                   //cambiar
    libro_Inicializar(arrayLibro,idAutor,QTY_TIPO);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);

        switch(opcion)
        {
            case 1: //Alta
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);
                libro_alta(arrayLibro,idAutor,QTY_TIPO,&contadorIdlibro);
            break;
            case 2: //Modificar
                     autor_modificar(arrayAutor,QTY_TIPO);
                    libro_modificar(arrayLibro,QTY_TIPO);
                break;

            case 3: //Baja
                autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
                break;
            case 5://Ordenar
                autor_ordenarPorString(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
