#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{

    // Validate command line argument

    if (argc != 2)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check key length

    int argv_length = strlen(argv[1]);
    if (argv_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check that key is alphabetic

    for (int i = 0; i < argv_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Entire key must be alphabetic\n");
            return 1;
        }

        // Check for repeated characters (case incencitive)

        for (int j = i + 1; j < argv_length; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not have repeated characters\n");
                return 1;
            }
        }
    }

    // Get plaintext

    string text = get_string("plaintext:  ");

    //Encipher and print

    printf("ciphertext: ");
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(argv[1][text[i] - 65]));
        }
        else if (islower(text[i]))
        {
            printf("%c", tolower(argv[1][text[i] - 97]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}