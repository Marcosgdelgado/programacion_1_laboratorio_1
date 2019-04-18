#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#define LEN_LISTA    100



int main()
{
    Empleado arrayEmpleados[LEN_LISTA];

    int opcion;
    char nombres[LEN_LISTA][20];

    int i;
    int posLibre;
    char buffer[20];
    int posicionaeliminar;

    for(i=0; i<LEN_LISTA; i++)
        nombres[i][0] = '\0';

    while(1)
    {

        utn_getNumber(&opcion,
                      "1)ingresar\n2)listar\n4)borrar\n",
                      "NO!",
                      1,10,2);

        printf("elegiste:%d\n",opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("agregar nombre\n");
                if(buscarlibre(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("1.se encontro lugar en %d\n",posLibre);
                    //utn_getString(buffer,"ingrese:","no!",0,20,1);
                    fgets(buffer,20,stdin);
                        printf("se ingreso:%s",buffer);
                        //lo que no va ->nombres[posLibre]=buffer;
                        strncpy(nombres[posLibre],buffer,20);
                        //strncpy(nombres[1],"HOL",20);
                        //strncpy(nombres[2],"OLA",20);
                        for (i=0;i<10;i++)
                            printf("%d: %s\n",i,nombres[i]);
                }
                break;
            }
            case 4:
            {
                fgets(buffer,20,stdin);buffer[strlen(buffer)];

                buscanombre(buffer,nombres,LEN_LISTA,&posicionaeliminar);

            nombres[posicionaeliminar][0]='\0';
            break;
            }
        }

     }
    return 0;
}
