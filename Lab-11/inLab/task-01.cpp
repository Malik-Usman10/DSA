#include <iostream>
using namespace std;

#define max 10
class GraphNode
{
public:
    int vertex;
    int weight;
    GraphNode *next;

    GraphNode()
    {
        vertex = 0;
        weight = 0;
        next = nullptr;
    }
};

class Graph
{
    GraphNode *headnodes[max];
    int n; // Number of vertex below headNode
    int visited[max];

public:
    Graph()
    {
        n = 0;
        for (int i = 0; i < max; i++)
        {
            headnodes[i] = nullptr;
            visited[i] = 0;
        }
    }
    ~Graph()
    {
    }
    void create()
    {
        
    }
    void initialize_visited()
    {

    }
    void addVertex(int vertex)
    {
        if (vertex >= max)
        {
            cout << "Maximum No of Vertex Reached" << endl;
            return;
        }
        if (headnodes[vertex] == nullptr)
        {
            cout << "Vertex Already Exist" << endl;
            return;
        }
        headnodes[vertex] = nullptr;
        cout << "Vertex Added Successfully" << endl;
    }
    
    void removeVertex(int vertex)
    {
        if (vertex >= n || headnodes[vertex] == nullptr)
        {
            cout << "Vertex Does not Exist" << endl;
            return;
        }
        delete headnodes[vertex];
        headnodes[vertex] = nullptr;
        for (int i = 0; i < n; i++)
        {
            GraphNode *temp = headnodes[i];
            GraphNode *prev = nullptr;
            while (temp)
            {
                if (temp->vertex == vertex)
                {
                    if (prev)
                    {
                        prev->next = temp->next;
                    }
                    else
                    {
                        headnodes[i] = temp->next;
                    }
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        cout << "Vertex" << vertex << "And Itx Edges Removed" << endl;
    }
    void addEdge(int vertex1, int vertex2)
    {
        if (vertex1 >= n || vertex2 >= n || headnodes[vertex1] == nullptr || headnodes[vertex2] == nullptr)
        {
            cout << "Invalid Invertice" << endl;
            return;
        }
        GraphNode *newNode = new GraphNode();
        newNode->vertex = vertex2;
        newNode->next = headnodes[vertex1];
        headnodes[vertex1] = newNode;
        cout << "Edge Added Between" << vertex1 << "And " << vertex2 << endl;
    }
    void removeEdge(int vertex1, int vertex2)
    {
        if (vertex1 >= n || vertex2 >= n || headnodes[vertex1] == nullptr || headnodes[vertex2] == nullptr)
        {
            cout << "Edge Does not exist between them" << endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            GraphNode* temp = headnodes[i];
            GraphNode* prev = nullptr;
        }
        
        



    }
    bool vertexExists(int vertex)
    {
        return true;
    }
    int examine_n() const
    {
        return n;
    }
    int getWeight(int vertex1, int vertex2)
    {
        return 0;
    }
    void printGraph()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Vertex " << i << ":";
            GraphNode *temp = headnodes[i];
            while (temp)
            {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    int opt = 0;
    int vertex, otherVertex;
    while (opt != 9)
    {
        cout << "\n----------------------------------" << endl;
        cout << "1: Add Vertex" << endl;
        cout << "2: Remove Vertex" << endl;
        cout << "3: Check Vertex Exists" << endl;
        cout << "4: Add Edge" << endl;
        cout << "5: Remove Edge" << endl;
        cout << "6: Examine n" << endl;
        cout << "7: Get Weight" << endl;
        cout << "8: Print Graph" << endl;
        cout << "9: Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter the Number: " << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter the Vertex to Add: " << endl;
            cin >> vertex;
            g.addVertex(vertex);
            break;
        case 2:
            cout << "Enter the Vertex to Remove " << endl;
            cin >> vertex;
            g.removeVertex(vertex);
            break;
        case 3:
            cout << "Enter the Vertex to Check if Exist" << endl;
            cin >> vertex;
            g.vertexExists(vertex);
            break;
        case 4:
            cout << "Enter the Vertex One: " << endl;
            cin >> vertex;
            cout << "Enter the Vertex Two" << endl;
            cin >> otherVertex;
            g.addEdge(vertex, otherVertex);
            break;
        case 5:
            cout << "Enter the Vertex One: " << endl;
            cin >> vertex;
            cout << "Enter the Vertex Two" << endl;
            cin >> otherVertex;
            g.removeEdge(vertex, otherVertex);
            break;
        case 6:
            cout << "Examining n ...." << endl;
            cout << g.examine_n() << endl;
            break;
        case 7:
            cout << "Enter the Vertex One: " << endl;
            cin >> vertex;
            cout << "Enter the Vertex Two" << endl;
            cin >> otherVertex;
            g.getWeight(vertex, otherVertex);
            break;
        case 8:
            cout << "Printing The Graph: " << endl;
            g.printGraph();
            break;
        case 9:
            break;
        default:
            break;
        }
    }
}