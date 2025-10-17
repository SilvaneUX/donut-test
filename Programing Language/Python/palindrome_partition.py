def min_cut_palindrome(s: str) -> int:
    n = len(s)
    if n <= 1:
        return 0
    # is_pal[i][j]
    is_pal = [[False]*n for _ in range(n)]
    for i in range(n-1, -1, -1):
        for j in range(i, n):
            if s[i] == s[j] and (j-i < 2 or is_pal[i+1][j-1]):
                is_pal[i][j] = True
    # dp[i] = min cuts for s[:i+1]
    dp = [0]*n
    for i in range(n):
        if is_pal[0][i]:
            dp[i] = 0
        else:
            mincuts = float("inf")
            for j in range(1, i+1):
                if is_pal[j][i]:
                    mincuts = min(mincuts, dp[j-1] + 1)
            dp[i] = mincuts
    return dp[-1]

# Example
print(min_cut_palindrome("aab"))  # 1
