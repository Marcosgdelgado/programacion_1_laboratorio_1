// sentencias de precompilador
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

    typedef struct
    {
    // variables a usar SIEMPRE
       int isEmpty;
       int idEmpleado;
    //***********************
       char nombre[20];
       char apellido[50];
    }Empleado;


    int Empleados_initArray(Empleado* pEmpleado,int limite);
    int Empleados_printDebugArray(Empleado* pEmpleado,int limite);
    int Empleados_lugarLibre(Empleado* pEmpleado,int limite);
    int Empleados_alta(Empleado* pEmpleado,int limite);
    int Empleados_baja(Empleado* pEmpleado,int limite);
    int Empleados_modificar(Empleado* pEmpleado,int limite);
    int Empleados_ordenarNombre(Empleado* pEmpleado,int limite);

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

int buscarlibre     (char lista[][20],
                     int len,
                     int* pIndex);
int buscanombre     (char* pNombre,
                     char lista[][20],
                     int len,
                     int* pIndex);

#endif // UTN_H_INCLUDED
