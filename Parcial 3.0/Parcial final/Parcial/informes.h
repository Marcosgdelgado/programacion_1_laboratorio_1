#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int Informes_listarPorCriterio(Musico arrayMusico[], Orquesta arrayOrquesta[], int sizeMusico, int sizeOrquesta, char* criterio);

int informar_OrquestaXmusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],
                              int sizeOrquesta, Instrumento arrayInstrumento[], int sizeIns);

int informar_masMusicos(Musico arrayMusico[],int sizeMusico, Orquesta arrayOrquesta[],int sizeOrquesta,
                        Instrumento arrayInstrumento[], int sizeIns);
int ListarxLugar(Orquesta arrayOrquesta[], int size);
int listarXorquesta(Musico arrayMusico[], int sizeMusico, Orquesta arrayOrquesta[], int sizeOrquesta,Instrumento arrayInstrumento[],int sizeInstrumento);
int imprimirCuerdas(Instrumento arrayInstrumento[],int sizeInstrumento,Musico arrayMusico[], int sizeMusico);
#endif // INFORMES_H_INCLUDED
