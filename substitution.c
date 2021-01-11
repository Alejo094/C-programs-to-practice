#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

string ciphertext(string plaintext);

int length_key = 0;
string key = " ";
int length_alph = strlen("abcdefghijklmnopqrstuvwxyz");
string alphabet = "abcdefghijklmnopqrstuvwxyz";

// First we try  to validate the user only inputs one key value with 26 characters, no repetition etc


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    length_key = strlen(argv[1]);
    int all_letters = 0;
    int no_repetition = 0;
    int c2 = 0;
    int a = 0;

    for (int i = 0 ; i < length_key; i += 1)
    {
        int c1 = argv[1][i];

        if (isalpha(c1) && islower(c1))
        {
            all_letters = c1;
        }
        else if (isalpha(c1) && isupper(c1))
        {
            all_letters = (c1 + 32);
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        for (a = no_repetition; a < length_alph; a += 1)
        {
            c2 = alphabet[a];

            if ((c2 - all_letters) == 0)
            {
                no_repetition += 1;
                i = -1;
                break;
            }
            else
            {
                break;
            }
        }
    }

    if (length_key != 26)
    {
        printf("Key must contain 26 characters of single letters!.\n");
        return 1;
    }
    else if (length_key == no_repetition &&  no_repetition == 26)
    {
        key = argv[1];
        string plaintext = get_string("plaintext: ");
        ciphertext(plaintext);
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//After knowing the key is valid and working we cipher the plaintext

string ciphertext(string plaintext)
{
    int length_pl = strlen(plaintext);
    printf("ciphertext: ");

    int p = 0;
    int a = 0;
    int rest = p - a;
    int k = 0;
    int new_i = 0;
    int message = 0;
    int pos_plain = 0;



// This loop is for the letters of the Key
    for (int t = 0; t < length_key; t += 1)

    {
        k = key[t];

// This loop is for the letters of the plaintext

        for (pos_plain = message; pos_plain <= length_pl && rest == 0; pos_plain += 1)
        {
            p = plaintext[pos_plain];
            rest = 1;
            new_i = 0;
        }

        if (pos_plain > length_pl)
        {
            printf("\n");
            return 0;
        }

// This loop is for the letters of the alphabet so that way we know the real position of the letter for cipher

        for (int i = new_i; i < length_alph; i += 1)
        {
            a = alphabet[i];

            if (isupper(p))
            {
                rest = (p + 32) - a;
            }
            else if (isspace(p) || ispunct(p) || isdigit(p))
            {
                rest = 0;
            }
            else
            {
                rest = p - a;
            }

            if (rest == 0)
            {
                message += 1;
                t = -1;

// As the key size should not matter and we have to mantain the size depending on the plaintext the only way i found to keep it was this way

                if (isupper(p) && isupper(k))
                {
                    printf("%c", k);
                    break;
                }
                else if (isupper(p) && islower(k))
                {
                    printf("%c", k - 32);
                    break;
                }
                else if (islower(p) && isupper(k))
                {
                    printf("%c", k + 32);
                    break;
                }
                else if (isspace(p) || ispunct(p) || isdigit(p))
                {
                    printf("%c", p);
                    break;
                }
                else
                {
                    printf("%c", k);
                    break;
                }
            }
            else
            {
                new_i += 1;
                break;
            }
        }
    }
    return 0;
}
