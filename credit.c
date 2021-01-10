#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{

    long card_num;
    int count=0;
    int identi;
    int suma=0;

    do
    {
    card_num = get_long("Please enter you credit card number?\n");
    }
    while (card_num<0);

    long long digits=card_num;
    while (digits>0)
    {
    digits=digits/10;
    count+=1;
    }
    if ((count!=13 )&&(count!=15)&&(count!=16))
    {
        printf("INVALID\n");
    }

    int number[count];

    for(int i=0; i<count;i++)
    {
        number[i] = card_num %10;
        card_num = card_num /10;
    }

    int longitud_numero[count];
    for (int i =0; i<count;i+=1)
    {
        longitud_numero[i] = number[i];
    }

    for(int i =1;i<count; i+=2)
    {
        number[i]=number[i]*2;
    }

    if (count==13)
    {
        for(int i = 0;i<count;i += 1)
        {
        identi=(number[i]%10)+(number[i]/10%10);
        suma=suma+identi;
        }

        if (longitud_numero[12] == 4 && suma%10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if (count==15)
    {
        for (int i = 0; i<count; i += 1)
        {
            identi=(number[i]%10)+(number[i]/10 %10);
            suma = suma+identi;
        }
        if (longitud_numero[14] == 3 && suma%10 == 0 && (longitud_numero[13] == 4 || longitud_numero[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

     if (count==16)
    {
        for(int i=0; i<count; i+=1)
        {
            identi = (number[i]%10)+(number[i]/10 %10);
            suma=suma+identi;
        }
        if (longitud_numero[15] == 5 && suma%10 == 0 && (longitud_numero[14] <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if (longitud_numero[15] == 4 && suma%10 == 0)
        {
            printf("VISA\n");
        }
        else
         {
            printf("INVALID\n");
         }
   }

}
