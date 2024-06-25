#include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

vector<int> findEulerianCircuit(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> circuit;//to store the final ans
    stack<int> stk;
    stk.push(0); // start from node 0
    while (!stk.empty()) {
        int u = stk.top();
        if (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            stk.push(v);
        } else {
            circuit.push_back(u);
            stk.pop();
        }
    }
    reverse(circuit.begin(), circuit.end()); // reverse the circuit to get correct order
    return circuit;
}


int main() {
    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> circuit = findEulerianCircuit(adj);
    for (int u : circuit) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}
