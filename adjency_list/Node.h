//
// Created by kubaw on 31.05.2021.
//

#ifndef PDBFK_NODE_H
#define PDBFK_NODE_H


class Node {
protected:
    //node added before this one
    Node *higher;
    //node added after this one
    Node *lower;
    //id of the node
    int id;
public:
    //constructor
    explicit Node(int id);

    //destructor
    virtual ~Node();

    //returns node added before this one
    [[nodiscard]] Node *getHigher() const;

    //sets node added before this one
    void setHigher(Node *higher);

    //returns node added after this one
    [[nodiscard]] Node *getLower() const;

    //sets node added after this one
    void setLower(Node *lower);

    //gets id of the node
    [[nodiscard]] int getID() const;

    //sets id of the node
    void setID(int id);
};


#endif //PDBFK_NODE_H
