#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[32];
    char apellido [32];
    int edad;
}Persona;

Persona* persona_new();
Persona* persona_newParametros(int id,int edad,char* nombre);
int persona_delete(Persona* this);

int persona_inicializar(Persona *this);

int persona_buscarLibre(Persona* personas[], int len, int* posicion);
void altaPersona(Persona* lista[], int len);

int persona_setId(Persona* this, int value);
int persona_setLegajo(Persona* this, int value);
int persona_setStatus(Persona* this, int value);
int persona_setNombre(Persona* this, char* value);

int persona_getEdad(Persona* this, int* edad);

int persona_getId(Persona* this, int* value);
int persona_getLegajo(Persona* this, int* value);
int persona_getStatus(Persona* this, int* value);
int persona_getNombre(Persona* this, char* value);

#endif // PERSONAS_H_INCLUDED
