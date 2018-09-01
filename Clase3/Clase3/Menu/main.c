#include <stdio.h>
#include <stdlib.h>

void funcionX(int* unNumero);

int main()
{
    int x = 5;



    funcionX(&x);

     printf("Ahora de nuevo en main la variable x vale %d\n\n", x);





return 0;
}

void funcionX(int* x){





*x = 10;







}



