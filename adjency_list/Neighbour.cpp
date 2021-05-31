//
// Created by kubaw on 31.05.2021.
//

#include "Neighbour.h"

Neighbour::Neighbour(int id, int edgeWeight) : Node(id) {
    higher = nullptr;
    lower = nullptr;
    this->edgeWeight = edgeWeight;

}

Neighbour::~Neighbour() {
    higher = nullptr;
    lower = nullptr;
    id = 0;
    edgeWeight = 0;
}

int Neighbour::getEdgeWeight() const {
    return edgeWeight;
}

void Neighbour::setEdgeWeight(int edgeWeight) {
    Neighbour::edgeWeight = edgeWeight;
}
