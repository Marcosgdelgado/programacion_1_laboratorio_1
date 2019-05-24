#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "utn.h"
#define QTY_Persona 100

int main()
{
    Persona* arrayPersona[QTY_Persona];
    Persona* pAux;
    pAux = persona_new();

    altaPersona(arrayPersona,QTY_Persona);

    if(pAux != NULL)
    {
        persona_setId(pAux,44);
        arrayPersona[0] = pAux;
    }


    pAux = persona_new();
    if(pAux != NULL)
    {
        persona_setId(pAux,14);
        arrayPersona[1] = pAux;
    }

    pAux = persona_newParametros(11,111,"Juan");
    if(pAux != NULL)
    {
        arrayPersona[2] = pAux;
    }
    return 0;
}
