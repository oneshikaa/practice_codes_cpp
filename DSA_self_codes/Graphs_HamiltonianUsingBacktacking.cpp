// #include <bits/stdc++.h>
#include<iostream>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

void hamiltonianCycle(vector<vector<int>>& adj, vector<int>& path, vector<bool>& visited, int n, int v, int start) {
    if (path.size() == n) {
        // If all vertices are visited, and there is a path from last vertex to the starting vertex, then it's a cycle
        if (adj[v][start] == 1) {
            path.push_back(start);
            for (int i = 0; i < n; i++) {
                cout << path[i] << " ";
            }
            cout << start << endl;
            path.pop_back();
        }
        return;
    }
    visited[v] = true;
    path.push_back(v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            hamiltonianCycle(adj, path, visited, n, i, start);
        }
    }
    path.pop_back();
    visited[v] = false;
}


int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    vector<int> path;
    vector<bool> visited(n, false);
    hamiltonianCycle(adj, path, visited, n, 0, 0);
    return 0;
}
