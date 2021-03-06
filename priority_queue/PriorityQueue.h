//
// Created by kubaw on 30.05.2021.
//

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct GraphAlgorithmStructure {
    int id;
    int p;
    int d_or_key;
};

class PriorityQueue {
private:
    //dynamic dynamic array storing id added to the queue
    GraphAlgorithmStructure *queue;
    //size of the binary queue
    int size;

    //restores priority queue features to the structure
    void restore(int size);

public:
    //constructor
    PriorityQueue();

    PriorityQueue(GraphAlgorithmStructure *collection, int size);

    //destructor
    virtual ~PriorityQueue();

    //adds specified id to queue
    void add(GraphAlgorithmStructure item);

    //removes the root of the queue
    void remove();

    //removes all id in the queue
    void removeAll();

    //prints content of the queue
    void show();

    //returns size fo the queue
    [[nodiscard]] int getSize() const;

    //returns element with minimum d or minimum key
    GraphAlgorithmStructure getMin();

    //sets specified element in the queue
    void setData(int id, GraphAlgorithmStructure primDijkstra);

    //returns true if vertex with given ID is in the queue
    bool contains(int id);

};


#endif //PRIORITY_QUEUE_H
