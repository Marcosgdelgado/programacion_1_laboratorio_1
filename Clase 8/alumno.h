
#include "alumno.h"


typedef struct
{
    int legajo;
    char nombre[30];
    float promedio;
    int edad;


}sAlumno;

void mostrarUnAlumno(sAlumno);
sAlumno pedirAlumno();
void cargarListadodeAlumnos(sAlumno[], int);
void mostrarListado(sAlumno[],int);
void ordenarAlumnoporNombre(sAlumno[],int);
