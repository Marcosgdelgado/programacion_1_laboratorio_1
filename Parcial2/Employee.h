#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* elemento_new();

int elemento_delete(Employee*  this);

void elemento_setId(Employee* this,int id);
int elemento_getId(Employee* this);

void elemento_setTipo(Employee* this,char* nombre);
char* elemento_getNombre(Employee* this);

void elemento_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int elemento_getHorasTrabajadas(Employee* this);

void elemento_setSueldo(Employee* this,float sueldo);
float elemento_getSueldo(Employee* this);

Employee* elemento_newParametros(char *var1, char *var2, char *var3, char *var4);



#endif // EMPLOYEE_H_INCLUDED
