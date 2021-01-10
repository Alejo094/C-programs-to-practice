#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{


    float money;
    int count = 0;

    do

    money = get_float("Money:");

    while(money <= 0);
    int money100 = round(money * 100);

        for(float total25 = money100; total25 >= 25;total25 -= 25)
        {
            count += 1;
            money100 -= 25;
        }

        for (float total10 = money100; total10 >= 10 && total10 <25;total10 -= 10)
        {
            count += 1;
            money100 -= 10;
        }

        for (float total5 = money100; total5 >= 5 && total5 < 10; total5 -= 5)
        {
            count += 1;
            money100 -= 5;
        }

        for (float total1 = money100; total1 >= 1 && total1 < 5;total1 -= 1)
        {
            count += 1;
            money100 -= 1;
        }
        printf("%i\n",count);

}
