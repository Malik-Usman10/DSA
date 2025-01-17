#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjMat; 
    int vertex;                
    int edge;                  
    bool isDirected;           
public:
    Graph(int v, bool directed = false) : vertex(v), edge(0), isDirected(directed) 
    {
        adjMat.resize(vertex, vector<int>(vertex, 0));
    }

    bool isEmpty() const 
    {
        return edge == 0;
    }

    void insertEdge(int u, int v) 
    {
        if (!isValidVertex(u) || !isValidVertex(v)) 
        {
            cout << "Error: Invalid vertex/vertices.\n";
            return;
        }

        if (adjMat[u][v] == 0) 
        {
            adjMat[u][v] = 1; 
            if (!isDirected) 
            {
                adjMat[v][u] = 1; 
            }
            edge++;
            cout << "Edge added between " << u << " and " << v << ".\n";
        }
        else 
        {
            cout << "Edge already exists between " << u << " and " << v << ".\n";
        }
    }

    void deleteEdge(int u, int v) 
    {
        if (!isValidVertex(u) || !isValidVertex(v)) 
        {
            cout << "Error: Invalid vertex/vertices.\n";
            return;
        }

        if (adjMat[u][v] == 1) 
        {
            adjMat[u][v] = 0; 
            if (!isDirected) 
            {
                adjMat[v][u] = 0;
            }
            edge--;
            cout << "Edge removed between " << u << " and " << v << ".\n";
        }
        else 
        {
            cout << "No edge exists between " << u << " and " << v << ".\n";
        }
    }

    void printGraph() const 
    {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertex; i++) 
        {
            for (int j = 0; j < vertex; j++) 
            {
                cout << adjMat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void displayEdges() const 
    {
        cout << "\nEdges in the Graph:\n";
        for (int i = 0; i < vertex; i++) 
        {
            for (int j = 0; j < vertex; j++) 
            {
                if (adjMat[i][j] == 1) 
                {
                    cout << "(" << i << " -> " << j << ")";
                    if (!isDirected && i > j) 
                    {
                        continue; 
                    }
                    cout << "\n";
                }
            }
        }
    }

    ~Graph() 
    {
        cout << "Graph destroyed. Memory cleaned up.\n";
    }

private:
    bool isValidVertex(int v) const 
    {
        return v >= 0 && v < vertex;
    }
};

int main() 
{
    int vertices = 5;
    bool isDirected = false;
    Graph g(vertices, isDirected);

    cout << "Is graph empty? " << (g.isEmpty() ? "Yes" : "No") << "\n";

    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    g.insertEdge(4, 0); 

    cout << "\nGraph after adding edges:\n";
    g.printGraph();
    g.displayEdges();

    g.deleteEdge(1, 3);
    cout << "\nGraph after deleting edge (1, 3):\n";
    g.printGraph();
    g.displayEdges();

    cout << "Is graph empty? " << (g.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}