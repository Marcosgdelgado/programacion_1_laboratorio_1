#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define A 3

sAlumno pedirAlumno()
{
     sAlumno alumnito;

     printf("ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &alumnito.legajo );
    printf("ingrese nombre: ");
        fflush(stdin);
        gets(alumnito.nombre);
    printf("ingrese promedio: ");
        fflush(stdin);
        scanf("%f", &alumnito.promedio );
    printf("ingrese edad: ");
        fflush(stdin);
        scanf("%d", &alumnito.edad );
        return alumnito;
}

void mostrarUnAlumno(sAlumno miAlumno)
{


    printf("%d\n%s\n%.2f\n%d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.edad);

}
}
void cargarListadodeAlumnos(sAlumno listado[], int tam)
{int i;
     for(i=0;i<tam; i++)
        {
            listadoMain[i]=pedirAlumno();
        }
}

void mostrarListado(sAlumno[],int tam)
{
    int i;
    for(i=0;i<tam; i++)
        {
            mostrarUnAlumno(listadoMain[i]);
        }
}
void ordenarAlumnoporNombre(sAlumno listado[], int tam)
{
    auxAlumno

    for(int i=0;i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0){

                auxAlumno = listado[i];
                listado[j] = listado[j];
                listado[j]= auxAlumno;
                //auxint = listado[i].legajo;
                //listado[i].legajo = auxint;<---|
                // ESTO NO SE HACE --------------|
            }
        }
    }
}

