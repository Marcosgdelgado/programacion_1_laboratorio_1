typedef struct{

int idCliente;
char nombre[50];
char apellido[50];
char telefono[50];
int isEmpty;

}Cliente;

int abmCliente_init(Cliente *array, int size);
int abmCliente_alta(Cliente *array,int size);
int abmCliente_buscarPorId(Cliente *array,int size, int id);
int abmCliente_baja(Cliente *array,int size, int id);
int abmCliente_modificacion(Cliente* array, int size, int id);
int abmCliente_mostrar(Cliente *array, int id);
int get_Int(char* mensaje, int *input);
int get_Float(char* mensaje, float *input);
int get_Long(char* mensaje, long *input);
int get_Char(char* mensaje, char *input);
int get_String(char* mensaje, char *input);
int val_numero(char *str);
int val_flotante(char *str);
int val_letras(char *str);
int val_alfaNumerico(char *str);
int val_email(char *str);
int val_telefono(char *str);

int get_stringLetras(char *mensaje,char *input);
int get_stringNumeros(char *mensaje,char *input);
int get_stringFlotantes(char *mensaje,char *input);
int get_stringAlfaNumerico(char *mensaje,char *input);

int get_validInt(char *requestMessage,char *errorMessage, int* input,int lowLimit, int hiLimit,int attemps);
int get_validLetras(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
int get_validFloat(char *requestMessage,char *errorMessage, float* input,int lowLimit, int hiLimit,int attemps);
int get_validAlfaNumerico(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);
