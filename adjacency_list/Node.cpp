//
// Created by kubaw on 31.05.2021.
//

#include "Node.h"

Node::Node(int id, Node *higher) {
    this->higher = higher;
    this->id = id;
}

Node *Node::getHigher() const {
    return higher;
}

void Node::setHigher(Node *node) {
    Node::higher = node;
}

int Node::getID() const {
    return id;
}

Node::~Node() {
    higher = nullptr;
    id = 0;
}
