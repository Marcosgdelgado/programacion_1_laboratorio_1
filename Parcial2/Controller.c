#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "input.h"
#include "../linkedlist_cascara_v6/inc/LinkedList.h"

int menu(void){
int option;
printf("Menu trabajo practico numero 3");
printf("\nSeleccione 1- Para cargar los datos de los empleados en modo texo");
printf("\nSeleccione 2- Para cargar los datos de los empleados en modo binario");
printf("\nSeleccione 3- Para dar de alta un empleado");
printf("\nSeleccione 4- Para modificar los datos de un empleado");
printf("\nSeleccione 5- Para dar de baja un empleado");
printf("\nSeleccione 6- Para imprimir la lista de empleados");
printf("\nSeleccione 7- Para ordenar la lista de empleados");
printf("\nSeleccione 8- Para guardar los datos de los empleados en modo texto");
printf("\nSeleccione 9- Para guardar los datos de los empleados en modo binario");
printf("\nSeleccione 10- Para guardar los datos de los empleados en TXT");
printf("\nSeleccione 11- Para salir del programa");
printf("\nOpcion elegida: ");
scanf("%d",&option);
return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL)
    {
        printf("Error al leer el archivo");
    }
    else
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    if((pArchivo = fopen(path,"rb")) == NULL)
    {
        printf("Error al abrir el archivo");
    }
    else
    {
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
        fclose(pArchivo);
    }

