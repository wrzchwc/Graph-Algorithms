//
// Created by kubaw on 30.05.2021.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue() {
    queue = nullptr;
    size = 0;
}

void PriorityQueue::add(PrimDijkstra item) {
    //queue is empty
    if (queue == nullptr || size == 0) {
        size++;
        queue = new PrimDijkstra[size];
        queue[0] = item;
    }
        //queue is not empty
    else {
        size++;
        auto *tmp = new PrimDijkstra[size];
        for (int i = 0; i < size; i++) {
            tmp[i] = queue[i];
        }
        tmp[size - 1] = item;
        delete queue;
        queue = tmp;
        restore(size);
    }


}

void PriorityQueue::remove() {
    //queue is empty
    if (queue == nullptr || size == 0)
        cout << "Error! Queue is empty." << endl;
        //queue has more than one element
    else if (size > 1) {
        swap(queue[0], queue[size - 1]);
        size--;
        auto *tmp = new PrimDijkstra[size];
        for (int i = 0; i < size; i++)
            tmp[i] = queue[i];
        delete queue;
        queue = tmp;
    }
        //queue has only one element
    else {
        size--;
        delete queue;
        queue = nullptr;
    }
    restore(size);
}


void PriorityQueue::show() {
    int tmp = 0;
    for (int i = 0; i <= ceil(log2(size)); i++) {
        if (size - tmp > tmp) {
            for (int j = 0; j < pow(2, i); j++)
                cout << queue[tmp + j].id << " ";
        } else {
            for (int j = 0; j < size - tmp; j++)
                cout << queue[tmp + j].id << " ";
        }
        cout << endl;
        tmp += pow(2, i);
    }
}


void PriorityQueue::removeAll() {
    while (size > 0)
        remove();
}

PriorityQueue::~PriorityQueue() {
    removeAll();
    queue = nullptr;
}

PriorityQueue::PriorityQueue(PrimDijkstra *collection, int size) {
    queue = new PrimDijkstra[size];
    for (int i = 0; i < size; i++) {
        this->queue[i] = collection[i];
    }
    this->size = size;
    restore(size);
}

void PriorityQueue::restore(int size) {
    bool ready = false;
    while (!ready) {
        ready = true;
        for (int i = size - 1; i > 0; i--) {
            if (queue[i].d_or_key < queue[(i - 1) / 2].d_or_key) {
                swap(queue[i], queue[(i - 1) / 2]);
                ready = false;
            }
        }
    }
}

int PriorityQueue::getSize() const {
    return size;
}

PrimDijkstra PriorityQueue::getMin() {
    return queue[0];
}

void PriorityQueue::setData(int id, PrimDijkstra primDijkstra) {
    auto *tmp = queue;
    while (tmp->id != id)
        tmp++;
    *tmp = {primDijkstra.id, primDijkstra.p, primDijkstra.d_or_key};
}

bool PriorityQueue::contains(int id) {
    auto *tmp = queue;
    for (int i = 0; i < size; i++, tmp++)
        if (tmp->id == id)
            return true;
    return false;
}








