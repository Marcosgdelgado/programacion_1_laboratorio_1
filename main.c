#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10



typedef struct{
    int legajo;
    char sexo;
    char nombre[20];
    float sueldo;
    int isEmpty;
}eEmpleado;
int menu();
void inicializarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);

int main()
{
    char seguir = 's';
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados, TAM);
do{
    switch(menu()){
case 1:
        printf("\nalta\n");
        system("pause");
    break;
case 2:
        printf("\nbaja\n");
        system("pause");
    break;
    case 3:
        printf("\nmodifica\n");
        system("pause");
    break;
    case 4:
        printf("\nListar\n");
        system("pause");
    break;
    case 5:
        printf("\nOrdenar\n");
        system("pause");
    break;
    case 6:
        printf("\nSalir\n");
        system("pause");
        seguir='n';
    break;
    }

}while(seguir== 'S');

 return 0;
}

int menu(){
int opcion;

system("cls");

printf("\n*** Menu ***\n\n");
printf(" 1- Alta\n");
printf(" 2- Baja\n");
printf(" 3- Modificacion\n");
printf(" 4- Listar empleados\n");
printf(" 1- Ordenar empleado\n");
printf(" 6- Salir\n\n");
scanf("%d", &opcion);

return opcion;
}
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for (int i=0; i < tam; i++){
        lista[i].isEmpty=1;
    }
}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d %s %c %.2f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo);

}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    system("cls");
    printf("Legajo nombre sexo sueldo \n\n");

    for(int i = 0; i < tam ; i++){
        if(lista[i].isEmpty == 0){
            mostrarEmpleado(lista[i]);
        }
    }

}
int buscarlibre(eEmpleado lista[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam ; i++){

        if(lista[i].isEmpty == 1){
            indice =i;
            break;
        }

    }

    return indice;
}
  int buscarEmpleado(eEmpleado lista[],int tam, int legajo)
  {


    int indice= -1;
    for(int i = 0; i < tam ; i++){

        if( lista[i].legajo == legajo && lista[i].isEmpty == 1){
            indice =i;
            break;
        }

    }
    return indice;
  }
void altaEmpleado (eEmpleado lista[], int tam){


int indice;
int legajo;
char sexo;
char nombre[tam];
float sueldo;
int existe;
eEmpleado nuevoEmpleado;

indice = buscarlibre(lista, tam);
system("cls");
printf("*** Alta empleado ***\n\n");

if (indice = -1){

    printf("No hay lugar en el sistema\n\n");
}
else{
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    existe= buscarEmpleado(lista, tam, legajo);

    if(existe != -1){
        printf("Ya existe empleado con ese Nº de legajo.\n %d", legajo);
        mostrarEmpleado(lista[existe]);

    }
    else {
        nuevoEmpleado.legajo = legajo;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nuevoEmpleado.nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &nuevoEmpleado.sexo);
        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%f", &nuevoEmpleado.sueldo);

        nuevoEmpleado.isEmpty = 0;
        lista[indice]=nuevoEmpleado;
    }
}



}

void bajaEmpleado (eEmpleado lista[], int tam)
{
    int legajo;
    int indice;
    char seguir;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista,tam,legajo);

    if (indice == -1){
        printf("No hay ningun empleado con ese Nº de legajo %d\n\n ", legajo);
        system("pause");
    }else{
        mostrarEmpleado(lista[indice]);

        printf("\nConfirmar borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

    if(seguir)

    }




}
