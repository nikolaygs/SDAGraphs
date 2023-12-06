#pragma once

#include <vector>

using namespace std;

// Базов API на граф
class Graph {
    int numVertices;
    bool directed; // флаг указващ дали графът е насочен или не
    vector<int> *adjList;

public:
    Graph(int V, bool directed) : numVertices(V),
    adjList(new vector<int>[V]), directed(directed) {}

    // добавя ребро м/у два върха
    void addEdge(int v, int w) {
        if (!directed) {
            adjList[w].push_back(v);
        }
        adjList[v].push_back(w);
    }

    // Връща списък с всички върхове съседни на v
    vector<int> adj(int v) {
        return adjList[v];
    }

    // Връща броят върхове в графа
    int vertices() {
        return numVertices;
    }
};