#ifndef orquesta_H_INCLUDED
#define orquesta_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idOrquesta;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
//    float varFloat;
//    char varChar;
    char varLongString[TEXT_SIZE];
    int tipoOrquesta;

}Orquesta;


#endif // orquesta_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int size);                                    //cambiar Orquesta
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicionOrquesta);                    //cambiar Orquesta
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);                    //cambiar Orquesta
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar Orquesta
int orquesta_baja(Orquesta array[], int sizeArray, int size);                                      //cambiar Orquesta
//int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta array[], int size);                                //cambiar Orquesta
int orquesta_ordenarPorString(Orquesta array[],int size);                              //cambiar Orquesta
int orquesta_listar(Orquesta array[], int size);                      //cambiar Orquesta
void orquesta_hardcodearDatos(Orquesta array[], int size, int* contadorID);
