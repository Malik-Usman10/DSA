#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int dest;
    int weight;
    Edge(int d, int w) : dest(d), weight(w) {}
};

class Graph {
private:
    int V; 
    vector<vector<Edge>> adj; 

public:
    Graph(int vertices) : V(vertices) 
    {
        adj.resize(vertices + 1); 
    }

    void addEdge(int src, int dest, int weight) 
    {
        adj[src].push_back(Edge(dest, weight));
    }

    vector<long long> shortestPath(int source) 
    {
        vector<long long> dist(V + 1, numeric_limits<long long>::max());
        
        priority_queue<pair<long long, int>, 
                      vector<pair<long long, int>>, 
                      greater<pair<long long, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) 
        {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const Edge& edge : adj[u]) 
            {
                int v = edge.dest;
                long long weight = edge.weight;

                if (dist[u] + weight < dist[v]) 
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int n, m; 
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) 
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int source = 1; 
    vector<long long> distances = g.shortestPath(source);

    for (int i = 1; i <= n; i++) 
    {
        if (distances[i] == numeric_limits<long long>::max())
        {
            cout << "INF";
        }
        else
        {
            cout << distances[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
