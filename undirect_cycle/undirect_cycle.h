#include <iostream>
#include <stack>
#include "../graph/graph.h"

class CycleDetectorUndirectGraph {
    bool *visited;
    Graph g;

    bool dfs(int v, int parent) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (visited[w] && w != parent) {
                return true;
            }

            if (!visited[w]) {
                if (dfs(w, v)) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    CycleDetectorUndirectGraph(Graph g) : g(g) , visited(new bool[g.vertices()]) {}

    int hasCycle() {
        for (int i = 0; i < g.vertices(); i++) {
            if (!visited[i]) {
                if (dfs(i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

};