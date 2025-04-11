// Study of Prims and Kruskal algorithms for minimum spanning tree.

#include <bits/stdc++.h> 
using namespace std; 
 
#define V 5 
 
int minKey(vector<int> &key, vector<bool> &mstSet) { 
   
     
    int min = INT_MAX, min_index; 
 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
 
    return min_index; 
} 
 
 
void printMST(vector<int> &parent, vector<vector<int>> &graph) { 
    cout << "Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout << parent[i] << " - " << i << " \t" 
             << graph[parent[i]][i] << " \n"; 
} 
 
 
void primMST(vector<vector<int>> &graph) { 
   
    vector<int> parent(V); 
    vector<int> key(V); 
    vector<bool> mstSet(V); 
 
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
 
    key[0] = 0; 
   
    parent[0] = -1; 
 
    for (int count = 0; count < V - 1; count++) { 
         
        int u = minKey(key, mstSet); 
 
        mstSet[u] = true; 
 
        for (int v = 0; v < V; v++) 
 
            if (graph[u][v] && mstSet[v] == false 
                && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
 
     printMST(parent, graph); 
} 
 
class DSU { 
    int* parent; 
    int* rank; 
 
public: 
    DSU(int n) 
    { 
        parent = new int[n]; 
        rank = new int[n]; 
 
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
 
    int find(int i) 
    { 
        if (parent[i] == -1) 
            return i; 
 
        return parent[i] = find(parent[i]); 
    } 
 
    void unite(int x, int y) 
    { 
        int s1 = find(x); 
        int s2 = find(y); 
 
        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    } 
}; 
 
class Graph { 
    vector<vector<int> > edgelist; 
    int V1; 
 
public: 
    Graph(int V1) { this->V1 = V1; } 
 
    void addEdge(int x, int y, int w) 
    { 
        edgelist.push_back({ w, x, y }); 
    } 
 
    void kruskals_mst() 
    { 
        sort(edgelist.begin(), edgelist.end()); 
 
        DSU s(V1); 
        int ans = 0; 
          int count = 0;  // To keep track of the number of edges in MST 
        cout << "Following are the edges in the " 
                "constructed MST" 
             << endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
 
            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
                count++;   
            } 
            if (count == V1 - 1) { 
                break; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
}; 
 
int main() { 
    int ch; 
      vector<vector<int>> graph = { { 0, 2, 0, 6, 0 }, 
                                { 2, 0, 3, 8, 5 }, 
                                { 0, 3, 0, 0, 7 }, 
                                { 6, 8, 0, 0, 9 }, 
                                { 0, 5, 7, 9, 0 } }; 
    Graph g(4); 
    while(1) 
    { 
        cout<<"\nEnter 1: Prims 2: Kruskal 3: Exit"; 
        cin>>ch; 
        switch(ch) 
        { 
            case 1: 
             primMST(graph); 
             break; 
            case 2: 
                g.addEdge(0, 1, 10); 
                g.addEdge(1, 3, 15); 
                g.addEdge(2, 3, 4); 
                g.addEdge(2, 0, 6); 
                g.addEdge(0, 3, 5); 
                g.kruskals_mst(); 
                break; 
        case 3: 
            return 0; 
        } 
    } 
    return 0; 
}