#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* this);
int controller_loadFromBinary(char* path , LinkedList* this);
int controller_addEmployee(LinkedList* this);
int controller_editEmployee(LinkedList* this);
int controller_removeEmployee(LinkedList* this);
int controller_ListEmployee(LinkedList* this);
int controller_sortEmployee(LinkedList* this);
int controller_saveAsText(char* path , LinkedList* this);
int controller_saveAsBinary(char* path , LinkedList* this);
int controller_saveAsTexTo(char* path, LinkedList* this);
int controller_ListEntregas(LinkedList* this);
int menu(void);


#endif // CONTROLLER_H_INCLUDED
