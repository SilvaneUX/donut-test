def max_sum_rectangle(matrix: list) -> int:
    if not matrix or not matrix[0]:
        return 0
    rows, cols = len(matrix), len(matrix[0])
    max_sum = float("-inf")
    for left in range(cols):
        temp = [0]*rows
        for right in range(left, cols):
            for r in range(rows):
                temp[r] += matrix[r][right]
            # Kadane on temp
            cur = temp[0]
            best = temp[0]
            for x in temp[1:]:
                cur = max(x, cur + x)
                best = max(best, cur)
            max_sum = max(max_sum, best)
    return max_sum

# Example
mat = [[1,2,-1,-4,-20],
       [-8,-3,4,2,1],
       [3,8,10,1,3],
       [-4,-1,1,7,-6]]
print(max_sum_rectangle(mat))  # 29


