cmake_minimum_required(VERSION 3.19)
project(PDBFK)

set(CMAKE_CXX_STANDARD 20)

add_executable(PDBFK Main.cpp priority_queue/PriorityQueue.cpp priority_queue/PriorityQueue.h adjency_matrix/AdjacencyMatrix.cpp adjency_matrix/AdjacencyMatrix.h adjency_list/Node.cpp adjency_list/Node.h adjency_list/Vertex.cpp adjency_list/Vertex.h adjency_list/Neighbour.cpp adjency_list/Neighbour.h adjency_list/AdjacencyList.cpp adjency_list/AdjacencyList.h)
add_executable(test test.cpp priority_queue/PriorityQueue.h priority_queue/PriorityQueue.cpp)