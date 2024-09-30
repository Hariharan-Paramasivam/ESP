import os
import shutil
import time
from datetime import datetime
import schedule

def backup_files(src_dir, backup_dir, days):
    """Backs up files from the source directory to the destination directory,
    considering modification time and avoiding self-copying.

    Args:
        src_dir (str): The source directory path.
        backup_dir (str): The backup directory path.
        days (int): The number of days to look back for file modifications.
    """

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
                    # Copy the file to the backup directory, preserving metadata.
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

    # Schedule the backup to run every hour
    schedule.every().hour.do(backup_files, src_directory, backup_directory, days_to_backup)

    # Start the scheduler
    while True:
        schedule.run_pending()
        time.sleep(1)

except ValueError:
    # Handle invalid input for the number of days.
    print("Invalid input! Please enter a valid number of days.")

except Exception as e:
    # Handle any unexpected errors.
    print(f"An error occurred: {e}")