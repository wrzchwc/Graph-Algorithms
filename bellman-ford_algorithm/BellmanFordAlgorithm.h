//
// Created by kubaw on 05.06.2021.
//

#ifndef PDBFK_BELLMANFORDALGORITHM_H
#define PDBFK_BELLMANFORDALGORITHM_H

#include "../adjacency_list/AdjacencyList.h"
#include "../adjacency_matrix/AdjacencyMatrix.h"

class BellmanFordAlgorithm {
private:
    static void solutionSequence(GraphAlgorithmStructure *array, int size, int initialVertex);
public:
    //constructor
    BellmanFordAlgorithm();

    //destructor
    virtual ~BellmanFordAlgorithm();

    //solver for adjacency list
    static bool solve(AdjacencyList *list, int initialVertex);

    //solver for adjacency matrix
    static bool solve(AdjacencyMatrix *matrix, int initialVertex);
};


#endif //PDBFK_BELLMANFORDALGORITHM_H
