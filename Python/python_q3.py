# Prompt the user for a string and print the output without any punctuation marks from the given string.
# NAME : Hariharan P
# ROLL NO : CB.EN.P2EBS24021
# DATE : 28.08.2024

import string  # Import the string module for easy access to punctuation marks.

try:
    BLACK_BOLD = "\033[1m"
    RESET = "\033[0m"
    # Prompt the user to enter a string.
    print('INPUT'.center(100,'-'))
    user_input = input("\nEnter a string: ")

    # Use a list comprehension to remove any characters that are punctuation marks.
    # This iterates over each character in the input string and only includes those not in string.punctuation.
    output = ''.join([char for char in user_input if char not in string.punctuation])
    print('\n')
    print('OUTPUT'.center(100,'-'))
    # Print the resulting string without punctuation.
    print("String without punctuation: {} {} {}".format(BLACK_BOLD,output,RESET))
    print('\n')
    print('END'.center(100,'-'))
    print('\n')
except Exception as e:
    # Catch any unexpected exceptions and print an error message.
    print(f"An error occurred: {e}")


"""
BEGIN

    # Define constants for text formatting (optional)
    BLACK_BOLD = Formatting code for bold text
    RESET = Formatting code to reset text formatting

    TRY
        PRINT "INPUT" centered with dashes
        
        # Prompt user to enter a string
        user_input = GET input from user

        # Remove punctuation from the input string
        output = Construct a new string by including only characters not in the list of punctuation marks
        
        PRINT "OUTPUT" centered with dashes
        
        # Print the resulting string without punctuation
        PRINT "String without punctuation: ", BLACK_BOLD, output, RESET
        
        PRINT "END" centered with dashes

    EXCEPT Exception as e
        # Handle any unexpected errors
        PRINT "An error occurred: ", e

END
"""