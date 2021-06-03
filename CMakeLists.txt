cmake_minimum_required(VERSION 3.19)
project(PDBFK)

set(CMAKE_CXX_STANDARD 20)

add_executable(PDBFK Main.cpp priority_queue/PriorityQueue.cpp priority_queue/PriorityQueue.h adjacency_matrix/AdjacencyMatrix.cpp adjacency_matrix/AdjacencyMatrix.h adjacency_list/Node.cpp adjacency_list/Node.h adjacency_list/Vertex.cpp adjacency_list/Vertex.h adjacency_list/Neighbour.cpp adjacency_list/Neighbour.h adjacency_list/AdjacencyList.cpp adjacency_list/AdjacencyList.h Main.h dijkstra_algorithm/DijkstraAlgorithm.cpp dijkstra_algorithm/DijkstraAlgorithm.h)
add_executable(test test.cpp priority_queue/PriorityQueue.h priority_queue/PriorityQueue.cpp )