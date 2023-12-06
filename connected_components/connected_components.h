#include <iostream>
#include <stack>
#include "../graph/graph.h"

class ConnectedComponents {
    bool *visited;
    Graph g;
    int* cc; // масив указващ към кой свързан компонент принадлежи всеки връх

    void dfs(int v, int ccNum) {
        visited[v] = true;
        cc[v] = ccNum;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                dfs(w, ccNum);
            }
        }
    }

    void connectedComponents() {
        int ccNum = 0; // брой на свързаните компоненти
        // итерираме през всички непосетени върхове
        for (int i = 0; i < g.vertices(); i++) {
            if (!visited[i]) {
                // всички върхове достижими от i са в един свързан компонент
                dfs(i, ccNum);
                ccNum++;
            }
        }
    }

public:
    ConnectedComponents(Graph g) : g(g) , visited(new bool[g.vertices()]), cc(new int[g.vertices()]) {
        for (int i = 0; i < g.vertices(); i++) {
            cc[i] = i;
        }
        connectedComponents();
    }

    bool connected(int v, int w) {
        // ако два върха имат един и същ свързан компонент, има път м/у тях
        return cc[v] == cc[w];
    }

};