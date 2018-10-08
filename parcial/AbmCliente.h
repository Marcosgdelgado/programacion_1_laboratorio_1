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
    char descripcion[20];
} eJuego;


void listarSectores(eJuego sectores[], int tam);
void obtenerSector(eJuego sectores[], int tam, int idJuegos, char cadena[]);
void inicializarJuego(eJuegos lista[], int tam);
void mostrarJuego(eJuegos unEmpleado, eJuego sectores[], int tam);
int buscarLibre(eJuegos lista[], int tam);
int buscarJuego(eJuegos lista[], int tam, int ID);
void altaJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector);
void bajaJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector);
void ModificarJuego(eJuegos lista[], int tam, eJuego sectores[], int tamSector);
void ordenarJuegosXID(eJuegos lista[], int tam);
void harcodearJuegos(eJuegos empleados[]);
void mostrarJuegos(eJuegos lista[], int tam, eJuego sectores[], int tamSector);
void listarJuegosXID(eJuegos x[],int tam, eJuego sectores[], int tamSector);
void ordenarXJuegoYNombre(eJuegos x[],int tam, eJuego sectores[], int tamSector);
void mostrarJuegosMasGanadores(eJuegos x[],int tam, eJuego sectores[], int tamSector);
