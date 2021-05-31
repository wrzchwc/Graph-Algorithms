//
// Created by kubaw on 31.05.2021.
//

#include "Neighbour.h"

Neighbour::Neighbour(int id, int weight) : Node(id) {
    this->lower = nullptr;
    this->edgeWeight = weight;
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

void Neighbour::setEdgeWeight(int weight) {
    Neighbour::edgeWeight = weight;
}

Neighbour *Neighbour::getLower() const {
    return lower;
}

void Neighbour::setLower(Neighbour *lower) {
    Neighbour::lower = lower;
}






