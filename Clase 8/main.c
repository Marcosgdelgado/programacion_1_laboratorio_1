#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define A 3



int main()
{
    sAlumno listadoMain[A];

    cargarListadodeAlumnos(listadoMain, A);

    mostrarListado(listadoMain, A);

    printf("ordenad\n");

    ordenarAlumnoporNombre(listadoMain, A);

    mostrarListado(listadoMain, A);

    /*printf("ingrese legajo: ");
        scanf("%d", &listadoMain[i].legajo );
    printf("ingrese nombre: ");
        fflush(stdin);
        gets(listadoMain[i].nombre);
    printf("ingrese promedio: ");
        scanf("%f", &listadoMain[i].promedio);
    printf("ingrese edad: ");
        scanf("%d", listadoMain[i].edad );*/


return 0;

}

/*int main()
{
    sAlumno mialumno; //={222, "Diego", 2.22};
    mialumno = pedirAlumno();

    system("cls");
    mostrarUnAlumno(mialumno);*/
    //sAlumno otroAlumno;


   /* printf("ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &mialumno.legajo );
    printf("ingrese nombre: ");
        fflush(stdin);
        gets(mialumno.nombre);
    printf("ingrese promedio: ");
        fflush(stdin);
        scanf("%f", &mialumno.promedio );
    printf("ingrese edad: ");
        fflush(stdin);
        scanf("%d", &mialumno.edad );*/
    //otroAlumno = mialumno;
    //system("cls");
    //mostrarUnAlumno(mialumno);
    //strset(otroAlumno, mialumno);

    //printf("%d\n%s\n%.2f", otroAlumno.legajo, otroAlumno.nombre, otroAlumno.promedio);

    /*return 0;
}*/






