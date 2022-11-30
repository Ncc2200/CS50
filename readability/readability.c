#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_letters(string text);
int compute_sentances(string text);
int compute_words(string text);


int main(void)
{
    // Get input from user
    string phrase = get_string("Text :");

    // Calculate letters, sentances, and words
    int letters = compute_letters(phrase);
    int sentances = compute_sentances(phrase);
    int words = compute_words(phrase);
    //printf("Letters: %i\n", letters);
    //printf("Sentances: %i\n", sentances);
    //printf("Words: %i\n", words);

    // Calculate reading index
    float index = 0.0588 * (letters * (100 / (float) words)) - 0.296 * (sentances * (100 / (float) words)) - 15.8;
    //printf("Index: %f\n", index);

    // Print Resulting Grade Level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

int compute_letters(string text)
{
    // Compute number of letters
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}

int compute_sentances(string text)
{
    // Compute number of sentances
    int sentances = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentances ++;
        }
    }
    return sentances;
}

int compute_words(string text)
{
    // Compute number of sentances
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words ++;
        }
    }
    words ++;
    return words;
}