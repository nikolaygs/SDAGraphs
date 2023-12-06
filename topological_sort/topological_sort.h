#include <iostream>
#include <stack>
#include "../graph/graph.h"

class TopologicalSort {
    bool *visited;
    Graph g;
    stack<int> topoOrder;

    void dfs(int v) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // запазваме че сме стигнали до връх w от връх v
                dfs(w);
            }
        }

        // пазим върховете в обратния ред на посещение
        topoOrder.push(v);
    }

public:
    TopologicalSort(Graph g) : g(g) , visited(new bool[g.vertices()]), topoOrder(stack<int>()) {
        for (int i = 0; i < g.vertices(); i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    void printOrder() {
        // печатим пътя до съответния връх
        while(!topoOrder.empty()) {
            cout << topoOrder.top();
            topoOrder.pop();
            if (topoOrder.size() > 0) {
                cout << "->";
            }
        }
        cout << "\n";
    }
};