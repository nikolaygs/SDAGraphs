#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>
#include "../graph/graph.h"

class BFSShortestPathFinder {
    bool *visited;
    Graph g;
    int* distTo;

public:
    BFSShortestPathFinder(Graph g, int v) : g(g) , visited(new bool[g.vertices()]), distTo(new int[g.vertices()]) {
        for (int i = 0; i < g.vertices(); i++) {
            distTo[i] = INT_MAX;
        }
        distTo[v] = 0;

        pathsFrom(v);
    }

    void pathsFrom(int v) {
        std::queue<int> queue; // пазим непосетените върхове в опащка
        queue.push(v);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            for (int w : g.adj(current)) {
                if (distTo[w] == INT_MAX) {
                    distTo[w] = distTo[current] + 1;
                    queue.push(w); // ако намерим непосетен връх го слагаме в опащката.
                }
            }
        }
    }

    int getMinDistTo(int w) {
        return distTo[w];
    }
};

