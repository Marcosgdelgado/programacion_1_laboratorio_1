#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



//a partir de esta funcion puedo crear muchas otras de validacion
int utn_isValidIntNumber(char* pCadena);

int utn_getNumber  (int *pResultado,
                    char *msj,
                    char *msjError,
                    int minimo,
                    int maximo,
                    int reintentos);

int utn_getString  (char *pResultado,
                    char *msj,
                    char *msjError,
                    int minimo,
                    int maximo,
                    int reintentos);

int buscarlibre(char lista[][20], int len,int* pIndex);
int buscanombre(char* pNombre,char lista[][20],int len, int* pIndex);
#endif // UTN_H_INCLUDED

