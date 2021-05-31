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
    auto *vertex = new Vertex(id);
    if (!(first && last)) {
        setFirst(vertex);
        setLast(vertex);
    } else {
        last->setNext(vertex);
        vertex->setPrevious(last);
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
        cout << tmp->getID() << " ";
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
        setFirst(nullptr);
        setLast(nullptr);
        //todo: removing neighbours
        first->setLower(nullptr);
        delete first;
    }
        //more than 1 containsVertex one the list
    else {
        auto *tmp = last->getPrevious();
        tmp->setNext(nullptr);
        last->setPrevious(nullptr);
        //todo: removing neighbours
        last->setLower(nullptr);
        delete last;
        setLast(tmp);
    }
    size--;
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