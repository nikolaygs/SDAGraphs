#pragma once

#include <vector>

using namespace std;

// Базов API на граф
class Graph {
    int numVertices;
    vector<vector<int>> adjList;

    bool directed; // флаг указващ дали графът е насочен или не

public:
    Graph(int V, bool directed) : numVertices(V), adjList(V), directed(directed) {}

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