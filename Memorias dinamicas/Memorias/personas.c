#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "personas.h"
#define QTY_Persona 100

static int cont=0;
static int generarId(void)
{
    cont++;
    return cont;
}

void persona_inicializarId(int val)
{
    cont = val;
}

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(int id,int legajo,char* nombre)
{
    return NULL;
}

/*int persona_inicializar(Persona *this)
{
    int retorno = -1;
    int i;

    if(persona_new()!=NULL && QTY_Persona>0)
    {
        for(i=0;i>QTY_Persona;i++)
        {
            persona_new();
        }
    retorno = 0;
    }
    return retorno;
}*/
int persona_initArray(Persona* personas[], int len)
{
    int i;
    int retorno=-1;
    if(personas!=NULL)
    {
        retorno=0;
        for(i=0;i<len;i++)
        {
            personas[i]=NULL;
        }
    }
    return retorno;
}

int persona_buscarLibre(Persona* personas[], int len, int* posicion)
{
    int retorno=-1;
    int i;
    if(personas!= NULL && len>=0 && posicion!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(personas[i]==NULL)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;




}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setId(Persona* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}


int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int persona_setNombre(Persona* this, char* nombre)
{
    if (this!=NULL && nombre !=NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
    }
    return -1;
}

int persona_getEdad(Persona* this, int* pEdad)
{
    if(this!=NULL && pEdad!=NULL)
    {
        *pEdad=this->edad;
        return 0;
    }
    return -1;
}

void altaPersona(Persona* lista[], int len)
{
    char auxNombre;
    int auxEdad;
    int auxId;
    int posLibre;

    utn_getName("Ingrese Nombre: ","Quilombo!",0,100,3,&auxNombre);

    Persona* p= persona_newParametros();
    //persona_setId(p,generarId());
    persona_buscarLibre(lista,len,&posLibre);
    lista[posLibre]=p;
}


