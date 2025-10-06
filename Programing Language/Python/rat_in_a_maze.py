def rat_in_maze(maze, n):
    paths = []
    path = [['0'] * n for _ in range(n)]

    def solve(x, y):
        if x == n - 1 and y == n - 1 and maze[x][y] == 1:
            path[x][y] = '1'
            temp = [''.join(row) for row in path]
            paths.append(temp)
            path[x][y] = '0'
            return

        if x < 0 or y < 0 or x >= n or y >= n or maze[x][y] == 0 or path[x][y] == '1':
            return

        path[x][y] = '1'

        solve(x + 1, y)  # down
        solve(x, y + 1)  # right
        solve(x - 1, y)  # up
        solve(x, y - 1)  # left

        path[x][y] = '0'

    solve(0, 0)

    return paths


# Example usage:
maze = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [0, 1, 0, 0],
    [1, 1, 1, 1]
]

result = rat_in_maze(maze, 4)
if result:
    print("Possible paths:")
    for p in result:
        for row in p:
            print(row)
        print()
else:
    print("No path found!")
