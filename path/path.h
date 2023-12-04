#include <iostream>
#include <stack>
#include "../graph/graph.h"

class DFSPathFinder {
    bool *visited;
    Graph g;
    int* pathTo; // за всеки връх пазим върха от които сме стигнали до него

    void dfs(int v) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // запазваме че сме стигнали до връх w от връх v
                pathTo[w] = v;
                dfs(w);
            }
        }
    }

public:
    DFSPathFinder(Graph g, int v) : g(g) , visited(new bool[g.vertices()]), pathTo(new int[g.vertices()]) {
        for (int i = 0; i < g.vertices(); i++) {
            pathTo[i] = i;
        }

        dfs(v);
    }

    void printPathTo(int w) {
        // ще получим пътя в обратен ред, затова ще ползваме стек
        stack<int> path;
        while (true) {
            path.push(w);
            w = pathTo[w];
            if (w == pathTo[w]) {
                path.push(w);
                break;
            }
        }

        // печатим пътя до съответния връх
        while(!path.empty()) {
            cout << path.top();
            path.pop();
            if (path.size() > 0) {
                cout << "->";
            }
        }
        cout << "\n";
    }
};

