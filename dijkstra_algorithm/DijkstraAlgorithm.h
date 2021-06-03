//
// Created by kubaw on 02.06.2021.
//

#ifndef PDBFK_DIJKSTRAALGORITHM_H
#define PDBFK_DIJKSTRAALGORITHM_H
#include "../adjacency_matrix/AdjacencyMatrix.h"
#include "../adjacency_list/AdjacencyList.h"

class DijkstraAlgorithm {
public:
    //constructor
    DijkstraAlgorithm();
    //destructor
    virtual ~DijkstraAlgorithm();
    static void solve(AdjacencyMatrix *matrix, int startVertex);
};


#endif //PDBFK_DIJKSTRAALGORITHM_H
