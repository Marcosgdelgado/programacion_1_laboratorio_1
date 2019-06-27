#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* this);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* this);


#endif // PARSER_H_INCLUDED
