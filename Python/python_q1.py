# Prompt two numbers from user along with the option of arithmetic operation. Use appropriate data type to print the results. Run the program continuously until the user chooses an option for exit. 
# NAME : Hariharan P
# ROLL NO : CB.EN.P2EBS24021
# DATE : 28.08.2024
BLACK_BOLD = "\033[1m"
RED = "\033[31m"
RESET = "\033[0m"
# Initialize a loop condition to keep the program running until the user decides to quit.
while True:
    # Start an infinite loop that continues until the user enters 'q' to quit.
    try:
        print('INPUT'.center(100,'-'))
        # Try block to handle potential errors, such as invalid input types.
        operator = input("\nEnter the operator (+, -, *, /) or 'q' to quit: ").strip()
        # Prompt the user to enter the operator. Strip any surrounding whitespace.
        result = None 
        # Initialize the result variable to None, which will be updated with the result of the operation.
        if operator in ['q','Q','QUIT','Quit','quit']:
            # If the user enters 'q' (in any case), set condition to False to exit the loop.
            print("\nExiting the program.".center(60,'-'))
            # Inform the user that the program is exiting.
            break  # Break out of the loop to end the program.
        if operator not in ['*','/','+','-']:
            # If the user enters 'q' (in any case), set condition to False to exit the loop.
            print(f"\n{RED}Enter the proper Operator.{RESET}".center(60,'-'))
            # Inform the user that the program is exiting.
            continue 
        try:
            num1 = eval(input("\nEnter the first number: "))
            # Prompt the user to enter the first number and convert it to a float.
            num2 = eval(input("Enter the second number: "))
            # Prompt the user to enter the second number and convert it to a float.
        except:
            print(f"\n{RED}Enter Valid Input Values{RESET}")
            # Prompt the user to enter valid input.
            continue


        match operator:
            # Use the match statement to handle different operators.
            case '+':
                result = num1 + num2  # Return the sum of num1 and num2 if the operator is '+'.
            case '-':
                result = num1 - num2  # Return the difference between num1 and num2 if the operator is '-'.
            case '*':
                result = num1 * num2  # Return the product of num1 and num2 if the operator is '*'.
            case '/':
                try:
                    result = num1 / num2
                except ZeroDivisionError as z:
                    print(f"Error {z}")  # Return the quotient of num1 divided by num2 if the operator is '/'.
            case _:
                # Handle any other operator as invalid.
                print(f"{RED}Invalid operator!{RESET}\n")
                pass
        if result is not None:
            print('\n')
            print('OUTPUT'.center(100,'-'))
            print(f"The result of{BLACK_BOLD} {num1} {operator} {num2} = {result}{RESET}")
            print('\n')
            print('END'.center(100,'-'))
            print('\n')
            # If the function returns a valid result (not None), print the result.
            
    except ValueError:
        # Catch a ValueError if the user enters non-numeric input.
        print(f"{RED}Invalid input! Please enter numeric values.{RESET}")


"""
BEGIN

    # Define constants for text formatting (optional)
    BLACK_BOLD = Formatting code for bold text
    RED = Formatting code for red text
    RESET = Formatting code to reset text formatting

    WHILE True  # Start of the loop
        PRINT "INPUT" centered with dashes
        
        # Get user input for operator
        operator = GET input from user
        TRIM whitespace from operator
        
        IF operator is one of quit options (e.g., 'q', 'quit') THEN
            PRINT "Exiting the program" centered with dashes
            BREAK  # Exit the loop
        END IF
        
        IF operator is not a valid operator (e.g., '+', '-', '*', '/') THEN
            PRINT error message for invalid operator
            CONTINUE  # Skip to the next iteration
        END IF
        
        TRY
            # Get and validate numbers
            num1 = GET input from user for the first number
            CONVERT num1 to a numeric value
            num2 = GET input from user for the second number
            CONVERT num2 to a numeric value
        EXCEPT error
            PRINT error message for invalid input
            CONTINUE  # Skip to the next iteration
        END TRY
        
        # Perform calculation based on operator
        SWITCH operator
            CASE '+':
                result = num1 plus num2
            CASE '-':
                result = num1 minus num2
            CASE '*':
                result = num1 times num2
            CASE '/':
                result = num1 divided by num2
            DEFAULT:
                PRINT error message for invalid operator
        END SWITCH
        
        IF result is not None THEN
            PRINT "OUTPUT" centered with dashes
            PRINT formatted result
            PRINT "END" centered with dashes
        END IF
        
    END WHILE  # End of the loop

END


"""