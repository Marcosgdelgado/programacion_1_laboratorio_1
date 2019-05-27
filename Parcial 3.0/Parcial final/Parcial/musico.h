#ifndef musico_H_INCLUDED
#define musico_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idMusico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    //float varFloat;
    //char varChar;
    char varLongString[TEXT_SIZE];
    int idOrquesta;
    int idInstrumento;
    int edadMusico;

}Musico;


#endif // musico_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
int musico_Inicializar(Musico array[], int size);                                    //cambiar fantasma
int musico_buscarEmpty(Musico array[], int size, int* posicionMusico);                    //cambiar fantasma
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicionMusico);                    //cambiar fantasma
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicionMusico);                    //cambiar fantasma
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int musico_alta(Musico array[], int size, int* contadorID,Orquesta arrayOrq[], int sizeOrq,Instrumento arrayInstrumento[], int sizeIns);                          //cambiar fantasma
int musico_baja(Musico array[], int size, int sizeLista);                                      //cambiar fantasma
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray, Orquesta arrayOrquesta[], int sizeOrq);                                //cambiar fantasma
int musico_ordenarPorString(Musico array[],int size);                              //cambiar fantasma
int musico_listar(Musico array[], int size,Instrumento arrayInstrumento[], int sizeIns);                      //cambiar fantasma
void harcodearMusicos(Musico array[],int size,int*contadorID);
