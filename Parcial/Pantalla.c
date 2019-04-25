#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "Utn_String.h"
#define Nombre_LEN 20


int pantalla_inicializar(Pantalla *arrayPantalla,int len)
{
    int i;
    int ret=-1;
    if(arrayPantalla != NULL && len >= 0)
    {
        for(i=0;i<len;i++)
        {
            arrayPantalla[i].isEmpty=1;
            ret=0;
        }
    }
    return ret;
}
int pantalla_lugarLibre(Pantalla *arrayPantalla,int len,int *lugarLibre)
{
    int i;
    int ret=-1;
    if(arrayPantalla != NULL && len >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayPantalla[i].isEmpty==1)
            {
                *lugarLibre = i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int pantalla_alta(Pantalla *arrayPantalla,int len)
{
    int ret=-1;
    int lugarLibre;
    char auxNombre[Nombre_LEN];
    char auxDireccion[30];
    if(arrayPantalla != NULL && len >= 0)
    {
        if(pantalla_lugarLibre(arrayPantalla,30,&lugarLibre)==0)
        {
           printf("%d",lugarLibre);
           if(getString(auxNombre,"Ingrese un nombre: ", "ERROR!", 1, Nombre_LEN, 2)==0)
              {
                strcpy(arrayPantalla[lugarLibre].nombre,auxNombre);
              }
            if(getString(auxDireccion," Ingrese direccion: ", "ERROR!", 1, Nombre_LEN, 2)==0)
              {
                strncpy(arrayPantalla[lugarLibre].direccion,auxDireccion,Nombre_LEN);
              }
            printf("%s,%s",arrayPantalla[lugarLibre].direccion,arrayPantalla[lugarLibre].nombre);
            arrayPantalla[lugarLibre].isEmpty=-1;
            ret=0;
        }

    }
    return ret;
}



