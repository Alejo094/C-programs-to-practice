#include <cs50.h>
#include <stdio.h>

int main(void)
{

int altura;
int espacios;

do

{
altura = get_int("Altura:");
}
    while(altura <=0  || altura > 8);

for(int fila = 0; altura > fila; fila+=1)
{
    for (espacios = altura - fila; 1 < espacios; espacios -= 1)
    {
    printf(" ");
    }
        for( int tricky = 0;tricky <= fila;tricky += 1)
        {
        printf("#");
        }
printf("\n");
}


}