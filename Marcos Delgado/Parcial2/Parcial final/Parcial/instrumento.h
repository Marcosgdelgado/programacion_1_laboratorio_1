#ifndef instrumento_H_INCLUDED
#define instrumento_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idInstrumento;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    int tipoInstrumento;
//    float varFloat;
//    char varChar;
    char varLongString[TEXT_SIZE];

}Instrumento;


#endif // instrumento_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);                                    //cambiar fantasma
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);                    //cambiar fantasma
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
int instrumento_buscarInt(Instrumento array[], int size, int valorBuscado, int* posicion);                    //cambiar fantasma
//int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);                    //cambiar fantasma
int instrumento_alta(Instrumento array[], int size, int* contadorID);                          //cambiar fantasma
int instrumento_baja(Instrumento array[], int size, int sizeLista);                                      //cambiar fantasma
//int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento array[], int size);                                //cambiar fantasma
int instrumento_ordenarPorString(Instrumento array[],int size);                              //cambiar fantasma
int instrumento_listar(Instrumento array[], int size);                      //cambiar fantasma
