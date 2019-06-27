#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "input.h"
#include "LinkedList.h"

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
 * \param this LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* this)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL)
    {
        printf("Error al leer el archivo");
    }
    else
    {
        parser_EmployeeFromText(pArchivo,this);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* this)
{

    int i,cant;
    cant = ll_len(this);
    Entregas* lista;
    char bufferCUIT;
    printf("\nID\t Tipo\t Cantidad\t Peso\n");
    for (i=0;i<cant;i++)
    {
        lista = (Entregas*)ll_get(this,i);
        entregas_setCUITstr(lista,bufferCUIT);
        printf("%d\n",bufferCUIT);
        //printf("%d\t %s\t %d\t\t %.2f\n",entregas_getId(lista,id),entregas_getNombre(lista),entregas_getHorasTrabajadas(lista),entregas_getSueldo(lista));
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* this)//serializar escribir en el archivo lo que esta en memoria
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Entregas* auxEmpleado;
    len = ll_len(this);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL)
        {
            pArchivo = fopen(path,"w+");
        }
    if (len>0)
        {
            for (i=0;i<len;i++){
            auxEmpleado = ll_get(this,i);
            fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->tipo,auxEmpleado->cantidad,auxEmpleado->peso);
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
 * \param this LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* this)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Entregas* auxEmpleado;
    len = ll_len(this);
    pArchivo = fopen(path,"r+b");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+b");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(this,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->tipo,auxEmpleado->cantidad,auxEmpleado->peso);
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
    Entregas* auxEmpleado;
    len = ll_len(this);
    pArchivo = fopen(path,"w+");

    if(this!= NULL && pArchivo!=NULL)
    {
        printf("IMPRIME");
        if (len>0)
        {

             fprintf(pArchivo,"ID\tTipo\tCantidad\tPeso\n");
            for (i=0;i<len;i++){
            auxEmpleado = ll_get(this,i);
            printf("faltandatos");
            fprintf(pArchivo,"%d\n",entregas_setCUITstr(auxEmpleado,auxEmpleado->cuit));
            //fprintf(pArchivo,"%d\t%s\t%d\t\t%.2f\t%d\tn",entregas_getCUIT(),auxEmpleado->id,auxEmpleado->tipo,auxEmpleado->cantidad,auxEmpleado->peso,auxEmpleado->cuit);
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
//    Entregas* bufferEntregas;
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
//            bufferEntregas=(Entregas*)ll_get(this,i);
//            strcpy(bufferTipo, entregas_getNombre(this));
//            strcmp(bufferCantidad, entregas_getHorasTrabajadas(this));
//            //strtod((entregas_getSueldo(this),bufferPeso);
//            entregas_getSueldo(this);
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
