"""
Title: Compute Diagonal Sums of a Square Matrix
Author: [Your GitHub Username]
"""

def calculate_diagonal_sums(matrix):
    """Return sums of main and secondary diagonals of a square matrix."""
    n = len(matrix)
    if n == 0 or any(len(row) != n for row in matrix):
        print("Error: Not a valid square matrix.")
        return 0, 0

    main_sum = 0
    sec_sum = 0

    for i in range(n):
        main_sum += matrix[i][i]
        sec_sum += matrix[i][n - 1 - i]

    return main_sum, sec_sum


if __name__ == "__main__":
    # Example 1
    matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    main, sec = calculate_diagonal_sums(matrix1)
    print("Matrix 1:")
    for row in matrix1:
        print(row)
    print("\nMain Diagonal Sum:", main)
    print("Secondary Diagonal Sum:", sec)

    # Example 2
    matrix2 = [
        [1, 0, 0, 0],
        [0, 2, 0, 0],
        [0, 0, 3, 0],
        [0, 0, 0, 4]
    ]

    main2, sec2 = calculate_diagonal_sums(matrix2)
    print("\n" + "-" * 60)
    print("Matrix 2:")
    for row in matrix2:
        print(row)
    print("\nMain Diagonal Sum:", main2)
    print("Secondary Diagonal Sum:", sec2)
