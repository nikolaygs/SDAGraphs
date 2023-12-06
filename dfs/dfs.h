#include <iostream>
#include <stack>
#include "../graph/graph.h"

using namespace std;

class DFSRecursiveTraversal {
    Graph g;
    bool *visited; // списък с посетените върхове
public:
    DFSRecursiveTraversal(Graph g) : g(g), visited(new bool[g.vertices()]) {}

    void dfs(int v) {
        // 0. Извеждаме елемента който обработваме
        cout << v << " ";
        // 1. Задаваме начален връх V от който започваме обхождането и го маркираме като посетен.
        visited[v] = true;
        // 2. Взимаме всичките съседни върхове на V
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // 3. За всеки непосетен връх съсед на V повтаряме стъпките.
                dfs(w);
            }
        }
    }
};

class DFSIterativeTraversal {
    Graph g;
    bool *visited; // списък с посетените върхове
public:
    DFSIterativeTraversal(Graph g) : g(g), visited(new bool[g.vertices()]) {}

    void dfs(int v) {
        std::stack<int> recStack; // пазим непосетените върхове в стек
        recStack.push(v);
        while (!recStack.empty()) {
            v = recStack.top();
            recStack.pop();
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
                for (int w : g.adj(v)) {
                    if (!visited[w]) {
                        recStack.push(w); // ако намерим непосетен връх го слагаме в стека.
                    }
                }
            }
        }
    }
};
