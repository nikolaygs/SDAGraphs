cmake_minimum_required(VERSION 3.26)
project(SDA_Graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDA_Graph main.cpp
        dfs/dfs.h
        graph/graph.h
        bfs/bfs.h
        path/path.h
        shortest_path/shortest_path.h
        connected_components/connected_components.h
        undirect_cycle/undirect_cycle.h
        direct_cycle/direct_cycle.h
        topological_sort/topological_sort.h
)
