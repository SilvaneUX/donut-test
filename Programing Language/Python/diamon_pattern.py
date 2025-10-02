def print_diamond(n):
    # Upper part of the diamond
    for i in range(n):
        # Print spaces
        for j in range(n - i - 1):
            print(" ", end="")
        # Print stars
        for j in range(2 * i + 1):
            print("*", end="")
        print()  # Move to the next line

    # Lower part of the diamond
    for i in range(n - 2, -1, -1):
        # Print spaces
        for j in range(n - i - 1):
            print(" ", end="")
        # Print stars
        for j in range(2 * i + 1):
            print("*", end="")
        print()  # Move to the next line

# Driver code
rows = 5  # You can change this value to increase or decrease the size of the diamond
print_diamond(rows)
