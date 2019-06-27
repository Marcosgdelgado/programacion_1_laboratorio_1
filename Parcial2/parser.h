#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "../linkedlist_cascara_v6/inc/LinkedList.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* this);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* this);


#endif // PARSER_H_INCLUDED
