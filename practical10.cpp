#include <iostream>
#include <vector>
using namespace std;

void DFS(int v, vector<int> adj[], bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (int i : adj[v])
    {
        if (!visited[i])
        {
            DFS(i, adj, visited);
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[V] = {false};

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    return 0;
}