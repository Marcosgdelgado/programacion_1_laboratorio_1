#include <stdio.h>
#include <stdlib.h>
int mostrarmayor(void);
int main()
{
    int a;
    int max;
    int min;
    int contador;
    int flag = 0;

    do
    {
    printf("ingrese un numero: ");
    scanf("%d", &a);
    if (contador==0){
    max = a;
    min=a;

    }else
    {
        if(a>max){
        max=a;
        }
        if(min>a || flag ==0){
            min=a;
            flag = 1;
        }
    }

      //a
      //return mayor=
    //mayor = mostrarmayor(a);
    }while(a != -1);
    printf("su numero max es: %d ",max);
    printf("su numero max es: %d ",min);
    return 0;
}

/*int mostrarmayor(int a){
 int max=0;

}*/


