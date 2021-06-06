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
    //number of vertexes in the list
    int size;
    //number of edges in the list
    int edges;
    //initial vertex
    int initialVertex;
    //first vertex in the list
    Vertex *first;
    //last vertex in the list
    Vertex *last;

    //sets first vertex in the list
    void setFirst(Vertex *vertex);

    //sets last vertex in the list
    void setLast(Vertex *vertex);

    //removes all neighbours of given vertex
    static void removeNeighbours(Vertex *vertex);

public:
    //constructor
    AdjacencyList();

    //constructor using matrix
    explicit AdjacencyList(AdjacencyMatrix *matrix);

    AdjacencyList(const string &filepath, const string &delimiter, bool directed);

    //destructor
    virtual ~AdjacencyList();

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

    //returns size of the list
    [[nodiscard]] int getSize() const;

    //returns number of neighbours of specified vertex
    int getNumberOfNeighbours(int id);

    //returns weight of specified edge
    int getData(int vertexID, int neighbourID) const;

    //returns initial vertex of the graph
    [[nodiscard]] int getInitialVertex() const;

    //returns number of edges
    [[nodiscard]] int getEdges() const;

    //returns maximum weight of edge
    [[nodiscard]] int getMaxWeight() const;
};


#endif //PDBFK_ADJACENCYLIST_H
