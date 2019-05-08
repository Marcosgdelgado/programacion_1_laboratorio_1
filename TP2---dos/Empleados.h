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
int findEmployee (eEmployee*,int, int);
int removeEmployee( eEmployee*, int, int);
int firstEmployee(int);
int printEmployee(eEmployee*,int);
int sortEmployee(eEmployee*,int,char*, char*,int);
void modifyEmployee(eEmployee*,int,char*,char*, float,int,int,int);

#endif // EMPLEADOS_H_INCLUDED
