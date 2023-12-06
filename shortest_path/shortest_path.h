#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>
#include "../graph/graph.h"

class BFSShortestPathFinder {
    Graph g;
    int* distTo;

public:
    BFSShortestPathFinder(Graph g, int v) : g(g) , distTo(new int[g.vertices()]) {
        for (int i = 0; i < g.vertices(); i++) {
            distTo[i] = INT_MAX;
        }
        distTo[v] = 0;

        pathsFrom(v);
    }

    void pathsFrom(int v) {
        std::queue<int> traversalOrder; // пазим непосетените върхове в опащка
        traversalOrder.push(v);

        while (!traversalOrder.empty()) {
            int current = traversalOrder.front();
            traversalOrder.pop();
            for (int w : g.adj(current)) {
                if (distTo[w] == INT_MAX) { // можем да го ползваме като индикация дали върха е бил посетен или не.
                    distTo[w] = distTo[current] + 1;
                    traversalOrder.push(w); // ако намерим непосетен връх го слагаме в опащката.
                }
            }
        }
    }

    int getMinDistTo(int w) {
        return distTo[w];
    }
};

