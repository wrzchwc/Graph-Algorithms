//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_ADJACENCYLIST_H
#define PDBFK_ADJACENCYLIST_H

#include <iostream>
#include "Node.h"
#include "Vertex.h"
#include "../adjacency_matrix/AdjacencyMatrix.h"

using namespace std;

class AdjacencyList {
private:
    int size;
    Vertex *first;
    Vertex *last;

    void setFirst(Vertex *vertex);

    void setLast(Vertex *vertex);

    static void removeNeighbours(Vertex *vertex);

public:
    //constructor
    AdjacencyList();

    //constructor using matrix
    explicit AdjacencyList(AdjacencyMatrix* matrix);

    AdjacencyList(const string &filepath, const string &delimiter, bool directed);

    //destructor
    virtual ~AdjacencyList();

    //returns pointer to containsVertex with specified id on the list, otherwise returns nullptr
    Vertex *containsVertex(int id);

    //adds new containsVertex
    void addVertex(int id);

    //prints all the elements on the list, length of the list, data pointed by first an last
    void show() const;

    //removes all the elements on the list
    void removeAll();

    //removes the last vertex
    void removeVertex();

    //adds lower of the specified vertex
    void addNeighbour(int vertexID, int neighbourID, int edgeWeight);
};


#endif //PDBFK_ADJACENCYLIST_H