return 0;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* pB;
   int resp,cant;
   char var1[50],var3[50],var2[50],var4[50];
   resp = 1;
   while (resp == 1){
        cant = ll_len(pArrayListEmployee);
        sprintf(var1,"%d",cant);
        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        getString(var2);
        printf("\nIngrese las horas trabajadas del empleado: ");
        fflush(stdin);
        getString(var3);
        printf("\nIngrese el sueldo del empleado: ");
        fflush(stdin);
        getString(var4);
        pB = elemento_newParametros(var1,var2,var3,var4);
        ll_add(pArrayListEmployee,pB);
        printf("\nPara continuar ingresando datos ingrese 1 : ");
        getInt(&resp);
        system("cls");
   }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int codigo,resp;
    char auxNombre[51];
    int auxSueldo,auxHoras;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el codigo del empleado a modificar: ");
    getInt(&codigo);
    if (pArrayListEmployee != NULL){
        puntero = ll_get(pArrayListEmployee,codigo);
        printf("1-Para modificar el Nombre\t 2-Para el Sueldo\t 3-Para las Horas Trabajadas");
        getInt(&resp);
        switch(resp){
            case 1:
                printf("\nIngrese el nombre a asignar");
                getString(auxNombre);
                elemento_setTipo(puntero,auxNombre);
                break;
            case 2:
                printf("\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                elemento_setSueldo(puntero,auxSueldo);
                break;
            case 3:
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                elemento_setHorasTrabajadas(puntero,auxHoras);
                break;
            case 4:
                printf("\n\nIngrese el nombre a asignar");
                getString(auxNombre);
                elemento_setTipo(puntero,auxNombre);
                printf("\n\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                elemento_setSueldo(puntero,auxSueldo);
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                elemento_setHorasTrabajadas(puntero,auxHoras);
                break;
        }
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant,codigo,resp;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el codigo del empleado a borrar: ");
    getInt(&codigo);
    if (pArrayListEmployee != NULL){
        cant = ll_len(pArrayListEmployee);
        if (codigo >0 && codigo <= cant){
            puntero = ll_get(pArrayListEmployee,codigo);
            free(puntero);
            ll_remove(pArrayListEmployee,codigo);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
        }
        else{
            printf("\nEl codigo debe estar entre 1 y %d\n\n",cant);
            system("pause");
            system("cls");
        }
    }
    else{
        printf("\n\nError al eliminar el registro \n\n");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    printf("\nID\t Tipo\t Cantidad\t Peso\n");
    for (i=1;i<2;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t\t %.2f\n",elemento_getId(lista),elemento_getNombre(lista),elemento_getHorasTrabajadas(lista),elemento_getSueldo(lista));
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int i,j,len;
    Employee* actualEmpleado;
    Employee* empSiguiente;
    Employee* auxiliar;
    len = ll_len(pArrayListEmployee);
    for (i=1;i<len;i++){
        actualEmpleado = ll_get(pArrayListEmployee,i);
        for(j=i+1;j<len;j++){
            empSiguiente = ll_get(pArrayListEmployee,j);
            if (elemento_getSueldo(actualEmpleado) > elemento_getSueldo(empSiguiente)){
                auxiliar = actualEmpleado;
                actualEmpleado = empSiguiente;
                empSiguiente = auxiliar;
            }
        }
    }
    return 1;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)//serializar escribir en el archivo lo que esta en memoria
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"r+b");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+b");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

int controller_saveAstxt(char* path , LinkedList* this)//serializar escribir en el archivo lo que esta en memoria
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(this);
    pArchivo = fopen(path,"w+");
    if(this!= NULL && pArchivo!=NULL)
    {
        if (len>0)
        {


             fprintf(pArchivo,"ID\tTipo\tCantidad\tPeso\n");
            for (i=0;i<len;i++){
            auxEmpleado = ll_get(this,i);
            fprintf(pArchivo,"%d\t%s\t%d\t\t%.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            total++;
            }
        printf("\nSe escribieron %d caracteres\n\n", total);
        }

    fclose(pArchivo);
    }
    return 1;
}

//int controller_saveAsTexTo(char* path, LinkedList* this)
//{
//    Employee* bufferEntregas;
//    FILE* pf;
//    char bufferTipo[128];
//    int bufferCantidad;
//    float bufferPeso;
//
//    int cantidadTotal=0;
//    int cantidadSTD=0;
//    int cantidadEXP=0;
//    int cantidadECO=0;
//    int cantidadMaxima=0;
//    float cantidadPromedio=0;
//    float pesoPromedio=0;
//    int i;
//    int ret=0;
//    int len;
//    pf=fopen(path,"w");
//    if(this!=NULL && pf!=NULL)
//    {
//
//        len=ll_len(this);
//        for(i=0; i<len; i++)
//        {
//            bufferEntregas=(Employee*)ll_get(this,i);
//            strcpy(bufferTipo, elemento_getNombre(this));
//            strcmp(bufferCantidad, elemento_getHorasTrabajadas(this));
//            //strtod((elemento_getSueldo(this),bufferPeso);
//            elemento_getSueldo(this);
//            cantidadTotal=cantidadTotal+bufferCantidad;
//            pesoPromedio=pesoPromedio+bufferPeso;
//            if(!strcmp(bufferTipo,"STD"))
//            {
//                cantidadSTD=cantidadSTD+1;
//            }
//            if(!strcmp(bufferTipo,"EXP"))
//            {
//                cantidadEXP=cantidadEXP+1;
//            }
//            if(!strcmp(bufferTipo,"ECO"))
//            {
//                cantidadECO=cantidadECO+1;
//            }
//            if(cantidadMaxima<bufferCantidad)
//            {
//                cantidadMaxima=bufferCantidad;
//            }
//
//        }
//        cantidadPromedio=(float) cantidadTotal/len;
//        pesoPromedio=pesoPromedio/len;
//        fprintf(pf,"/*********************\n");
//        fprintf(pf,"Informe de ventas\n");
//        fprintf(pf,"********************\n");
//        fprintf(pf,"- Cantidad total de entregas: %d\n",cantidadTotal);
//        fprintf(pf,"- Cantidad de entregas por tipo: %d (STD) - %d (EXP) - %d (ECO)\n",   cantidadSTD,
//                                                                                        cantidadEXP,
//                                                                                        cantidadECO);
//        fprintf(pf,"- Cantidad maxima de bultos entregados: %d\n",cantidadMaxima);
//        fprintf(pf,"- Promedio de bultos por entrega: %.2f\n",cantidadPromedio);
//        fprintf(pf,"- Peso promedio por entrega: %.2f\n",pesoPromedio);
//        fprintf(pf,"*********************/\n");
//        fclose(pf);
//    }
//    return ret;
//}
