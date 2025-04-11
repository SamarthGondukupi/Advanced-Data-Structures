//  Study of Dijkstra's algorithm for minimum spanning tree. 

#include <iostream> 
#include <vector> 
#include <queue> 
#include <limits> 
using namespace std; 
// Define an edge as a pair (neighbor, weight) 
typedef pair<int, int> Edge; 
void dijkstra(vector<vector<Edge>>& graph, int source) { 
int V = graph.size(); 
vector<int> dist(V, numeric_limits<int>::max()); // Distance array initialized to infinity 
priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap 
dist[source] = 0; 
pq.push({0, source}); // (distance, vertex) 
while (!pq.empty()) { 
int currDist = pq.top().first; 
int u = pq.top().second; 
pq.pop(); 
if (currDist > dist[u]) continue; // Ignore outdated distances 
for (const auto& neighbor : graph[u]) { 
int v = neighbor.first; 
int weight = neighbor.second; 
if (dist[u] + weight < dist[v]) { 
dist[v] = dist[u] + weight; 
pq.push({dist[v], v}); 
} 
} 
} 
// Output the shortest distances 
cout << "Vertex\tDistance from Source" << endl; 
for (int i = 0; i < V; i++) { 
cout << i << "\t" << dist[i] << endl; 
} 
} 
int main() { 
int V = 5; // Number of vertices 
vector<vector<Edge>> graph(V); 
// Add edges (u, v, weight) 
graph[0].push_back({1, 10}); 
graph[0].push_back({3, 5}); 
graph[1].push_back({2, 1}); 
graph[1].push_back({3, 2}); 
graph[2].push_back({4, 4}); 
graph[3].push_back({1, 3}); 
graph[3].push_back({2, 9}); 
graph[3].push_back({4, 2}); 
graph[4].push_back({2, 6}); 
int source = 0; 
dijkstra(graph, source); 
return 0; 
}