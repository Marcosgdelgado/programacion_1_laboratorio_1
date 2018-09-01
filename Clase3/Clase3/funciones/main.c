#include <stdio.h>

#include <stdlib.h>

//prototipo
int sumar1(int op1, int op2);

int main()
{

    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

      printf("Ingrese otro numero: ");
      scanf("%d", &num2);

     resultado =  sumar1(num1, num2);


     printf("El resultado de la suma es %d\n\n", resultado);





    return 0;
}


/** \brief suma dos enteros
 *
 * \param op1 es el primer operando a sumar
 * \param op2 es el segundo operando a sumar
 * \return retorna la suma de los parametros
 *
 */

int sumar1(int op1, int op2){

int rta;

rta = op1 + op2;

return rta;

}

