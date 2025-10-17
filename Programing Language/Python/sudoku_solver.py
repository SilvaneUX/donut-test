def solve_sudoku(board: list) -> None:
    from collections import defaultdict
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    empties = []

    for r in range(9):
        for c in range(9):
            val = board[r][c]
            if val == ".":
                empties.append((r, c))
            else:
                rows[r].add(val)
                cols[c].add(val)
                boxes[(r//3)*3 + c//3].add(val)

    def backtrack(i=0):
        if i == len(empties):
            return True
        r, c = empties[i]
        b = (r//3)*3 + c//3
        for d in "123456789":
            if d not in rows[r] and d not in cols[c] and d not in boxes[b]:
                rows[r].add(d); cols[c].add(d); boxes[b].add(d)
                board[r][c] = d
                if backtrack(i+1):
                    return True
                board[r][c] = "."
                rows[r].remove(d); cols[c].remove(d); boxes[b].remove(d)
        return False

    backtrack()

# Example board
board = [
 ["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]
]
solve_sudoku(board)
for row in board:
    print("".join(row))
