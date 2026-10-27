#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return 0;
}