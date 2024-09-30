# Prompt the user for the names and ages of 5 members, then sort the members based on their age.
# NAME : Hariharan P
# ROLL NO : CB.EN.P2EBS24021
# DATE : 28.08.2024
try:
    BLACK_BOLD = "\033[1m"
    RESET = "\033[0m"
    # Prompt the user for the number of members.
    print('INPUT'.center(100,'-'))
    num_members = int(input("Enter the number of members: "))

    # Initialize an empty list to store the members' information (name and age).
    members = []

    # Prompt the user for the names and ages of the specified number of members.
    for i in range(num_members):
        name = input(f"Enter the name of member {i+1}: ")  # Prompt for the name.
        age = int(input(f"Enter the age of {name}: "))  # Prompt for the age and convert to integer.

        # Append the tuple (name, age) to the members list.
        members.append((name, age))

    # Sort the list of members by age.
    members.sort(key=lambda member: member[1])
    print('OUTPUT'.center(100,'-'))
    # Print the sorted list of members.
    print("\nMembers sorted by age:")
    for name, age in members:
        print(f"{BLACK_BOLD}{name}: {age}{RESET} years old")
    print('END'.center(100,'-'))

except ValueError:
    # Catch a ValueError if the input is not a valid integer.
    print("Invalid input! Please enter a valid number for the age or number of members.")

except Exception as e:
    # Catch any other unexpected exceptions and print an error message.
    print(f"An error occurred: {e}")


"""
BEGIN

    # Define constants for text formatting (optional)
    BLACK_BOLD = Formatting code for bold text
    RESET = Formatting code to reset text formatting

    TRY
        PRINT "INPUT" centered with dashes
        
        # Prompt user for the number of members
        num_members = GET integer input from user

        # Initialize a list to store members' information
        Initialize an empty list called members

        # Loop to collect names and ages of members
        FOR i FROM 1 TO num_members DO
            # Prompt for the name of each member
            name = GET input from user
            
            # Prompt for the age of each member
            age = GET integer input from user
            
            # Add the (name, age) tuple to the members list
            Append (name, age) to members
        END FOR

        # Sort the list of members by age
        SORT members by the second element of each tuple (age)

        PRINT "OUTPUT" centered with dashes
        
        # Print the sorted list of members
        PRINT "Members sorted by age:"
        FOR each (name, age) in members DO
            PRINT name with BLACK_BOLD formatting, followed by age with RESET formatting
        END FOR

        PRINT "END" centered with dashes

    EXCEPT ValueError
        # Handle case where input is not a valid integer
        PRINT "Invalid input! Please enter a valid number for the age or number of members."

    EXCEPT Exception as e
        # Handle any other unexpected errors
        PRINT "An error occurred: ", e

END
"""