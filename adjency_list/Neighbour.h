//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_NEIGHBOUR_H
#define PDBFK_NEIGHBOUR_H

#include "Node.h"

class Neighbour : public Node {
private:
    //weight of edge between containsVertex and neighbour
    int edgeWeight;
public:
    //constructor
    Neighbour(int id, int edgeWeight);

    //destructor
    ~Neighbour() override;

    //returns weight of edge between neighbour and containsVertex
    [[nodiscard]] int getEdgeWeight() const;

    //sets weight of edge between neighbour and containsVertex
    void setEdgeWeight(int edgeWeight);
};


#endif //PDBFK_NEIGHBOUR_H
