#!/bin/bash

# A reusable function to handle the core email validation logic.
# $1: The email address string to validate.
validate_email() {
    local email="$1"
    # Regex pattern: allows letters, numbers, dots, underscores, and %/+ in the local part,
    # followed by @, followed by domain parts, ending with a TLD
    # For TLD minimum 2 chars, no max length. There are specific TLDs with long char length like .international
    local email_regex="^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"

    # Check against the regex
    if [[ "$email" =~ $email_regex ]]; then
        echo "✅ Email address '$email' is valid."
        return 0 # Success
    else
        echo "❌ Email address '$email' is invalid."
        return 1 # Failure
    fi
}

# --- Main Script Execution ---

# 1. Check if an argument was passed to the script (non-interactive mode)
if [ -n "$1" ]; then
    echo "Running in non-interactive validation mode."
    # Run the validation function with the first argument
    validate_email "$1"
    # Exit with the return code of the validation function (0 for valid, 1 for invalid)
    exit $?
fi

# 2. If no argument was provided, run the interactive loop
echo "Running in interactive mode. Press Ctrl+C to exit."
while true
do
    read -p "Enter email: " email

    # Validate input (allows re-prompting if invalid, breaks loop if valid)
    validate_email "$email"

    # $? holds the exit status of the last executed command (validate_email)
    if [ $? -eq 0 ]; then
        break
    fi
done
