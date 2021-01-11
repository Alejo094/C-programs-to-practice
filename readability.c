#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


float count_letters(string a);

float count_words(string a);

float count_sentences(string a);

float length = 0;


int main(void)
{

//I divided this program in 3 separate functions each one is in charge of counting letters, words and sentences respectively.

    string a = get_string("Please type the text to evaluate the reading level?\n");

    length = strlen(a);

    float  total_letters = (strlen(a) - count_letters(a));

    float index = round(0.0588 * ((total_letters * 100) / count_words(a)) - (0.296 * ((count_sentences(a) * 100) / count_words(
                            a))) - 15.8);

//Here we evaluate the result of the index formula and state the level of readability of text.

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (1 >= index || index < 16)
    {
        printf("Grade %0.0f\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

//This first function is to count the spaces and punctuation of the text, I use a for loop
//for that. The remainder should be the letters, thats why I substract this fucntion from the
//strlength upwards.

float count_letters(string a)
{
    float L = 0;
    for (int i = 0; i < length; i += 1)
    {
        int c = a[i];
        if (isspace(c))
        {
            L += 1;
        }
        else if (ispunct(c))
        {
            L += 1;
        }
    }
    return L;
}

// This second function is to count the words in the text. I use a for loop to go trough the text
//and count the spaces using the logic that after each space there should be a word. I also
//covered the double spaces at the beginning and end of the text so that the grade should not be
//affected or also in the middle of words.

float count_words(string a)
{
    float count = 0;
    for (int i = 0; i < length ; i += 1)
    {
        int c = a[i];

        int x = isspace(a[i]) && isspace(a[i + 1]);

        if (x)
        {
            continue;
        }
        else if ((isspace(c) || isalpha(c)) && (i != length - 1) && count == 0)
        {
            count += 1;
        }
        else if (isspace(c) && (i != length - 1) && (count >= 1))
        {
            count += 1;
        }
        else if (isspace(c) && (i == length - 1))
        {
            continue;
        }
        else
        {
            continue;
        }
    }
    return count;
}


//This last function is to count the sentences taking into consideration dots, exclamation
//points and interrogation signs as new setences I am also using a for loop that.

float count_sentences(string a)
{
    float S = 0;
    for (int i = 0; i < length; i += 1)
    {
        int c = a[i];
        if ((c == '.') || (c == '!') || (c == '?'))
        {
            S += 1;
        }
        else
        {
            S += 0;
        }

    }
    return S;

}






