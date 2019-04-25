#ifndef UTN_STRING_H_INCLUDED
#define UTN_STRING_H_INCLUDED

//int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

//a partir de esta funcion puedo crear muchas otras de validacion
int utn_isValidIntNumber(char* cadena);
int validarLetra (char letras[]);
int utn_getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);
int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);


#endif // UTN_STRING_H_INCLUDED
