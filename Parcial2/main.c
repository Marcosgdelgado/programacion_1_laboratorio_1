#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "input.h"
#include "LinkedList.h"

int main()
{
    int opcion= 0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
     opcion=menu();
      do{
        switch(opcion)
        {
            case 1:
                system("cls");
                if (flag == 1){
                    printf ("\n\nSolo se puede cargar una vez\n\n");
                }else{
                    controller_loadFromText("data.csv",listaEmpleados);
                }
                flag = 1;
                break;
            case 2:
                system("cls");
                if (flag == 1){
                    printf ("\n\nSolo se puede cargar una vez\n\n");
                }else{
                    //controller_loadFromBinary("bin.dat",listaEmpleados);
                }
                flag = 1;
                break;
            case 3:
                if (flag == 1){
                system("cls");
                //controller_addEmployee(listaEmpleados);
                }
                break;
            case 4:
                if (flag == 1){
                system("cls");
                //controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if (flag == 1){
                system("cls");
//                controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if (flag == 1){
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                }
                break;
            case 7:
                system("cls");
               // controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv", listaEmpleados);
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("bin.dat",listaEmpleados);
                break;
            case 10:
                system("cls");
                //controller_saveAsTexTo("data.txt",listaEmpleados);
                controller_saveAstxt("data.txt", listaEmpleados);
                break;
        }
    opcion = menu();
    }while(opcion != 11);
    return 0;
}
