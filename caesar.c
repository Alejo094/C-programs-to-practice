#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

string ciphertext(string a);
int key = 0;


int main(int argc, string argv[])
{

// First we validate if the input enter by the user for the key is all numbers or not

    int s = 0;

    if (argc != 2)
    {
        printf("Usage:./caesar key\n");
        return 1;
    }

    int length_key = strlen(argv[1]);
    for (int i = 0; i < length_key ; i += 1)
    {
        int c = argv[1][i];
        if (isdigit(c))
        {
            s += 1;
        }
    }
    if (length_key == s)
    {
        key = atoi(argv[1]);

        string a = get_string("Plaintext:  ");
        ciphertext(a);
    }
    else
    {
        printf("Usage:./caesar key\n");
        return 1;
    }


}

// After validating the key is workin fine we the create a function that takes the plaintext and converts it to cipher

string ciphertext(string a)
{

    int length_a = strlen(a);
    printf("ciphertext: ");
    for (int i = 0; i < length_a; i += 1)
    {

// Depending if the letter entered in the string of plaintext is lowercase or uppercase we have to do a special conversion taking the Decimal ASCII chart as reference

        int c = a[i];
        int total = c + key;
        if (ispunct(c) || isspace(c))
        {
            printf("%c", c);
        }
        else if (isupper(c) && total <= 90)
        {
            printf("%c", total);
        }
        else if (isupper(c) && total > 90)
        {
            int x = (total - 90) % 26;
            printf("%c", 64 + x);
        }
        else if (islower(c) && total <= 122)
        {
            printf("%c", total);
        }
        else if (islower(c) && total > 122)
        {
            int x = (total - 122) % 26;
            printf("%c", 96 + x);
        }
        else
        {
            printf("%c",  key);
        }

    }
    printf("\n");
    return 0;
}
