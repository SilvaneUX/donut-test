def add_operators(num: str, target: int) -> list:
    res = []
    n = len(num)

    def dfs(index, path, value, last):
        if index == n:
            if value == target:
                res.append(path)
            return
        for i in range(index+1, n+1):
            s = num[index:i]
            if len(s) > 1 and s[0] == "0":
                break
            cur = int(s)
            if index == 0:
                dfs(i, s, cur, cur)
            else:
                dfs(i, path + "+" + s, value + cur, cur)
                dfs(i, path + "-" + s, value - cur, -cur)
                dfs(i, path + "*" + s, value - last + last * cur, last * cur)

    dfs(0, "", 0, 0)
    return res

# Example
print(add_operators("123", 6))  # ["1+2+3", "1*2*3"]
