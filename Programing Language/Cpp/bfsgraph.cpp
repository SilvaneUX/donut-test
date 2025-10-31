#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges, src, dest, start;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (src dest):\n";
    for (int i = 0; i < edges; i++) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
