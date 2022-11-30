#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    printf("\n");

    // Ask for size
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    // Each Row
    for (int i = 0; i < n; i++)
    {
        // Printing Columns
        for (int j = 0; j < n * 2 + 1; j++)
        {
            if (j < n - i - 1)
            {
                printf(" ");
            }
            else if (j == n)
            {
            printf("  ");
            }
            else if (j < n + i + 2)
            printf("#");
        }
        // Next Row
        printf("\n");
    }
}