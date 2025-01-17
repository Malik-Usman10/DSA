#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj;  
    
    void DFSUtil(int vertex, vector<bool>& visited)
     {
        visited[vertex] = true;
        cout << vertex << " ";
        
        for (int adjacent : adj[vertex]) 
        {
            if (!visited[adjacent]) 
            {
                DFSUtil(adjacent, visited);
            }
        }
    }
    
public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }
    
    void addEdge(int v, int w) 
    {
        adj[v].push_back(w);
    }
    
    void DFS(int start) 
    {
        vector<bool> visited(V, false);
        
        cout << "DFS starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    
    cout << "Performing DFS traversal..." << endl;
    g.DFS(0);
    
    return 0;
}
