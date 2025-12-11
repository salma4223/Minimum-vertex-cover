#include <iostream>
#include <vector>
using namespace std;

/*
Vertex Cover Problem:
A vertex cover is a set of vertices that includes at least one endpoint 
of every edge in the graph.

We want to find the MINIMUM vertex cover (smallest number of vertices).
*/

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list
    
public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    
    // Add an edge between u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // MAIN FUNCTION: Find minimum vertex cover
    vector<int> findMinimumVertexCover() {
        vector<bool> visited(V, false);
        vector<int> cover;
        
        // Try all subsets of vertices
        for (int mask = 0; mask < (1 << V); mask++) {
            vector<int> currentCover;
            
            // Build current subset based on mask bits
            // If bit i is 1, vertex i is in the cover
            for (int i = 0; i < V; i++) {
                if (mask & (1 << i)) {
                    currentCover.push_back(i);
                }
            }
            
            // Check if this subset is a valid vertex cover
            if (isVertexCover(currentCover)) {
                // If it's smaller than current best, update
                if (cover.empty() || currentCover.size() < cover.size()) {
                    cover = currentCover;
                }
            }
        }
        
        return cover;
    }
    
    // Check if a set of vertices covers all edges
    bool isVertexCover(const vector<int>& vertices) {
        // Mark which vertices are in the cover
        vector<bool> inCover(V, false);
        for (int v : vertices) {
            inCover[v] = true;
        }
        
        // Check every edge
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                // Only check each edge once (u < v)
                if (u < v) {
                    // If neither endpoint is in cover, it's not a valid cover
                    if (!inCover[u] && !inCover[v]) {
                        return false;
                    }
                }
            }
        }
        
        return true;  // All edges covered
    }
    
    // Print the graph
    void printGraph() {
        cout << "Graph edges:\n";
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                if (u < v) {  // Print each edge only once
                    cout << u << " -- " << v << endl;
                }
            }
        }
    }
};

// Example usage
int main() {
    // Create a graph with 4 vertices
    Graph g(4);
    
    // Add edges (creating a square: 0-1-2-3-0)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    
    cout << "=== Vertex Cover Solver ===\n";
    g.printGraph();
    
    // Find minimum vertex cover
    vector<int> minCover = g.findMinimumVertexCover();
    
    // Display result
    cout << "\nMinimum Vertex Cover (size " << minCover.size() << "): ";
    for (int v : minCover) {
        cout << v << " ";
    }
    cout << endl;
    
    return 0;
}