#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Declare variables
    long c;
    int n_sum_odd = 0;
    int n_sum_even = 0;
    int check_sum = 0;
    int leng;
    int first;
    int first_two;
    int last;

    //Ask for Credit Card Number
    do
    {
        c = get_long("Credit Card Number: ");
    }
    while (c < 1);

    // Calclate length of credit card number
    leng = log10(c) + 1;

    // Calculate first two digits of credit card number
    first = c / pow(10, leng - 1);
    first_two = c / pow(10, leng - 2);

    // Set c_temp to credit card number
    long c_temp = c;

    // Loop to find integers from right to left
    for (int i = 0; i < leng; i++)
    {
        int n = c_temp % 10;

        // Save last digit on first iteration
        if (i == 0)
        {
            last = n;
        }

        // Checksum logic
        // Odd positions from right to left
        if (i % 2 != 0)
        {
            int n_sum_temp = n * 2;
            if (n_sum_temp >= 10)
            {
                n_sum_temp = (n_sum_temp % 10) + ((n_sum_temp / 10) % 10);
            }
            n_sum_odd = n_sum_temp + n_sum_odd;
        }
        // Even positions from right to left
        else if (i % 2 == 0)
        {
            n_sum_even = n + n_sum_even;
        }
        // Final Checksum
        check_sum = n_sum_odd + n_sum_even;
        check_sum = check_sum % 10;
        c_temp = c_temp / 10;
    }

    // Determine and print type of credit card
    if (check_sum != 0)
    {
        printf("INVALID\n");
    }
    else if (first == 4 && (leng == 13 || leng == 16))
    {
        printf("VISA\n");
    }
    else if (first_two >= 51 && first_two <= 55 && leng == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_two == 34 || first_two == 37) && leng == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
