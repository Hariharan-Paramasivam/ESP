# Get the information of name, date of birth and blood group from the user and store it as key value pairs for 5 persons. Compute the age from the date of birth information and add as another key value pair. Combine them as a data frame and store it in a csv file.
# NAME : Hariharan P
# ROLL NO : CB.EN.P2EBS24021
# DATE : 28.08.2024

import pandas as pd  # Import pandas for DataFrame creation and CSV handling.
from datetime import datetime  # Import datetime to work with date of birth and calculate age.

def calculate_age(dob):
    # Function to calculate age given a date of birth.
    today = datetime.today()  # Get today's date.
    age = today.year - dob.year - ((today.month, today.day) < (dob.month, dob.day))
    return age

try:
    print('INPUT'.center(100,'-'))
    # Get the number of persons from the user.
    num_persons = int(input("Enter the number of persons: "))

    # Initialize an empty list to store the information for each person.
    persons = []

    # Loop to gather information for the specified number of persons.
    for i in range(num_persons):
        # Get the name, date of birth, and blood group from the user.
        name = input(f"Enter the name of person {i+1}: ")
        dob_input = input(f"Enter the date of birth of {name} (format DD-MM-YYYY): ")
        blood_group = input(f"Enter the blood group of {name}: ")

        # Try to convert the date of birth string into a datetime object.
        try:
            dob = datetime.strptime(dob_input, "%d-%m-%Y")
        except ValueError:
            # Handle the case where the date of birth format is incorrect.
            print(f"Invalid date format for {name}. Please enter the date in YYYY-MM-DD format.")
            continue  # Skip this entry and ask again.

        # Calculate the age based on the date of birth.
        age = calculate_age(dob)

        # Store the information in a dictionary.
        person_info = {
            "Name": name,
            "Date of Birth(dd-mm-yyyy)": dob_input,
            "Blood Group": blood_group,
            "Age": age
        }

        # Append the dictionary to the persons list.
        persons.append(person_info)

    # Convert the list of dictionaries into a DataFrame.
    df = pd.DataFrame(persons)

    # Save the DataFrame to a CSV file.
    df.to_csv("persons_info.csv", index=False)
    print('OUTPUT'.center(100,'-'))
    print("\nData successfully saved to persons_info.csv")
    print(df) 
    print('END'.center(100,'-')) # Optionally print the DataFrame to see the result.

except ValueError:
    # Catch a ValueError if the input is not a valid integer.
    print("Invalid input! Please enter a valid number for the number of persons.")

except Exception as e:
    # Catch any other unexpected errors and print an error message.
    print(f"An error occurred: {e}")

"""
BEGIN

    # Define a function to calculate age from date of birth
    FUNCTION calculate_age(dob):
        today = GET today's date
        age = today.year - dob.year
        IF today's month and day are before dob's month and day THEN
            age = age - 1  # Adjust age if birthday hasn't occurred yet this year
        END IF
        RETURN age
    END FUNCTION

    TRY
        # Prompt user for the number of persons
        num_persons = GET integer input from user

        # Initialize an empty list to store information for each person
        Initialize an empty list called persons

        # Loop to gather information for each person
        FOR i FROM 1 TO num_persons DO
            # Prompt for the name of the person
            name = GET input from user
            
            # Prompt for the date of birth and convert it to a date object
            dob_input = GET input from user (format DD-MM-YYYY)
            TRY
                dob = CONVERT dob_input to a date object
            EXCEPT error
                PRINT error message for invalid date format
                CONTINUE to next iteration
            END TRY
            
            # Prompt for the blood group
            blood_group = GET input from user
            
            # Calculate the age using the date of birth
            age = CALL calculate_age(dob)
            
            # Create a dictionary with the person's information
            person_info = {
                "Name": name,
                "Date of Birth": dob_input,
                "Blood Group": blood_group,
                "Age": age
            }

            # Add the dictionary to the list of persons
            ADD person_info to persons
        END FOR

        # Convert the list of dictionaries to a DataFrame-like structure
        df = CONVERT persons list to a DataFrame-like structure

        # Save the DataFrame to a CSV file
        SAVE df to "persons_info.csv"

        PRINT confirmation message
        PRINT the DataFrame (optional)

    EXCEPT ValueError
        # Handle errors for invalid integer inputs
        PRINT error message for invalid number of persons

    EXCEPT error
        # Handle other unexpected errors
        PRINT error message with details

END

"""