#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void printMST(const vector<int> &parent, const vector<vector<int>> &graph, int V)
{
    cout << "Edges in MST:" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

void primMST(const vector<vector<int>> &graph, int V)
{
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
                pq.push({key[v], v});
            }
        }
    }

    printMST(parent, graph, V);
}

int main()
{
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph, V);

    return 0;
}

