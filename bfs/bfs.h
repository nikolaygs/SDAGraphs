#include <iostream>
#include <queue>
#include "../graph/graph.h"

using namespace std;

class BFSTraversal {
    bool visited[];
public:
    void bfs(Graph g, int v) {
        std::queue<int> queue; // 1. пазим непосетените върхове в опащка
        queue.push(v); // 2. слагаме началния връх в опашкатасс и го маркираме като посетен
        visited[v] = true;

        while (!queue.empty()) {
            int current = queue.front(); // 3. взимаме първия връх от опашката
            queue.pop();
            for (int w : g.adj(current)) { // 4. всички непосетени негови съседи слагаме в опащката
                if (!visited[w]) {
                    visited[w] = true;
                    queue.push(w);
                }
            }
        }
    }
};