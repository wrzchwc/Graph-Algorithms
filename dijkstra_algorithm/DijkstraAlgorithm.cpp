//
// Created by kubaw on 02.06.2021.
//

#include "DijkstraAlgorithm.h"
#include "../priority_queue/PriorityQueue.h"


DijkstraAlgorithm::DijkstraAlgorithm() = default;

DijkstraAlgorithm::~DijkstraAlgorithm() = default;

void DijkstraAlgorithm::solve(AdjacencyMatrix *matrix, int startVertex) {
    auto size = matrix->getSize();
    auto *solution = new PrimDijkstra[size];
    for (int i = 0; i < size; i++)
        solution[i] = {i, NULL, INT_MAX};
    solution[startVertex].d_or_key = 0;
    auto *queue = new PriorityQueue(solution, size);
    while (queue->getSize() > 0) {
        auto u = queue->getMin().id;
        auto number = matrix->getNumberOfNeighbours(u);
        auto *neighbours = new PrimDijkstra[number];
        for (int i = 0, j = 0; i < matrix->getSize(); i++) {
            if (matrix->getData(u, i) != INT_MAX)
                neighbours[j++] = solution[i];
        }
        for (int i = 0; i < number; i++) {
            auto DU = solution[u].d_or_key;
            auto WUV = matrix->getData(u, neighbours[i].id);
            auto relaxation = DU + WUV;
            auto compare = solution[neighbours[i].id].d_or_key;
            auto ID = solution[neighbours[i].id].id;
            auto P = solution[neighbours[i].id].p;
            if (compare > relaxation) {
                solution[neighbours[i].id].d_or_key = relaxation;
                solution[neighbours[i].id].p = u;
                queue->setData(neighbours[i].id, PrimDijkstra(neighbours[i].id, u, relaxation));
            }
        }
        queue->remove();
    }
    for (int i = 0; i < size; i++) {
        cout << solution[i].id<<" " << solution[i].d_or_key << " " << solution[i].p << endl;
    }
}
