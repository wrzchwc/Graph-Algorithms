//
// Created by kubaw on 31.05.2021.
//

#include "Node.h"

Node::Node(int id) {
    higher = nullptr;
    lower = nullptr;
    this->id = id;
}

Node *Node::getHigher() const {
    return higher;
}

void Node::setHigher(Node *higher) {
    Node::higher = higher;
}

Node *Node::getLower() const {
    return lower;
}

int Node::getID() const {
    return id;
}

void Node::setID(int id) {
    Node::id = id;
}

Node::~Node() {
    higher = nullptr;
    lower = nullptr;
    id = 0;
}

void Node::setLower(Node *lower) {
    Node::lower = lower;
}
