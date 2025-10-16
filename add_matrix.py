def calculate_diagonal_sums(matrix):
    n = len(matrix)
    if n == 0 or any(len(row) != n for row in matrix):
        print("Error: Input is not a valid square matrix.")
        return 0, 0

    main_diag_sum = 0
    secondary_diag_sum = 0

    # Iterate through the rows of the matrix
    for i in range(n):
        main_diag_sum += matrix[i][i]
        j = n - 1 - i
        secondary_diag_sum += matrix[i][j]

    return main_diag_sum, secondary_diag_sum

example_matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# Calculate the sums
main_sum, secondary_sum = calculate_diagonal_sums(example_matrix)

# Display the results
print("Input Matrix:")
for row in example_matrix:
    print(row)

print("\nMain Diagonal Sum:", main_sum)
print("Secondary Diagonal Sum:", secondary_sum)


example_matrix_2 = [
    [1, 0, 0, 0],
    [0, 2, 0, 0],
    [0, 0, 3, 0],
    [0, 0, 0, 4]
]

main_sum_2, secondary_sum_2 = calculate_diagonal_sums(example_matrix_2)

print("\n----------------------------------------------------------------------")
print("Second Input Matrix:")
for row in example_matrix_2:
    print(row)

print("\nMain Diagonal Sum:", main_sum_2) # Expected: 1 + 2 + 3 + 4 = 10
print("Secondary Diagonal Sum:", secondary_sum_2) # Expected: 0 + 0 + 0 + 0 = 0