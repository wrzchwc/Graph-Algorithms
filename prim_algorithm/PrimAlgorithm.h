//
// Created by kubaw on 03.06.2021.
//

#ifndef PDBFK_PRIMALGORITHM_H
#define PDBFK_PRIMALGORITHM_H

#include "../adjacency_matrix/AdjacencyMatrix.h"
#include "../adjacency_list/AdjacencyList.h"

class PrimAlgorithm {
public:
    //constructor
    PrimAlgorithm();

    //destructor
    virtual ~PrimAlgorithm();
    static void solve(AdjacencyMatrix *matrix, int startVertex);

    static void solve(AdjacencyList *list, int startVertex);
};


#endif //PDBFK_PRIMALGORITHM_H
