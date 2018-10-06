typedef struct
{
    int id;
    char descripcion[20];

}eComida;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idComida;
    int idEmpl;
    eFecha fecha;
}eAlmuerzo;

typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float salary;
    int idSector;
    int isEmpty;
} Employee;

typedef struct
{
    int sectorid;
    char descripcion[20];
}eSector;

void inicializarEmpleados(Employee lista[], int tam);
void mostrarEmpleado(Employee unEmpleado, eSector sectores[], int tam);
int buscarLibre(Employee lista[], int tam);
int buscarEmpleado(Employee lista[], int tam, int id);
void altaEmpleado(Employee lista[], int tam, eSector sectores[], int tamSector);
void bajaEmpleado(Employee lista[], int tam);
void ModificarEmpleado(Employee lista[], int tam);
void ordenarEmpleadosXid(Employee lista[], int tam);
void harcodearEmpleados(Employee empleados[]);
void mostrarEmpleados(Employee lista[], int tam, eSector sectores[], int tamSector);
void listarSectores(eSector sectores[], int tam);
void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[]);
