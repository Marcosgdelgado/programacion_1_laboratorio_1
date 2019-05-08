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

int findEmployee (eEmployee* emp,int id, int len)
{ int ret = -1;
  int i;

    if(emp!= NULL)
    {
     for(i=0;i<len;i++)
     {
         if(emp[i].id==id && emp[i].isEmpty==0)
         {
            ret = i;
            break;
         }
     }
    }
    return ret;

}

int removeEmployee( eEmployee* emp, int len, int id)
{
    int auxId;
    int ret =-1;
    char rta;

    auxId= findEmployee(emp,id,len);
//if(firstEmployee(bandera)!=0){
    if(auxId!=-1)
    {
        do
        {
            printf("Desea eliminar id? S/N:\n");
            rta = toupper(getch());

        }while(rta!='S'&& rta!='N');
        if(rta=='S')
        {
         emp[auxId].isEmpty=1;
         printf("Baja logica realizada\n");
         ret = 0;
        }

        if(rta=='N')

        {
            printf("La baja no se realizo\n");
        }
    }else{printf("NO existe id\n");}
    return ret;
}
int firstEmployee(int flag){
    int ret=-1;
    if(flag!=1){
        system("cls");
        printf("___________________________________________________________________\n");
        printf("ERROR! Debera realizar la carga de un empleado\n");
        printf("___________________________________________________________________\n");
        ret=0;
    }
    return ret;
}

int printEmployee(eEmployee* emp,int len)
{
    int  ret=-1;
    int i;

    for(i=0;i<len;i++)
    {
        if(emp[i].isEmpty==0)
        {
            printf("%d\n%s\n%s\n%.2f\n%d\n",emp[i].id,emp[i].name,emp[i].lastName,emp[i].salary,emp[i].sector);
            ret = 0;
        }
    }
 return ret;
}

int sortEmployee(eEmployee* emp,int len,char* name, char* lastName,int opcion)
{
    eEmployee empAux;
    int i, j;
    if(opcion==1){
        for(i=0;i<len-1;i++){
                for(j=i;j<len;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(emp[i].sector>emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0;i<len-1;i++){
            for(j=i;j<len;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(strcmp(emp[i].lastName,emp[j].lastName)>0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }

    if(opcion==0){
        for(i=0;i<len-1;i++){
            for(j=i;j<len;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(emp[i].sector<emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0;i<len-1;i++){
            for(j=i;j<len;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(strcmp(emp[i].lastName,emp[j].lastName)<0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }
    return 0;
}


void modifyEmployee(eEmployee *emp,int len,char* nombre,
                    char* apellido, float salario,int sk,int id,int Modif)
        {
            if(Modif==1)
            strcpy(emp[id].name,nombre);
            if(Modif==2)
            strcpy(emp[id].lastName,apellido);
            if(Modif==3)
            emp[id].salary=salario;
            if(Modif==4)
            emp[id].sector=sk;
}








