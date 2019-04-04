#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void prueba(void);
int utn_getnumber(int*,int,int,char*,char*, int);
void mostrarArrays(char,int);
int utn_getNumero(int*, char*, char*, int, int, int);

int utn_getarrayInt(    int* pArrayResultados,
                        int limite,
                        const char *mensaje,
                        const char *mensajeError,
                        int minimo,
                        int maximo,
                        int reintentos);

int calcularpromedio(int *pArrayInt, int limite, float *pResultado);
#endif // UTN_H_INCLUDED


