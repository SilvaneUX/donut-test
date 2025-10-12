#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj; 

    // function for DFS cycle detection
    bool dfsUtil(int node, int parent, vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsUtil(neighbor, node, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    // function for BFS cycle detection
    bool bfsUtil(int start, vector<bool>& visited) {
        queue<pair<int, int>> q; 
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check cycle using DFS
    bool isCyclicDFS() {
        vector<bool> visited(V, false);

        // handles disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsUtil(i, -1, visited))
                    return true;
            }
        }
        return false;
    }

    // Check cycle using BFS
    bool isCyclicBFS() {
        vector<bool> visited(V, false);

        // handles disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsUtil(i, visited))
                    return true;
            }
        }
        return false;
    }

    // Display the graph
    void display() {
        cout << "\nGraph Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example 1: Graph with cycle
    cout << "===== Example 1: Graph with Cycle =====\n";
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(3, 4);
    
    g1.display();
    
    cout << "\nCycle Detection using DFS: ";
    if (g1.isCyclicDFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    
    cout << "Cycle Detection using BFS: ";
    if (g1.isCyclicBFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    // Example 2: Graph without cycle (Tree)
    cout << "\n===== Example 2: Graph without Cycle =====\n";
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    
    g2.display();
    
    cout << "\nCycle Detection using DFS: ";
    if (g2.isCyclicDFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    
    cout << "Cycle Detection using BFS: ";
    if (g2.isCyclicBFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    // Example 3: Single cycle
    cout << "\n===== Example 3: Single Cycle =====\n";
    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 0);
    
    g3.display();
    
    cout << "\nCycle Detection using DFS: ";
    if (g3.isCyclicDFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    
    cout << "Cycle Detection using BFS: ";
    if (g3.isCyclicBFS())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}