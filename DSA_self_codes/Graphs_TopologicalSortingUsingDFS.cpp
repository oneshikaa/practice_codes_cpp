#include <bits/stdc++.h>
#include<iostream>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

/*
Create a stack to store the nodes.
Initialize visited array of size N to keep the record of visited nodes.
Run a loop from 0 till N
if the node is not marked True in visited array
Call the recursive function for topological sort and perform the following steps.
Mark the current node as True in the visited array.
Run a loop on all the nodes which has a directed edge to the current node
if the node is not marked True in the visited array:
Recursively call the topological sort function on the node
Push the current node in the stack.
Print all the elements in the stack.
*/

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &s) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];//storing the adjacent vertex
        if (!visited[v]) {
            dfs(v, visited, adj, s);
        }
    }
    s.push(node);
}

void topologicalSort(int N, vector<vector<int>> &adj) {
    vector<bool> visited(N, false);
    stack<int> s;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, s);
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<int>> adj(N);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);//we are forming a DAG
    }
    topologicalSort(N, adj);
    return 0;
}
