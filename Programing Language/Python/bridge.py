def critical_connections(n: int, edges: list) -> list:
    g = [[] for _ in range(n)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    disc = [-1]*n
    low = [0]*n
    time = 0
    res = []

    def dfs(u, parent):
        nonlocal time
        disc[u] = low[u] = time
        time += 1
        for v in g[u]:
            if v == parent:
                continue
            if disc[v] == -1:
                dfs(v, u)
                low[u] = min(low[u], low[v])
                if low[v] > disc[u]:
                    res.append([u, v])
            else:
                low[u] = min(low[u], disc[v])

    for i in range(n):
        if disc[i] == -1:
            dfs(i, -1)
    return res

# Example
n = 4
edges = [[0,1],[1,2],[2,0],[1,3]]
print(critical_connections(n, edges))  # [[1,3]]
