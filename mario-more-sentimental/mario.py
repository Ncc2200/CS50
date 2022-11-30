# TODO

# Import libraries
from cs50 import get_int

# Ask user for desired height
while True:
    h = get_int("Height: ")
    if (h > 0 and h <= 8):
        break

# Iterate through rows and columns
for i in range(1, 1 + h):
    for j in range(1, 1 + h):

        # Print left side
        if j > (h - i):
            print("#", end="")
        else:
            print(" ", end="")

        # Print right side
        if j == h:
            print(" ", "#" * i, end="")

    print()

