#include <iostream>
#include <stack>
#include "../graph/graph.h"

using namespace std;

class DFSRecursiveTraversal {
    // списък с посетените върхове
    bool visited[];
public:
    void dfs(Graph g, int v) {
        // 1. Задаваме начален връх V от които започваме обхождането и го маркираме като посетен.
        visited[v] = true;
        // 2. Взимаме всичките съседни върхове на V
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // 3. За всеки непосетен връх съсед на V повтаряме стъпките.
                dfs(g, w);
            }
        }
    }
};

class DFSIterativeTraversal {
    bool visited[];
public:
    void dfs(Graph g, int v) {
        std::stack<int> recStack; // пазим непосетените върхове в стек
        recStack.push(v);
        visited[v] = true;

        while (!recStack.empty()) {
            int current = recStack.top();
            recStack.pop();

            for (int w : g.adj(current)) {
                if (!visited[w]) {
                    recStack.push(w); // ако намерим непосетен връх го слагаме в стека.
                    visited[w] = true;
                }
            }
        }
    }
};
