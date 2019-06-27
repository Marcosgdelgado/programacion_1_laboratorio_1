#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float peso;
    int cuit;

}Entregas;

/*Employee* entregas_new();

int entregas_delete(Employee*  this);

void entregas_setId(Employee* this,int id);
int entregas_getId(Employee* this);

void entregas_setTipo(Employee* this,char* nombre);
char* entregas_getNombre(Employee* this);

void entregas_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int entregas_getHorasTrabajadas(Employee* this);

void entregas_setSueldo(Employee* this,float sueldo);
float entregas_getSueldo(Employee* this);

Employee* entregas_newParametros(char *var1, char *var2, char *var3, char *var4);*/

Entregas* entregas_new();

void entregas_idInit(int id);
int entregas_idGenerator();
int entregas_setIdStr(Entregas* this,char* idStr);
int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);
int entregas_delete(Entregas* this);
int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);
int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);
int entregas_setPesoStr(Entregas* this,char* precioStr);
int entregas_setPeso(Entregas* this,float peso);
int entregas_getPeso(Entregas* this,float* peso);
int entregas_setCUITstr(Entregas* this,char* CUITstr);
int entregas_setCUIT(Entregas* this,int cuit);
int entregas_getCUIT(Entregas* this,int* cuit);

Entregas* entregas_newParametros(char* idStr,char* fechaStr,char* tipoFotoStr,char* precioStr, char* CUITstr, char* pepito);

#endif // EMPLOYEE_H_INCLUDED
