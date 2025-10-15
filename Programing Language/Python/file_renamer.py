import os
import sys

def rename_files(directory, search_string, replace_string):
    """
    Renames files in a specified directory by replacing a search string with a 
    replace string in their filenames.

    Args:
        directory (str): The path to the directory containing the files.
        search_string (str): The string to search for in the filenames.
        replace_string (str): The string to replace the search string with.
    """
    # 1. Check if the provided directory path exists
    if not os.path.isdir(directory):
        print(f"Error: Directory not found at '{directory}'")
        return

    print(f"--- Starting rename operation in: {directory} ---")
    
    renamed_count = 0
    skipped_count = 0

    try:
        # Loop through all items (files and folders) in the directory
        for filename in os.listdir(directory):
            old_filepath = os.path.join(directory, filename)

            # --- Improvement: Check if the item is a file (skipping directories) ---
            if not os.path.isfile(old_filepath):
                # Optionally print skipped directories
                # print(f"Skipped directory: {filename}")
                skipped_count += 1
                continue
            
            # Check if the search string is present in the current filename
            if search_string in filename:
                
                # Construct the new filename by replacing the search string
                new_filename = filename.replace(search_string, replace_string)
                
                # Get the full path for the new filename
                new_filepath = os.path.join(directory, new_filename)
                
                # Perform the rename operation
                os.rename(old_filepath, new_filepath)
                
                print(f"Renamed: '{filename}' -> '{new_filename}'")
                renamed_count += 1
            
            # --- Optional: If you want to print files that did not match the string ---
            # else:
            #     print(f"Skipped (no match): '{filename}'")
                
    except Exception as e:
        # Catch any unexpected errors during the file operations (e.g., permission denied)
        print(f"\nAn error occurred during renaming: {e}")
        return

    print(f"\n--- Rename operation complete. ---")
    print(f"{renamed_count} file(s) renamed.")
    print(f"{skipped_count} item(s) skipped (not files or could not be processed).")


def main():
    """
    Main function to handle user input and run the rename_files utility.
    """
    print("Python Batch File Renamer Utility")
    print("---------------------------------")
    
    # Get inputs from the user
    
    # 1. Directory path
    directory = input("Enter the directory path to work in (e.g., C:\\MyFiles or /home/user/docs): ").strip()
    
    # 2. Search string
    search_string = input("Enter the text to FIND in the filenames: ").strip()
    
    # Check if the search string is empty to prevent unintended full renames
    if not search_string:
        print("Error: The text to find cannot be empty.")
        return

    # 3. Replace string
    replace_string = input("Enter the text to REPLACE it with (leave blank to delete the found text): ").strip()
    
    # Confirm with the user before proceeding
    print("\n--- Confirmation ---")
    print(f"Directory: {directory}")
    print(f"Search for: '{search_string}'")
    print(f"Replace with: '{replace_string}'")
    
    confirmation = input("Proceed with renaming? (yes/no): ").strip().lower()

    if confirmation == 'yes':
        # Execute the renaming function
        rename_files(directory, search_string, replace_string)
    else:
        print("Operation cancelled by the user.")


if __name__ == "__main__":
    main()
