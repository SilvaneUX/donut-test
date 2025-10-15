#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

// Dijkstra's Algorithm
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w]: adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Floyd-Warshall Algorithm
void floydWarshall(int V, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    
    cout << "Floyd-Warshall Distance Matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]>=INF) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> adj(V);
    vector<vector<int>> graph(V, vector<int>(V, INF));
    for(int i=0;i<V;i++) graph[i][i]=0;

    for(int i=0;i<E;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        graph[u][v] = w;
    }

    // Dijkstra from node 0
    vector<int> dist = dijkstra(V, adj, 0);
    cout << "Dijkstra distances from 0: ";
    for(int d: dist) cout << d << " ";
    cout << endl;

    // Floyd-Warshall
    floydWarshall(V, graph);

    return 0;
}
