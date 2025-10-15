#include <bits/stdc++.h>
using namespace std;

// DFS Approach
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(auto it : adj[node])
        if(!visited[it]) dfs(it, adj, visited, st);
    st.push(node);
}

// Kahn's Algorithm
vector<int> kahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0), result;
    for(int i=0;i<V;i++)
        for(auto it : adj[i])
            indegree[it]++;
    
    queue<int> q;
    for(int i=0;i<V;i++)
        if(indegree[i]==0) q.push(i);
    
    while(!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return result;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // DFS Topological Sort
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
        if(!visited[i]) dfs(i, adj, visited, st);
    
    cout << "DFS Topo Sort: ";
    while(!st.empty()){ cout << st.top() << " "; st.pop(); }
    cout << endl;

    // Kahn's Algorithm
    vector<int> topo = kahn(V, adj);
    cout << "Kahn's Topo Sort: ";
    for(int x: topo) cout << x << " ";
    cout << endl;

    return 0;
}
