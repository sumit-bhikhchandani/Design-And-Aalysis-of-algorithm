// C++ implementation of Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

struct Subset {
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

vector<Edge> KruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result;
    int e = 0, i = 0;

    sort(graph.edges.begin(), graph.edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    Subset *subsets = new Subset[V * sizeof(Subset)];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    delete[] subsets;
    return result;
}

int main() {
    Graph graph;
    graph.V = 4;
    graph.E = 5;

    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({0, 3, 5});
    graph.edges.push_back({1, 3, 15});
    graph.edges.push_back({2, 3, 4});

    vector<Edge> MST = KruskalMST(graph);

    cout << "Edges in MST:\n";
    for (Edge edge : MST)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    
    return 0;
}
