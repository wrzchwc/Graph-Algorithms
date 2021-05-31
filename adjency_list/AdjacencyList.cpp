//
// Created by kubaw on 31.05.2021.
//

#include <iostream>
#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList() {
    size = 0;
    first = nullptr;
    last = nullptr;
}

void AdjacencyList::addVertex(int id) {
    if (!(first && last)) {
        auto *vertex = new Vertex(id);
        setFirst(vertex);
        setLast(vertex);
    } else {
        auto *vertex = new Vertex(id, nullptr, last);
        last->setNext(vertex);
        setLast(vertex);
    }
    size++;
}

void AdjacencyList::setFirst(Vertex *vertex) {
    AdjacencyList::first = vertex;
}

void AdjacencyList::setLast(Vertex *vertex) {
    AdjacencyList::last = vertex;
}

void AdjacencyList::show() const {
    auto *tmp = first;
    while (tmp) {
        auto *neighbour = tmp->getLower();
        cout << "[V:" << tmp->getID() << "]";
        while (neighbour) {
            cout << "-[" << neighbour->getID() << ":" << neighbour->getEdgeWeight() << "]";
            neighbour = neighbour->getLower();
        }
        cout << endl;
        tmp = tmp->getNext();
    }
    cout << endl;
}

void AdjacencyList::removeAll() {
    while (size > 0)
        removeVertex();
}

void AdjacencyList::removeVertex() {
    //empty list
    if (!(first && last)) {
        cout << "Error! Adjacency list empty." << endl;
        return;
    }
        //1 containsVertex on the list
    else if (first == last) {
        if (first->getLower())
            removeNeighbours(first);
        first->setLower(nullptr);
        delete first;
        setFirst(nullptr);
        setLast(nullptr);
    }
        //more than 1 vertex one the list
    else {
        auto *penultimate = last->getPrevious();
        penultimate->setNext(nullptr);
        last->setPrevious(nullptr);
        if (last->getLower())
            removeNeighbours(last);
        last->setLower(nullptr);
        delete last;
        setLast(penultimate);
    }
    size--;
}

void AdjacencyList::removeNeighbours(Vertex *vertex) {
    auto *tmp = vertex->getLower();
    auto *pmt = tmp;
    while (tmp) {
        tmp = tmp->getLower();
        delete pmt;
        pmt = tmp;
    }
}

Vertex *AdjacencyList::containsVertex(int id) {
    auto *tmp = first;
    while (tmp != nullptr) {
        if (tmp->getID() == id)
            return tmp;
        tmp = tmp->getNext();
    }
    return nullptr;
}

AdjacencyList::~AdjacencyList() {
    removeAll();
}

void AdjacencyList::addNeighbour(int vertexID, int id, int edgeWeight) {
    auto *neighbour = new Neighbour(id, edgeWeight);
    auto *tmp = first;
    while (tmp->getID() != vertexID)
        tmp = tmp->getNext();
    if (tmp->getLower()) {
        auto *tmp2 = tmp->getLower();
        while (tmp2->getLower())
            tmp2 = tmp2->getLower();
        tmp2->setLower(neighbour);
        neighbour->setHigher(tmp2);
    } else {
        tmp->setLower(neighbour);
        neighbour->setHigher(tmp);
    }
}


