#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libreria.h"

//int getString(char *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos);
//***********************************************************************************************
//int getNumber(int *resultado, char *msg, char *msgError,int minimo,int maximo, int reintentos);
//***********************************************************************************************
//int isValidNumber(char* cadena);

int main()
{
    int numero;

    getNumber(numero,"Ingrese un numero","Error",1,10,1);
    printf("%d", numero);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int val;
   char str[20];

   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   return(0);
}*/
