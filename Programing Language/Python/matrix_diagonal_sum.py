"""
📘 Program: Matrix Diagonal Sum Calculator
-----------------------------------------
This Python program calculates the sum of both the
main (primary) diagonal and the secondary (anti) diagonal
of a square matrix.

✨ Features:
- Accepts matrix input from user or uses a predefined example
- Handles any square matrix size (n x n)
- Clearly displays both diagonal sums
- Beginner-friendly and well-commented

"""

def diagonal_sums(matrix):
    """
    Function to compute the sums of both diagonals.
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    n = len(matrix)
    main_sum = 0
    secondary_sum = 0
    
    for i in range(n):
        main_sum += matrix[i][i]
        secondary_sum += matrix[i][n - i - 1]
        
    return main_sum, secondary_sum


if __name__ == "__main__":
    print("🌟 Matrix Diagonal Sum Calculator 🌟")
    print("Choose Input Mode:")
    print("1️⃣  Enter your own matrix")
    print("2️⃣  Use predefined example")

    choice = input("Enter 1 or 2: ").strip()

    if choice == '1':
        # User Input Mode
        n = int(input("\nEnter the size of the square matrix (n): "))
        matrix = []
        
        print("Enter the matrix elements row by row:")
        for i in range(n):
            row = list(map(int, input(f"Row {i+1}: ").split()))
            if len(row) != n:
                print("❌ Error: Each row must contain exactly", n, "elements.")
                exit()
            matrix.append(row)
    
    elif choice == '2':
        # Predefined Example
        matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        print("\n✅ Using predefined example matrix:")
    else:
        print("❌ Invalid choice! Please run the program again.")
        exit()

    # Display the matrix
    print("\nYour Matrix:")
    for row in matrix:
        print(row)
    
    # Compute diagonal sums
    main_diag, secondary_diag = diagonal_sums(matrix)
    
    # Display results
    print(f"\nMain Diagonal Sum: {main_diag}")
    print(f"Secondary Diagonal Sum: {secondary_diag}")
    
    # Optional: Check if diagonals are equal
    if main_diag == secondary_diag:
        print("🎉 Both diagonals have the same sum!")
    else:
        print("🔹 Diagonal sums are different.")
