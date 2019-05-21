#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "orquesta.h"
#include "utn.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_TIPO 3

int main()
{
    int opcion;
    char submenu;
    int contadorIdOrquesta=0;

    int contadorIdMusico=0;

    int contadorIdInstrumento=0;

    Orquesta arrayOrquesta[QTY_TIPO];
    orquesta_Inicializar(arrayOrquesta,QTY_TIPO);

    Musico arrayMusico[QTY_TIPO];
    musico_Inicializar(arrayMusico,QTY_TIPO);

    Instrumento arrayInstrumento[QTY_TIPO];
    instrumento_Inicializar(arrayInstrumento,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n*****MENU*****\n\n1) Altas:\n-Orquesta\n-Musico\n-Instrumento\n\n2)Modificar\n-Orquesta\n-Musico\n-Instrumento\n \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(toupper(opcion))
        {
            case 1: //Alta
                utn_getChar("\nA) Alta orquesta\nB) Alta musico\nC) Alta instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_alta(arrayOrquesta,QTY_TIPO,&contadorIdOrquesta);
                        system("pause");
                        system("cls");
                         break;
                case 'B':
                        musico_alta(arrayMusico,QTY_TIPO,&contadorIdMusico,arrayOrquesta,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'C':
                        instrumento_alta(arrayInstrumento,QTY_TIPO,&contadorIdInstrumento);
                        system("pause");
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 2: //Modificar
                utn_getChar("\nA) Modificar orquesta\nB) Modificar musico\nC) Modificar instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_modificar(arrayOrquesta,QTY_TIPO);
                        system("cls");
                         break;
                case 'B':
                        musico_modificar(arrayMusico,QTY_TIPO);
                        system("cls");
                         break;
                case 'C':
                        instrumento_modificar(arrayInstrumento,QTY_TIPO);
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 3: //Baja
                utn_getChar("\nA) Baja orquesta\nB) Baja musico\nC) Baja instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_baja(arrayOrquesta,QTY_TIPO,QTY_TIPO);
                        system("cls");
                         break;
                case 'B':
                        musico_baja(arrayMusico,QTY_TIPO,QTY_TIPO);
                        system("cls");
                         break;
                case 'C':
                        instrumento_baja(arrayInstrumento,QTY_TIPO,QTY_TIPO);
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 4://Listar
                utn_getChar("\nA) Listar orquesta\nB) Listar musico\nC) Listar instrumento\nS)Menu anterior\n","*Incorrecto*",'A','Z',3,&submenu);
                switch(toupper(submenu))
                {
                case 'A':
                        orquesta_listar(arrayOrquesta,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'B':
                        musico_listar(arrayMusico,QTY_TIPO,arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'C':
                        instrumento_listar(arrayInstrumento,QTY_TIPO);
                        system("pause");
                        system("cls");
                         break;
                case 'S'://Salir
                        break;
                default:
                    printf("\nLetra incorrecta\n");
                }
                break;

            case 5:
                //orquestas_tipos(arrayOrquesta,QTY_TIPO);
                //Ordenar
 //               orquesta_ordenarPorString(arrayOrquesta,QTY_TIPO);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
