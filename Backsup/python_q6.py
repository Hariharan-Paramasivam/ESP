# Automate a task of backing up files based on time in the Windows environment.
# NAME : Hariharan P
# ROLL NO : CB.EN.P2EBS24021
# DATE : 28.08.2024

import os
import shutil
import time
from datetime import datetime

def backup_files(src_dir, backup_dir, days):
    try:
        # Calculate the cutoff time for file modification.
        cutoff_time = time.time() - days * 86400  # Convert days to seconds.
        print('OUTPUT'.center(100, '-'))
        
        # Ensure the backup directory exists.
        if not os.path.exists(backup_dir):
            os.makedirs(backup_dir)
            print(f"Backup directory {backup_dir} created.")
        
        # Loop through all files in the source directory.
        for foldername, subfolders, filenames in os.walk(src_dir):
            for filename in filenames:
                # Get the full file path.
                file_path = os.path.join(foldername, filename)
                
                # Determine the backup file path.
                backup_file_path = os.path.join(backup_dir, filename)
                
                # Ensure the source file and backup file are not the same
                if os.path.abspath(file_path) == os.path.abspath(backup_file_path):
                    print(f"Skipping copy for {file_path} as it is the same as the backup path.")
                    continue

                # Check if the file was modified within the last 'days' days.
                if os.path.getmtime(file_path) >= cutoff_time:
                    # Copy the file to the backup directory.
                    shutil.copy2(file_path, backup_file_path)
                    print(f"Copied: {file_path} to {backup_file_path}")

        print("Backup process completed successfully.")
        print('END'.center(100, '-'))

    except Exception as e:
        # Handle any unexpected errors during the backup process.
        print(f"An error occurred during the backup process: {e}")

try:
    # Define source and backup directories.
    print('INPUT'.center(100, '-'))
    src_directory = input("Enter the source directory path: ")
    backup_directory = input("Enter the backup directory path: ")

    # Get the number of days from the user to determine which files to back up.
    days_to_backup = int(input("Enter the number of days to look back for file modifications: "))

    # Perform the backup.
    backup_files(src_directory, backup_directory, days_to_backup)

except ValueError:
    # Handle invalid input for the number of days.
    print("Invalid input! Please enter a valid number of days.")

except Exception as e:
    # Handle any unexpected errors.
    print(f"An error occurred: {e}")


"""
BEGIN

    # Define a function to perform file backup
    FUNCTION backup_files(src_dir, backup_dir, days):
        TRY
            # Calculate the cutoff time for file modification
            cutoff_time = CURRENT_TIME - (days * SECONDS_PER_DAY)
            
            # Ensure the backup directory exists
            IF backup_dir does not exist THEN
                CREATE backup_dir
                PRINT "Backup directory created."
            END IF

            # Loop through all files in the source directory
            FOR each file in src_dir DO
                # Get the last modification time of the file
                file_mod_time = GET last modification time of file

                # Check if the file was modified within the last 'days' days
                IF file_mod_time >= cutoff_time THEN
                    # Determine the backup file path
                    backup_file_path = COMBINE backup_dir and filename

                    # Copy the file to the backup directory
                    COPY file to backup_file_path
                    PRINT "Copied: ", file, " to ", backup_file_path
                END IF
            END FOR

            PRINT "Backup process completed successfully."
        
        EXCEPT error
            # Handle any unexpected errors during the backup process
            PRINT "An error occurred during the backup process: ", error

    END FUNCTION

    TRY
        # Define source and backup directories
        PRINT "INPUT"
        src_directory = GET input from user for source directory path
        backup_directory = GET input from user for backup directory path

        # Get the number of days from the user to determine which files to back up
        days_to_backup = GET integer input from user for number of days

        # Perform the backup
        CALL backup_files(src_directory, backup_directory, days_to_backup)
    
    EXCEPT ValueError
        # Handle invalid input for the number of days
        PRINT "Invalid input! Please enter a valid number of days."
    
    EXCEPT error
        # Handle any unexpected errors
        PRINT "An error occurred: ", error

END
"""