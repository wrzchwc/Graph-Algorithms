//
// Created by kubaw on 31.05.2021.
//

#include <iostream>
#include <string>
#include "AdjacencyList.h"
#include "../Main.h"


using namespace std;

AdjacencyList::AdjacencyList() {
    size = 0;
    initialVertex = 0;
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

void AdjacencyList::addNeighbour(int vertexID, int neighbourID, int edgeWeight) {
    auto *neighbour = new Neighbour(neighbourID, edgeWeight);
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

AdjacencyList::AdjacencyList(const string &filepath, const string &delimiter, bool directed) {
    fstream file;
    string tmp;
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;

    file.open(filepath, ios::in);
    getline(file, tmp);
    // parameters[0]-edges
    // parameters[1]-vertexes
    // parameters[2]-start
    // parameters[3]-end
    int *parameters = interpret(tmp, delimiter, 4);
    initialVertex = parameters[2];
    for (int i = 0; i < parameters[1]; i++)
        addVertex(i);
    while (getline(file, tmp)) {
        //edge[0] - start
        // edge[1] - end
        // edge [2] - weight
        int *edge = interpret(tmp, delimiter, 3);
        addNeighbour(edge[0], edge[1], edge[2]);
        if (!directed)
            addNeighbour(edge[1], edge[0], edge[2]);
    }

    file.close();

}

AdjacencyList::AdjacencyList(AdjacencyMatrix *matrix) {
    this->size = 0;
    first = nullptr;
    last = nullptr;
    initialVertex = matrix->getInitialVertex();
    for (int i = 0; i < matrix->getSize(); i++)
        addVertex(i);
    for (int row = 0; row < matrix->getSize(); row++)
        for (int column = 0; column < matrix->getSize(); column++)
            if (matrix->getData(row, column) != INT_MAX)
                addNeighbour(row, column, matrix->getData(row, column));
}

int AdjacencyList::getSize() const {
    return size;
}

int AdjacencyList::getNumberOfNeighbours(int id) {
    auto *tmp = first;
    while (tmp->getID() != id)
        tmp = tmp->getNext();
    auto *tmp2 = tmp->getLower();
    int neighbours = 0;
    while (tmp2 != nullptr) {
        tmp2 = tmp2->getLower();
        neighbours++;
    }
    return neighbours;
}

int AdjacencyList::getData(int vertexID, int neighbourID) {
    auto *tmp = first;
    while (tmp->getID() != vertexID)
        tmp = tmp->getNext();
    auto *tmp2 = tmp->getLower();
    while (tmp2 != nullptr) {
        if (tmp2->getID() == neighbourID)
            return tmp2->getEdgeWeight();
        tmp2 = tmp2->getLower();
    }
    return INT_MAX;
}

int AdjacencyList::getInitialVertex() const {
    return initialVertex;
}


