#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

 typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

 }eEmployee;

int initEmployee(eEmployee*,int);
int freeSpace (eEmployee*, int, int*);
int addEmployee(eEmployee*, int, int, char*, char*, float, int);



#endif // EMPLEADOS_H_INCLUDED
