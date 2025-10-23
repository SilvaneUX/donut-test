
class Graph:
    def __init__(self, directed=False):
        self.adj = {}
        self.directed = directed

    def add_edge(self, u, v):
        self.adj.setdefault(u, []).append(v)
        self.adj.setdefault(v, [])
        if not self.directed:
            self.adj[v].append(u)

    def dfs_recursive(self, start):
        visited = set()
        order = []
        def _dfs(u):
            visited.add(u)
            order.append(u)
            for v in self.adj.get(u, []):
                if v not in visited:
                    _dfs(v)
        _dfs(start)
        return order

    def dfs_iterative(self, start):
        visited = set()
        order = []
        stack = [start]
        while stack:
            u = stack.pop()
            if u in visited:
                continue
            visited.add(u)
            order.append(u)
            for v in reversed(self.adj.get(u, [])):
                if v not in visited:
                    stack.append(v)
        return order

    def connected_components(self):
        seen = set()
        comps = []
        for node in self.adj:
            if node not in seen:
                comp = []
                stack = [node]
                while stack:
                    u = stack.pop()
                    if u in seen:
                        continue
                    seen.add(u)
                    comp.append(u)
                    for v in self.adj.get(u, []):
                        if v not in seen:
                            stack.append(v)
                comps.append(comp)
        return comps

if __name__ == "__main__":
    g = Graph()
    edges = [
        ("A","B"), ("A","C"), ("B","D"), ("C","E"),
        ("D","F"), ("E","F"), ("G","H")
    ]
    for u,v in edges:
        g.add_edge(u,v)
    print(g.dfs_recursive("A"))