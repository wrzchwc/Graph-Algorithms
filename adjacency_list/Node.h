//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_NODE_H
#define PDBFK_NODE_H


class Node {
protected:
    //node added before this one
    Node *higher;

    //id of the node
    int id;
public:
    //constructor
    explicit Node(int id, Node *higher = nullptr);

    //destructor
    virtual ~Node();

    //returns node added before this one
    [[nodiscard]] Node *getHigher() const;

    //sets node added before this one
    void setHigher(Node *node);

    //gets id of the node
    [[nodiscard]] int getID() const;

};


#endif //PDBFK_NODE_H
