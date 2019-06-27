#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "../linkedlist_cascara_v6/inc/LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int r,i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];
        //leo los titulos
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        //Se saco la lectura en falso, ya que sino el primer empleado con indice 1, pasaria
        //a estar en el indice 0 del linked list
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                Employee* p = elemento_newParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));
    }
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    //int r,i;
    Employee* pBinario;

        do{
                pBinario = elemento_new(); //se coloca dentro del do porque sino pisa los otros datos dentro del linkedlist
                if(fread(pBinario,sizeof(Employee),1, pFile)==1) //porque cuento con 1
                {
                    ll_add(pArrayListEmployee,pBinario);
                }
                   else
                   {
                       elemento_delete(pBinario);
                   }


            }while( !feof(pFile));

    return 1;
}
