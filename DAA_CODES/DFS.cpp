#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int start) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        stack<int> s;
        visited[start] = true;
        s.push(start);

        while (!s.empty()) {
            int v = s.top();
            cout << v << " ";
            s.pop();

            for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    s.push(*it);
                }
            }
        }
        delete[] visited;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    return 0;
}
