//
// Created by kubaw on 02.06.2021.
//

#ifndef PDBFK_DIJKSTRAALGORITHM_H
#define PDBFK_DIJKSTRAALGORITHM_H

#include "../adjacency_matrix/AdjacencyMatrix.h"
#include "../adjacency_list/AdjacencyList.h"
#include "../bellman-ford_algorithm/BellmanFordAlgorithm.h"

class DijkstraAlgorithm {
private:
    //co-functions for printing the solution
    static void solutionSequence(GraphAlgorithmStructure *array, int size, int startVertex);

    static bool inSequence(int id, const int *sequence, int size);

public:
    //constructor
    DijkstraAlgorithm();

    //destructor
    virtual ~DijkstraAlgorithm();

    //solver for adjacency matrix
    static void solve(AdjacencyMatrix *matrix, int startVertex);

    //solver for adjacency list
    static void solve(AdjacencyList *list, int startVertex);

    friend class BellmanFordAlgorithm;
};


#endif //PDBFK_DIJKSTRAALGORITHM_H
