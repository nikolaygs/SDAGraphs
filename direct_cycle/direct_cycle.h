#include <iostream>
#include <stack>
#include "../graph/graph.h"

class CycleDetectorDirectGraph {
    bool *visited;
    Graph g;

    bool dfs(int v, bool* recStack) {
        if (recStack[v])
            return true;

        if (visited[v])
            return false;

        visited[v] = true;
        recStack[v] = true;

        for (int w : g.adj(v)) {
            if (dfs(w, recStack)) {
                return true;
            }
        }

        recStack[v] = false;
        return false;
    }

public:
    CycleDetectorDirectGraph(Graph g) : g(g) , visited(new bool[g.vertices()]) {}

    int hasCycle() {
        bool* recStack = new bool[g.vertices()];
        for (int i = 0; i < g.vertices(); i++) {
            if (!visited[i]) {
                if (dfs(i, recStack)) {
                    return true;
                }
            }
        }

        return false;
    }

};