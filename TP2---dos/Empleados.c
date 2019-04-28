#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Empleados.h"


int initEmployee(eEmployee* emp,int maxEmp)
{
    int i;
    int ret=-1;

    if ((emp!=NULL) && (maxEmp>=0))
    {
        for(i=0;i<maxEmp;i++)
        {
            emp[i].isEmpty=1;
        }
        ret=0;
    }
    return ret;
}


int freeSpace (eEmployee* emp, int maxEmp, int *freePosition)
{
    int i;
    int ret=-1;

    if ((emp!=NULL) && (maxEmp>=0))
    {
        for (i=0;i<maxEmp;i++)
            {
                if(emp[i].isEmpty)
                {
                     *freePosition = i;
                     ret=0;
                     break;
                }
            }
    }
return ret;
}


int addEmployee(eEmployee *emp, int maxEmp, int id, char *nombre, char *apellido, float salario, int sector)
{
    int i;
    int ret=-1;
   int position;

   i = freeSpace(emp, maxEmp, &position);

     if(i!=-1)
     {
         emp[i].isEmpty = 0;
         strcpy(emp[position].name,nombre);
         strcpy(emp[position].lastName,apellido);
         emp[position].salary = salario;
         emp[position].sector = sector;
         emp[position].id = id;
         ret=0;
     }
return ret;
}


















