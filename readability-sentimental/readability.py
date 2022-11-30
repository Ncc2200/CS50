# TODO

from cs50 import get_string

# Ask user to enter a string of text
phrase = get_string("Please enter text: ")

# Calculate length of phrase
phrase_len = len(phrase)

# Initialize variables
word_count = 1
letter_count = 0
sentance_count = 0

# Calculate letters, words, and sentances
for i in range(phrase_len):
    if phrase[i].isalpha() == True:
        letter_count += 1
    if phrase[i] == ' ':
        word_count += 1
    elif phrase[i] == "." or phrase[i] == "!" or phrase[i] == "?":
        sentance_count += 1

# Calculate Coleman-Liau index
L = letter_count * (100 / word_count)
S = sentance_count * (100 / word_count)

index = round(0.0588 * L - 0.296 * S - 15.8)

# Output reading level of text
if index < 1:
    print("Before Grade 1")
elif 1 <= index and index <= 16:
    print(f'Grade {index}')
else:
    print("Grade 16+")