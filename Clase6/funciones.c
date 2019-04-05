#include <stdio.h>
#include <stdlib.h>
static int esNumerica(char* cadena)
 {
 int ret=-1;
 int i=0;
 if(cadena!=NULL)
 {
 while(cadena[i]!='\0')
 {
 if(cadena[i]<'0' || cadena[i]>'9')
 break;
 i++;
 }
 if(cadena[i]=='\0')
 ret=1;
 }
 return ret;
 }

static int getInt(int* pResultado)
 {
 int ret=-1;
 char buffer[64];
 scanf("%s",buffer);
 if(esNumerica(buffer))
 {
 *pResultado = atoi(buffer);
 ret=1;
 }
 return ret;
 }

int getNumero(int* pResultado,
 char* mensaje,
 char* mensajeError,int* pResultadodos,
 char* mensajedos,
 int minimo,
 int maximo,
 int reintentos)
 {
 int ret;
 int num;
 int retdos;
 int numdos;
 while(reintentos>0)
 {
 printf(mensaje);
 if(getInt(&num)==1)
// if(scanf("%d",&num)==1)
 {
 if(num<=maximo && num>=minimo)
 break;
 }
 fflush(stdin);
 reintentos--;
 printf(mensajeError);
 printf(mensajedos);
 if(getInt(&numdos)==1)
// if(scanf("%d",&num)==1)
 {
 if(numdos<=maximo && numdos>=minimo)
 break;
 }
 fflush(stdin);
 reintentos--;
 printf(mensajeError);

 }
 if(reintentos==0)
 {
 ret=-1;
 }
 else
 {
 ret=0;
 *pResultado = num;
 }
 return ret;
 return retdos;
 }


 //void imprint(char*txt)
 /*int i=0;
 while(txt[i]!='\0')
 {
    printf("%c",txt[i]);
    i++;
 }
 */

