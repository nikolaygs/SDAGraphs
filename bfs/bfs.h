#include <iostream>
#include <queue>
#include "../graph/graph.h"

using namespace std;

class BFSTraversal {
    Graph g;
    bool *visited;
public:
    BFSTraversal(Graph g) : g(g), visited(new bool[g.vertices()]) {}

    void bfs(int v) {
        std::queue<int> traversalOrder; // 1. пазим непосетените върхове в опащка
        traversalOrder.push(v); // 2. слагаме началния връх в опашкатасс и го маркираме като посетен
        visited[v] = true;
        while (!traversalOrder.empty()) {
            v = traversalOrder.front(); // 3. взимаме първия връх от опашката
            traversalOrder.pop();
            cout << v << " ";
            for (int w : g.adj(v)) { // 4. всички непосетени негови съседи слагаме в опащката
                if (!visited[w]) {
                    visited[w] = true;
                    traversalOrder.push(w);
                }
            }
        }
    }
};