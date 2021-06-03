//
// Created by kubaw on 03.06.2021.
//

#include "PrimAlgorithm.h"
#include "../priority_queue/PriorityQueue.h"

PrimAlgorithm::PrimAlgorithm() = default;

PrimAlgorithm::~PrimAlgorithm() = default;

void PrimAlgorithm::solve(AdjacencyMatrix *matrix, int startVertex) {
    auto size = matrix->getSize();
    auto *solution = new PrimDijkstra[size];
    for (int i = 0; i < size; i++) {
        solution[i].id = i;
        solution[i].d_or_key = INT_MAX;
    }
    solution[startVertex].d_or_key = 0;
    solution[startVertex].p = NULL;
    auto *queue = new PriorityQueue(solution, size);
    while (queue->getSize() > 0) {
        auto u = queue->getMin().id;
        auto number = matrix->getNumberOfNeighbours(u);
        auto *neighbours = new PrimDijkstra[number];
        for (int i = 0, j = 0; j < number; i++)
            if (matrix->getData(u, i) != INT_MAX)
                neighbours[j++] = solution[i];
        for (int i = 0; i < number; i++) {
            auto v = neighbours[i];
            auto w = matrix->getData(u, v.id);
            if (queue->contains(v.id) && w < v.d_or_key) {
                solution[v.id].d_or_key=w;
                solution[v.id].p=u;
                queue->setData(v.id,PrimDijkstra{v.id,u,w});
            }
        }
        queue->remove();
    }
    cout << "Solution: " << endl;
    auto mst = 0;
    for (int i = 0; i < size; i++) {
        if (i != startVertex) {
            cout << solution[i].p << "-" << solution[i].id << ":" << matrix->getData(solution[i].p, solution[i].id)
                 << endl;
            mst += matrix->getData(solution[i].p, solution[i].id);
        }
    }
    cout << "Minimum spanning tree: " << mst << endl;
}

void PrimAlgorithm::solve(AdjacencyList *list, int startVertex) {
    auto size=list->getSize();
    auto*solution=new PrimDijkstra[size];
    for(int i=0;i<size;i++){
        solution[i].id=i;
        solution[i].d_or_key=INT_MAX;
    }
    solution[startVertex].d_or_key=0;
    solution[startVertex].p=NULL;
    auto *queue=new PriorityQueue(solution,size);
    while(queue->getSize()>0){
        auto u=queue->getMin().id;
        auto number=list->getNumberOfNeighbours(u);
        auto *neighbours=new PrimDijkstra[number];
        for(int i=0,j=0;j<number;i++)
            if(list->getData(u,i)!=INT_MAX)
                neighbours[j++]=solution[i];
        for(int i=0;i<number;i++){
            auto v=neighbours[i];
            auto w=list->getData(u,v.id);
            if(queue->contains(v.id)&&w<v.d_or_key){
                solution[v.id].d_or_key=w;
                solution[v.id].p=u;
                queue->setData(v.id,PrimDijkstra{v.id,u,w});
            }
        }
        queue->remove();
    }
    cout << "Solution: " << endl;
    auto mst = 0;
    for (int i = 0; i < size; i++) {
        if (i != startVertex) {
            cout << solution[i].p << "-" << solution[i].id << ":" << list->getData(solution[i].p, solution[i].id)
                 << endl;
            mst += list->getData(solution[i].p, solution[i].id);
        }
    }
    cout << "Minimum spanning tree: " << mst << endl;
}
