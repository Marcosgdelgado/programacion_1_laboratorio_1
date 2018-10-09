typedef struct
{
    int id;
    char nombre[20];
    float importe;
    int idJuegos;
    int isEmpty;
} eJuegos;

typedef struct
{
    int id;
    char descripcion[51];
} eCategoria;

typedef struct
{
    int codigo;
    char nombre[51];
    char sexo;
    float telefono;
    int isEmpty;
} eCliente;


typedef struct
{
    int dia;
    int mes;
    int anio;

} efecha;
typedef struct
{
    int id;
    int idComida;
    int idEmp;
    efecha fecha;
    int isEmpty;

} eAlmuerzo;


typedef struct
{
    int id;
    char descripcion[20];

} eComida;

void listarSectores(eCategoria sectores[], int tam);
void obtenerSector(eCategoria sectores[], int tam, int idJuegos, char cadena[]);
void inicializarJuego(eJuegos lista[], int tam);
void mostrarJuego(eJuegos unEmpleado, eCategoria sectores[], int tam);
int buscarLibre(eJuegos lista[], int tam);
int buscarJuego(eJuegos lista[], int tam, int ID);
void altaJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector);
void bajaJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector);
void ModificarJuego(eJuegos lista[], int tam, eCategoria sectores[], int tamSector);
//void ordenarJuegosXID(eJuegos lista[], int tam);
//void harcodearJuegos(eJuegos empleados[]);
void mostrarJuegos(eJuegos lista[], int tam, eCategoria sectores[], int tamSector);
//void listarJuegosXID(eJuegos x[],int tam, eCategoria sectores[], int tamSector);
//void ordenarXJuegoYNombre(eJuegos x[],int tam, eCategoria sectores[], int tamSector);
//void mostrarJuegosMasGanadores(eJuegos x[],int tam, eCategoria sectores[], int tamSector);
int menu();
void inicializarCliente(eCliente lista[], int tam);
void mostrarCliente(eCliente unEmpleado, int tam);
int buscarLibreCliente(eCliente lista[], int tam);
int buscarCliente(eCliente lista[], int tam, int codigo);
void altaCliente(eCliente lista[], int tam);
void bajaCliente(eCliente lista[], int tam);
void modificarCliente(eCliente lista[], int tam);
void mostrarClientes(eCliente lista[]);
