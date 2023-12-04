#include <iostream>
#include "dfs/dfs.h"
#include "bfs/bfs.h"
#include "path/path.h"
#include "shortest_path/shortest_path.h"
#include "connected_components/connected_components.h"
#include "direct_cycle/direct_cycle.h"
#include "undirect_cycle/undirect_cycle.h"

using namespace std;


int main() {

    // Директен граф с цикъл
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

//    DFSRecursiveTraversal dfsRec  = DFSRecursiveTraversal();
//    dfsRec.dfs(graph, 0);
//
//    DFSIterativeTraversal dfsIter  = DFSIterativeTraversal();
//    dfsIter.dfs(graph, 0);

//    BFSTraversal bfsTraversal = BFSTraversal();
//    bfsTraversal.bfs(graph, 0);

//    cout << "Find paths with DFS" << "\n";
//    DFSPathFinder dfsPathFinder = DFSPathFinder(graph, 0);
//    dfsPathFinder.printPathTo(5);
//    dfsPathFinder.printPathTo(1);
//    dfsPathFinder.printPathTo(2);
//
//    cout << "Find distances with BFS" << "\n";
//    BFSShortestPathFinder shortestPath = BFSShortestPathFinder(graph, 0);
//    cout << shortestPath.getMinDistTo(5) << "\n";
//    cout << shortestPath.getMinDistTo(6) << "\n";
//    cout << shortestPath.getMinDistTo(4) << "\n";
//
//     cout << "Connected components" << "\n";
//     ConnectedComponents cc = ConnectedComponents(graph);
//     cout <<  cc.connected(0, 6) << "\n";
//     cout <<  cc.connected(5, 6) << "\n";

//    cout << "Cycle in Undirected graph " << "\n";
//    CycleDetectorUndirectGraph undirectCycleDetector = CycleDetectorUndirectGraph(graph);
//    cout << undirectCycleDetector.hasCycle();

    cout << "Cycle in Directed graph " << "\n";
    CycleDetectorDirectGraph directCycleDetector = CycleDetectorDirectGraph(graph);
    cout << directCycleDetector.hasCycle() << "\n";

    return 0;
}