#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

int getString(char *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos);
//***********************************************************************************************
int getNumber(int *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos);
//***********************************************************************************************
int isValidNumber(char* cadena);

#endif // LIBRERIA_H_INCLUDED
