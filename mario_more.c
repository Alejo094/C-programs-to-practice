#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int altura;

    do

    altura = get_int("Altura:");

    while( altura <=0 || altura > 8 );

for(int fila=0; fila<altura ;fila+=1)
    {
        for(int espacios = altura-fila;espacios>1 ;espacios-=1 )
        {
            printf(" ");
        }
        for(int tricky=0; tricky<=fila;tricky+=1)
        {
            printf("#");
        }
            printf("  ");

        for(int tricky1=0; tricky1<=fila;tricky1+=1)
        {
            printf("#");
        }
    printf("\n");
    }
}