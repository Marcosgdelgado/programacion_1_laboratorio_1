#include <stdio.h>
#include <stdlib.h>
#include "Herramientas.h"
#include "Empleados.h"
#define lista_tam 2
#define Max_Char 51

int main()
{
    int opcion=0;
    int flag = 0;
    int posicion;
    int id=0;
    char auxNombre[Max_Char];
    char auxApellido[Max_Char];
    float auxSalario;
    int auxSector;
    int auxIdeliminar;
    int encontrarAux;
    int Modif;
    int idBaja;
    eEmployee emp[lista_tam];

   do{
        utn_getEntero(&opcion,"Ingrese un numero:\n1- ALTA\n2- BAJA\n3- Mostrar lista\n4-\n5- SALIR\n","ERROR!\n",1,5,3);

        switch(opcion)
        {
            case 1:
            {

                printf("ALTA:\n");
                if(flag==0)
                {if(initEmployee(emp,lista_tam)==0)
                {
                    initEmployee(emp,lista_tam);
                    flag=1;
                }
                }
                if(freeSpace(emp,lista_tam,&posicion)!=-1)
                {
                    id++;
                }else
                     {printf("\nNo queda espacio para guardar empleados.\n");
                        break;
                     }
                 utn_getStringAvanzado(auxNombre,"Ingrese nombre\n","ERROR",Max_Char,3);
                 utn_getStringAvanzado(auxApellido,"Ingrese apellido\n","ERROR",Max_Char,3);
                 utn_getFlotante(&auxSalario,"Ingrese salario\n","ERROR",1,100000000,3);
                 utn_getEntero(&auxSector,"Ingrese sector\n","ERROR",0,5,3);
                 addEmployee(emp,lista_tam,id,auxNombre,auxApellido,auxSalario,auxSector);

                 system("cls");
                break;
            }
            case 2:
            {   system("cls");
                printf("BAJA\n");
                if (firstEmployee(flag)==-1){
                printEmployee(emp,lista_tam);
                utn_getEntero(&idBaja, "Ingrese id a eliminar", "Error el id es incorrecto", 0, lista_tam, 5);
                auxIdeliminar= findEmployee(emp, idBaja, lista_tam);
                if(auxIdeliminar!=-1){
                removeEmployee(emp,lista_tam,idBaja);
                system("cls");
                printf("Empleado eliminado correctamente\n");
                system("PAUSE");
                system("cls");
                }
                else{
                        system("cls");
                        printf("No se encuentra el ID\n");
                    }
                   }
                break;
            }
            case 3:
            {
                system("cls");

                if(firstEmployee(flag)!=0){ //si no es la primera vez
                    printEmployee(emp,lista_tam);
                    utn_getEntero(&id,"Ingrese ID a modificar: ","ERROR! Ingrese numero entre 1 y 1000\n",0,1000,2);
                    encontrarAux=findEmployee(emp,id,lista_tam);
                    if(encontrarAux!=-1){ //si lo encontro
                        printf("1- Ingrese Nombre\n");
                        printf("2- Ingrese apellido\n");
                        printf("3- Ingrese Salario\n");
                        printf("4- Ingrese Sector\n\n");
                        utn_getEntero(&Modif,"Ingrese valor que desea modificar\n\n",
                                      "ERROR! Ingrese numero entre 1 y 5\n",1,5,2);
                        switch(Modif){
                            case 1:
                                utn_getStringAvanzado(auxNombre,"Ingrese nombre: ",
                                                      "ERROR! El nombre debe ser solo letras\n",lista_tam,2);
                                modifyEmployee(emp,lista_tam, auxNombre, auxApellido, auxSalario,auxSector,encontrarAux,Modif);
                            break;
                            case 2:
                                utn_getStringAvanzado(auxApellido,"Ingrese apellido: ",
                                                      "ERROR! El apellido debe ser solo letras\n",lista_tam,2);
                                modifyEmployee(emp,lista_tam, auxNombre, auxApellido, auxSalario,auxSector,encontrarAux,Modif);
                            break;
                            case 3:
                                utn_getFlotante(&auxSalario,"Ingrese salario: ",
                                                "ERROR! Ingrese salario positivo\n",1,100000,2);
                                modifyEmployee(emp,lista_tam, auxNombre, auxApellido, auxSalario,auxSector,encontrarAux,Modif);
                            break;
                            case 4:
                                utn_getEntero(&auxSector,"Ingrese sector: ",
                                              "ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
                                modifyEmployee(emp,lista_tam, auxNombre, auxApellido, auxSalario,auxSector,encontrarAux,Modif);
                            break;
                            system("cls");
                            printf("Empleado modificado correctamente\n");
                        }
                    }
                    else{
                        system("cls");
                        printf("No se encuentra el ID\n");
                    }
                }
                break;
            }
            case 4:
            {

                break;
            }
        }

    }while(opcion!=5);
}
