//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_NEIGHBOUR_H
#define PDBFK_NEIGHBOUR_H

#include "Node.h"

class Neighbour : public Node {
private:
    //weight of edge between containsVertex and lower
    int edgeWeight;
    Neighbour *lower;
public:
    //constructor
    Neighbour(int id, int weight);

    //destructor
    ~Neighbour() override;

    //returns neighbour added after this one
    [[nodiscard]] Neighbour *getLower() const;

    //sets neighbour after this one
    void setLower(Neighbour *lower);

    //returns weight of the edge between vertex and this neighbour
    [[nodiscard]] int getEdgeWeight() const;

};


#endif //PDBFK_NEIGHBOUR_H
