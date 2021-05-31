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

    [[nodiscard]] Neighbour *getLower() const;

    void setLower(Neighbour *lower);

    [[nodiscard]] int getEdgeWeight() const;

    void setEdgeWeight(int edgeWeight);


};


#endif //PDBFK_NEIGHBOUR_H
