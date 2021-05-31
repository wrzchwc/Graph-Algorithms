//
// Created by kubaw on 31.05.2021.
//

#include "Vertex.h"

Vertex::Vertex(int id) : Node(id) {
    previous = nullptr;
    next = nullptr;
}

Vertex::~Vertex() {
    previous = nullptr;
    next = nullptr;
    higher = nullptr;
    lower = nullptr;
}

Vertex * Vertex::getPrevious() const {
    return previous;
}

void Vertex::setPrevious(Vertex *previous) {
    Vertex::previous = previous;
}

Vertex * Vertex::getNext() const {
    return next;
}

void Vertex::setNext(Vertex *next) {
    Vertex::next = next;
}
