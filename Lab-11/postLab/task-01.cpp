#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  
    vector<vector<int>> adj; 
    
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
    
    void BFS(int start) {
        vector<bool> visited(V, false);
        
        queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        cout << "BFS starting from vertex " << start << ": ";
        
        while (!q.empty()) {
            start = q.front();
            cout << start << " ";
            q.pop();
            
            for (int adjacent : adj[start]) 
            {
                if (!visited[adjacent]) 
                {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
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
    
    cout << "Performing BFS traversal..." << endl;
    g.BFS(0);
    
    return 0;
}
