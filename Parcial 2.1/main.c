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
    int contadorIdautor=0;                   //cambiar
    int contadorIdlibro=0;

    Autor arrayAutor[QTY_TIPO];
    Libro arrayLibro[QTY_TIPO];
    autor_Inicializar(arrayAutor,QTY_TIPO);                   //cambiar
    libro_Inicializar(arrayLibro,QTY_TIPO);
    do
    {
        utn_getUnsignedInt("\n\n1) Alta autor \n2) Alta Libro \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);                   //cambiar

                break;

            case 2: //Modificar
                libro_alta(arrayLibro,arrayAutor,QTY_TIPO,&contadorIdlibro, QTY_TIPO);
                //autor_modificar(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                libro_listar(arrayLibro,QTY_TIPO);
               // autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
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
