# TODO
# Import libraries
from cs50 import get_string

# Ask user for credit card number
while True:
    card = get_string("Credit Card Number: ")
    if int(card) > 1:
        break

# Check length of credit card number and exit early if invalid
card_len = len(card)
if card_len < 13 or 16 < card_len:
    print("INVALID")
    exit()

# Validate credit card number
# Iterate through card number using Luhn's Algorithm
even = 0
odd = 0

for i in range(card_len):
    position = (card_len - i) - 1
    if (i + 1) % 2 == 0:
        even_temp = (int(card[position]) * 2)
        if even_temp > 9:
            even += even_temp // 10
            even += even_temp % 10
        else:
            even = even + (int(card[position]) * 2)
    elif (i + 1) % 2 != 0:
        odd = odd + int(card[position])

checksum = (even + odd) % 10

# Output final results
if checksum == 0:
    first_digit = int(card[0])
    second_digit = int(card[1])

    if first_digit == 4 and (card_len == 13 or card_len == 16):
        print("VISA")

    elif first_digit == 5 and (1 <= second_digit <= 5):
        print("MASTERCARD")

    elif first_digit == 3 and (second_digit == 4 or second_digit == 7):
        print("AMEX")
    else:
        print("INVALID")
else:
    print("INVALID")