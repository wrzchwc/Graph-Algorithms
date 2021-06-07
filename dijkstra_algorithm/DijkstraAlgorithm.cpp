//
// Created by kubaw on 02.06.2021.
//

#include "DijkstraAlgorithm.h"


DijkstraAlgorithm::DijkstraAlgorithm() = default;

DijkstraAlgorithm::~DijkstraAlgorithm() = default;

void DijkstraAlgorithm::solve(AdjacencyMatrix *matrix, int startVertex) {
    auto size = matrix->getSize();
    auto *solution = new GraphAlgorithmStructure[size];
    for (int i = 0; i < size; i++)
        solution[i] = {i, NULL, INT_MAX};
    solution[startVertex].d_or_key = 0;
    auto *queue = new PriorityQueue(solution, size);
    while (queue->getSize() > 0) {
        auto u = queue->getMin().id;
        auto number = matrix->getNumberOfNeighbours(u);
        auto *neighbours = new GraphAlgorithmStructure[number];
        for (int i = 0, j = 0; j < number; i++) {
            if (matrix->getData(u, i) != INT_MAX)
                neighbours[j++] = solution[i];
        }
        for (int i = 0; i < number; i++) {
            auto relaxation = solution[u].d_or_key + matrix->getData(u, neighbours[i].id);
            auto compare = solution[neighbours[i].id].d_or_key;
            if (compare > relaxation) {
                solution[neighbours[i].id].d_or_key = relaxation;
                solution[neighbours[i].id].p = u;
                queue->setData(neighbours[i].id, GraphAlgorithmStructure{neighbours[i].id, u, relaxation});
            }
        }
        queue->remove();
    }
    solutionSequence(solution, size, startVertex);
    delete queue;
    delete[] solution;
}

void DijkstraAlgorithm::solve(AdjacencyList *list, int startVertex) {
    auto size = list->getSize();
    auto *solution = new GraphAlgorithmStructure[size];
    for (int i = 0; i < size; i++)
        solution[i] = {i, NULL, INT_MAX};
    solution[startVertex].d_or_key = 0;
    auto *queue = new PriorityQueue(solution, size);
    while (queue->getSize() > 0) {
        auto u = queue->getMin().id;
        auto number = list->getNumberOfNeighbours(u);
        auto *neighbours = new GraphAlgorithmStructure[number];
        for (int i = 0, j = 0; j < number; i++) {
            if (list->getData(u, i) != INT_MAX)
                neighbours[j++] = solution[i];
        }
        for (int i = 0; i < number; i++) {
            auto relaxation = solution[u].d_or_key + list->getData(u, neighbours[i].id);
            auto compare = solution[neighbours[i].id].d_or_key;
            if (compare > relaxation) {
                solution[neighbours[i].id].d_or_key = relaxation;
                solution[neighbours[i].id].p = u;
                queue->setData(neighbours[i].id, GraphAlgorithmStructure{neighbours[i].id, u, relaxation});
            }
        }
        queue->remove();
    }
    solutionSequence(solution, size, startVertex);
    delete queue;
    delete[] solution;
}

void DijkstraAlgorithm::solutionSequence(GraphAlgorithmStructure *solution, int size, int startVertex) {
    cout << "Solution: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "vertex: " << i << " distance: " << solution[i].d_or_key << " | " << i << " ";
        if (i != startVertex) {
            auto previous = solution[i].p;
            while (previous != startVertex) {
                cout << previous << " ";
                previous = solution[previous].p;
            }
            cout << startVertex << " " << endl;
        } else
            cout << endl;
    }
}
