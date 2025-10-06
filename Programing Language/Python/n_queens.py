def is_safe(board, row, col, n):
    for j in range(col):
        if board[row][j] == 1:
            return False
    
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens(n):
    board = [[0 for x in range(n)] for y in range(n)]
    
    def solve_util(board, col):
        if col >= n:
            return True
        
        for i in range(n):
            if is_safe(board, i, col, n):
                board[i][col] = 1
                
                if solve_util(board, col + 1):
                    return True
                
                board[i][col] = 0
        
        return False
    
    if solve_util(board, 0) == False:
        print("Solution does not exist")
        return False
    
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=" ")
        print()
    return True

print("Solution for 4-Queens problem:")
solve_n_queens(4)