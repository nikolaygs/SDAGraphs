#include <iostream>
#include "dfs/dfs.h"
#include "bfs/bfs.h"
#include "path/path.h"
#include "shortest_path/shortest_path.h"
#include "connected_components/connected_components.h"
#include "direct_cycle/direct_cycle.h"
#include "undirect_cycle/undirect_cycle.h"
#include "topological_sort/topological_sort.h"

using namespace std;

Graph getSampleUndirectedGraph() {
    Graph graph(7, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    graph.addEdge(5, 6);
    return graph;
}

Graph getDisconnectedUndirectedGraph() {
    Graph graph(7, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(5, 6);
    return graph;
}

Graph getTreeUndirectedGraph() {
    Graph graph(10, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 8);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 6);
    graph.addEdge(1, 7);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(8, 9);
    return graph;
}

Graph getSampleDAG() {
    // Директен граф без цикъл
    Graph graph(8, true);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(7, 6);

    return graph;
}

Graph getDirectedGraphWithCycle() {
    Graph graph(8, true);
    graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(2, 1);
    graph.addEdge(3, 2);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 7);
    graph.addEdge(6, 4);
    graph.addEdge(7, 6);
    return graph;
}

int main() {
    DFSRecursiveTraversal dfsRec  = DFSRecursiveTraversal(getTreeUndirectedGraph());
    dfsRec.dfs(0);
    cout << "\n";

    DFSIterativeTraversal dfsIter  = DFSIterativeTraversal(getTreeUndirectedGraph());
    dfsIter.dfs(0);
    cout << "\n";

    BFSTraversal bfsTraversal = BFSTraversal(getTreeUndirectedGraph());
    bfsTraversal.bfs(0);
    cout << "\n";

    cout << "Find paths with DFS" << "\n";
    DFSPathFinder dfsPathFinder = DFSPathFinder(getSampleUndirectedGraph(), 0);
    dfsPathFinder.printPathTo(5);
    dfsPathFinder.printPathTo(1);
    dfsPathFinder.printPathTo(2);
    cout << "\n";

    cout << "Find distances with BFS" << "\n";
    BFSShortestPathFinder shortestPath = BFSShortestPathFinder(getSampleUndirectedGraph(), 0);
    cout << shortestPath.getMinDistTo(5) << "\n";
    cout << shortestPath.getMinDistTo(6) << "\n";
    cout << shortestPath.getMinDistTo(4) << "\n";
    cout << "\n";

     cout << "Connected components" << "\n";
     ConnectedComponents cc = ConnectedComponents(getSampleUndirectedGraph());
     cout <<  cc.connected(0, 6) << "\n";
     cout <<  cc.connected(5, 6) << "\n";

    cout << "Cycle in Undirected graph " << "\n";
    CycleDetectorUndirectGraph undirectCycleDetector = CycleDetectorUndirectGraph(getSampleUndirectedGraph());
    cout << undirectCycleDetector.hasCycle() << "\n";

    cout << "Cycle in Directed graph " << "\n";
    CycleDetectorDirectGraph directCycleDetector = CycleDetectorDirectGraph(getSampleDAG());
    cout << directCycleDetector.hasCycle() << "\n";

    cout << "Topological sort" << "\n";
    TopologicalSort topoSort = TopologicalSort(getSampleDAG());
    topoSort.printOrder();

    return 0;
}