//  Study of Breadth First Traversal and Depth First Traversal for a user defined Graph. 

// C++ program for BFS and DFS of an undirected graph 
#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 
 
// BFS from given source s 
void bfs(vector<vector<int>>& adj, int s)  
{ 
    // Create a queue for BFS 
    queue<int> q;   
    vector<bool> visited(adj.size(), false); 
    visited[s] = true; 
    q.push(s); 
 
    while (!q.empty()) { 
       
       int curr = q.front(); 
        q.pop(); 
        cout << curr << " "; 
 
        for (int x : adj[curr]) { 
            if (!visited[x]) { 
                visited[x] = true; 
                q.push(x); 
            } 
        } 
    } 
} 
 
// Function to add an edge to the graph BFS 
void addEdge(vector<vector<int>>& adj, 
                          int u, int v)  
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); // Undirected Graph 
} 
 
// Recursive function for DFS traversal 
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){ 
   
    visited[s] = true; 
 
    // Print the current vertex 
    cout << s << " "; 
 
    // Recursively visit all adjacent vertices 
    // that are not visited yet 
    for (int i : adj[s]) 
        if (visited[i] == false) 
            DFSRec(adj, visited, i); 
} 
 
void DFS(vector<vector<int>> &adj, int s){ 
    vector<bool> visited(adj.size(), false); 
    DFSRec(adj, visited, s); 
} 
 
// To add an edge in an undirected graph DFS 
void addEdge1(vector<vector<int>> &adj, int s, int t){ 
    adj[s].push_back(t);  
    adj[t].push_back(s);  
} 
 
int main(){ 
    int V = 5; 
    int ch; 
    int s = 0; // Starting vertex for DFS 
    vector<vector<int>> adj(V); 
    vector<vector<int>> edges={{0, 1},{0, 2},{1, 3},{1, 4},{2, 4}}; 
    
    while(1) 
    { 
        cout<<"\nEnter 1: BFS 2: DFS 3: Exit"; 
        cin>>ch; 
        switch(ch) 
        { 
            case 1: 
            // Add edges to the graph 
            addEdge(adj, 0, 1); 
            addEdge(adj, 0, 2); 
            addEdge(adj, 1, 3); 
            addEdge(adj, 1, 4); 
            addEdge(adj, 2, 4); 
 
            cout << "BFS starting from 0 : \n"; 
            bfs(adj, 0); 
            break; 
        case 2: 
     
            for (auto &e : edges) 
                addEdge1(adj, e[0], e[1]); 
            cout << "DFS from source: " << s << endl; 
            DFS(adj, s); // Perform DFS starting from the source vertex 
            break; 
        case 3: 
            return 0; 
        } 
    } 
    return 0; 
} 