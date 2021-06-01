//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_VERTEX_H
#define PDBFK_VERTEX_H

#include "Node.h"
#include "Neighbour.h"

class Vertex : public Node {
private:
    // preceding containsVertex
    Vertex *previous;
    // succeeding containsVertex
    Vertex *next;

    Neighbour *lower;
public:
    //constructor
    explicit Vertex(int id, Node *higher = nullptr, Vertex *previous = nullptr);

    //destructor
    ~Vertex() override;

    //returns pointer to the previous containsVertex
    [[nodiscard]] Vertex *getPrevious() const;

    //sets pointer to the previous containsVertex
    void setPrevious(Vertex *vertex);

    //returns pointer to the next containsVertex
    [[nodiscard]] Vertex *getNext() const;

    //sets pointer to the next containsVertex
    void setNext(Vertex *vertex);

    //returns firstly added neighbour of the vertex
    [[nodiscard]] Neighbour *getLower() const;

    //sets the first neighbour of the vertex
    void setLower(Neighbour *neighbour);
};


#endif //PDBFK_VERTEX_H
