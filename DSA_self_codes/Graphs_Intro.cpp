#include<iostream>
#include<utility>
#include<vector>

using namespace std;

class Graph{

    public :

    int v ;
    #define v 4
    bool adjMat[v+1][v+1]={0}; 
    int m ;
    int color[v] = {0} ; 

    Graph(){
    int colors;
    cout<<"enter number of colors :"<<endl;
    cin>>colors;

    m = colors;

    int e;
    
    cout<<"enter number of edges : ";
    cin>>e;
    
    
    for (int i = 0; i < e; i++)
    {
        int v1,v2;
        cout<<"enter v1 : ";
        cin>>v1;
        cout<<"enter v2 : ";
        cin>>v2;
        adjMat[v1][v2]=1;
        adjMat[v2][v1]=1;
    }

    cout<<"Graph :"<<endl;
    for (int i = 1; i < v+1; i++)
    {
        for (int j = 1; j < v+1; j++)
        {
            cout<<adjMat[i][j];
        }
        cout<<endl;
    }

    }

    void addEdge_forList(vector<int>adj[],int v1,int v2){
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
    }

    void print_adjList(vector<int>adj[],int V){
        for (int i = 0; i < V; i++)
        {
            cout << "\n Adjacency list of vertex " << i
            << "\n head ";
            for(auto x : adj[v]){
                cout<<"->"<<x;        
            }
            cout<<endl;
        }
    }

    //utility function
    void DFS_U(int u,vector<int>adj[],vector<bool>&visited){
        visited[u] = true;
        cout<<u<<" ";
        for (int i = 0; i < adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==false){
                DFS_U(adj[u][i],adj,visited);
            }
        }
    }

    //actual dfs traversal function
    void DFS(vector<int>adj[],int V){
        vector<bool>visited(V,false);
        for (int u = 0; u < V; u++)
        {
            if (visited[u]==false){
                DFS_U(u,adj,visited);
            }
        }   
    }
    
    void printSol(int color[]){
        for (int i = 0; i < v; i++)
        {
            cout<<" "<<color[i];
        }
        cout<<endl;
    }

    bool isSafe(bool graph[v+1][v+1],int color[]){

        for (int i = 0; i < v; i++) 
        {
            for (int j = i+1; j< v; j++)
            {
                if(adjMat[i][j] && color[j]==color[i]){
                    return false;
                }
            }
            
        }
        return true;
    }

    bool graphColoring(bool graph[5][5],int m, int i, int color[v]){
        if(i==v){
            if(isSafe(adjMat,color)){
                cout<<"Solution : ";
                printSol(color);
                return true;
            }
        return false;
        }
        

        for (int j = 1; j <=m; j++)
        {
            color[i] = j;
            if(graphColoring(graph,m,i+1,color))
                return true;

            color[i] =0;  

        }
        return false;        
    }
};


int main(){
    
    Graph g;
    g.graphColoring(g.adjMat,g.m,0,g.color);


    // int V = 5;
    // vector<int> adj[V];
    // addEdge_forList(adj, 0, 1);
    // addEdge_forList(adj, 0, 4);
    // addEdge_forList(adj, 1, 2);
    // addEdge_forList(adj, 1, 3);
    // addEdge_forList(adj, 1, 4);
    // addEdge_forList(adj, 2, 3);
    // addEdge_forList(adj, 3, 4);

    // print_adjList(adj, V);
    // DFS(adj,V);

}