#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "Employee.h"
#include "LinkedList.h"

static int lastId=0;

void entregas_idInit(int id)
{
    lastId=id+1;
}

int entregas_idGenerator()
{
    return lastId++;
}

int entregas_setIdStr(Entregas* this,char* idStr)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL && idStr!=NULL)
    {
        if(utn_isValidInt(idStr))
        {
            bufferId = atoi(idStr);
            if(!entregas_setId(this,bufferId))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setId(Entregas* this,int id)
{
    int ret=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        ret=0;
    }
    return ret;
}

int entregas_getId(Entregas* this,int* id)
{
    int ret=-1;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        ret=0;
    }
    return ret;
}

Entregas* entregas_new()
{
    return (Entregas*)malloc(sizeof(Entregas));
}

int entregas_delete(Entregas* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}



int entregas_setTipo(Entregas* this,char* tipo)
{
    int ret=-1;
    if(this != NULL && utn_isValidName(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        ret=0;
    }
    return ret;
}

int entregas_getTipo(Entregas* this,char* tipo)
{
    int ret=-1;
    if(this!=NULL && tipo!=NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        ret=0;
    }
    return ret;
}


int entregas_setCantidadStr(Entregas* this,char* tipoFotoStr)
{
    int ret=-1;
    int bufferCantidad;
    if(this!=NULL)
    {
        if(utn_isValidInt(tipoFotoStr))
        {
            bufferCantidad = atoi(tipoFotoStr);
            if(!entregas_setCantidad(this,bufferCantidad))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setCantidad(Entregas* this,int cantidad)
{
    int ret=-1;
    if(this!=NULL && cantidad>=0)
    {
        this->cantidad=cantidad;
        ret=0;
    }
    return ret;
}

int entregas_getCantidad(Entregas* this,int* cantidad)
{
    int ret=-1;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        ret=0;
    }
    return ret;
}



int entregas_setPesoStr(Entregas* this,char* precioStr)
{
    int ret=-1;
    int bufferPeso;
    if(this!=NULL)
    {
        if(utn_isValidFloat(precioStr))
        {
            bufferPeso = atof(precioStr);
            if(!entregas_setPeso(this,bufferPeso))
            {
                ret=0;
            }
        }
    }
    return ret;
}

//int entregas_setPeso(Entregas* this,char* precioStr)
//{
//    int ret=-1;
//    int bufferCUIT;
//    if(this!=NULL)
//    {
//        if(utn_(precioStr))
//        {
//            bufferPeso = atof(precioStr);
//            if(!entregas_setPeso(this,bufferPeso))
//            {
//                ret=0;
//            }
//        }
//    }
//    return ret;
//}
int entregas_setPeso(Entregas* this,float peso)
{
    int ret=-1;
    if(this!=NULL && peso>=0)
    {
        this->peso=peso;
        ret=0;
    }
    return ret;
}

int entregas_getPeso(Entregas* this,float* peso)
{
    int ret=-1;
    if(this!=NULL && peso!=NULL)
    {
        *peso=this->peso;
        ret=0;
    }
    return ret;
}


int entregas_setCUITstr(Entregas* this,char* CUITstr)
{
    int ret=-1;
    int bufferCUIT;
    if(this!=NULL)
    {
        if(isValidCUIT(CUITstr))
        {
            bufferCUIT = atoi(CUITstr);
            if(!entregas_setId(this,bufferCUIT))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setCUIT(Entregas* this,int cuit)
{
    int ret=-1;
    if(this!=NULL && cuit>=0)
    {
        this->cuit=cuit;
        ret=0;
    }
    return ret;
}

int entregas_getCUIT(Entregas* this,int* cuit)
{
    int ret=-1;
    if(this!=NULL&&cuit!=NULL)
    {
        *cuit=this->cuit;
        ret=0;
    }
    return ret;
}

Entregas* entregas_newParametros(char* idStr,char* fechaStr,char* tipoFotoStr,char* precioStr, char* CUITstr, char* pepito)
{
    Entregas* aux;
    aux=entregas_new();
    if(aux!=NULL)
    {
        if(entregas_setIdStr(aux,idStr)||entregas_setTipo(aux,fechaStr)||entregas_setCantidadStr(aux,tipoFotoStr)||entregas_setPesoStr(aux,precioStr)||entregas_setCUITstr(aux,CUITstr))
        {
            entregas_delete(aux);
            aux=NULL;
        }
    }
    return aux;
}
