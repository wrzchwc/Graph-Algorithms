//
// Created by kubaw on 31.05.2021.
//

#include "Vertex.h"

Vertex::Vertex(int id,  Node *higher, Vertex *previous) : Node(id, higher) {
    this->previous = previous;
    next = nullptr;
    lower = nullptr;
}

Vertex::~Vertex() {
    previous = nullptr;
    next = nullptr;
    higher = nullptr;
    lower = nullptr;
}

Vertex *Vertex::getPrevious() const {
    return previous;
}

void Vertex::setPrevious(Vertex *vertex) {
    Vertex::previous = vertex;
}

Vertex *Vertex::getNext() const {
    return next;
}

void Vertex::setNext(Vertex *vertex) {
    Vertex::next = vertex;
}

Neighbour *Vertex::getLower() const {
    return lower;
}

void Vertex::setLower(Neighbour *neighbour) {
    Vertex::lower = neighbour;
}
