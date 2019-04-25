#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#define Nombre_LEN 20


typedef struct{
int id;
char direccion[Nombre_LEN];
int isEmpty;
char nombre [Nombre_LEN];
float precio;
int tipo;

}Pantalla;




int pantalla_inicializar(Pantalla *arrayPantalla,int len);
int pantalla_lugarLibre(Pantalla *arrayPantalla,int len,int *lugarLibre);
int pantalla_alta(Pantalla *arrayPantalla,int len);


#endif // PANTALLA_H_INCLUDED
