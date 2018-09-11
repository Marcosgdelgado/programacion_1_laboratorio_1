#include <stdio.h>
#include <stdlib.h>

void mostrarArrays(char vec[],int tam);
void mostrarOrden(char vec[],int tam);

int main()
{
    char letra[]={'a','b','c','d','f','g','h','i'};

    mostrarArrays(letra, 8);
    mostrarOrden(letra, 8);
    mostrarArrays(letra, 8);

    return 0;
}

void mostrarArrays(char vec[],int tam){

for(int i=0 ;i < tam; i++)
{
    printf("%c  ", vec[i]);
}
}
void mostrarOrden (char vec[],int tam)
{
    char aux;
    for(int i=0 ;i< tam -1; i++)
    {

        for(int j = i+ 1; j < tam; j++)
        {
            if(vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec [j]= aux;
            }
        }

    }

}




