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

    eEmployee emp[lista_tam];

   do{
        utn_getEntero(&opcion,"Ingrese un numero entre 1 y 5:\n","ERROR!\n",1,5,3);

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
                 printf("%d\n%s\n%s\n%.2f\n%d\n",id,auxNombre,auxApellido,auxSalario,auxSector);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {

                break;
            }
        }

    }while(opcion!=5);
}
