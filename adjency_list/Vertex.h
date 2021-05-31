//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_VERTEX_H
#define PDBFK_VERTEX_H

#include "Node.h"

class Vertex : public Node {
private:
    // preceding containsVertex
    Vertex *previous;
    // succeeding containsVertex
    Vertex *next;
public:
    //constructor
    explicit Vertex(int id);

    //destructor
    ~Vertex() override;

    //returns pointer to the previous containsVertex
    [[nodiscard]] Vertex * getPrevious() const;

    //sets pointer to the previous containsVertex
    void setPrevious(Vertex *previous);

    //returns pointer to the next containsVertex
    [[nodiscard]] Vertex * getNext() const;

    //sets pointer to the next containsVertex
    void setNext(Vertex *next);
};


#endif //PDBFK_VERTEX_H
