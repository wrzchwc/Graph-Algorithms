//
// Created by kubaw on 30.05.2021.
//

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct PrimDijkstra {
    int id;
    int p;
    int d_or_key;
};

class PriorityQueue {
private:
    //dynamic dynamic array storing id added to the queue
    PrimDijkstra *queue;
    //size of the binary queue
    int size;

    //restores priority queue features to the structure
    void restore(int size);

public:
    //constructor
    PriorityQueue();

    PriorityQueue(PrimDijkstra *collection, int size);

    //destructor
    virtual ~PriorityQueue();

    //adds specified id to queue
    void add(PrimDijkstra item);

    //removes the root of the queue
    void remove();

    //removes all id in the queue
    void removeAll();

    //returns true if queue containsVertex specified id, otherwise returns false
    bool contains(int id);

    //prints content of the queue
    void show();

};


#endif //PRIORITY_QUEUE_H
