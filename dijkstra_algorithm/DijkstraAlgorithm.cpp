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
    cout << "Solution: " << endl;
    auto shortest_path = 0;
    for (int i = 0; i < size; i++) {
        cout << "vertex: "<<solution[i].id << " distance: " << solution[i].d_or_key << endl;
        if (i != startVertex)
            shortest_path += matrix->getData(solution[i].p, solution[i].id);
    }
    solutionSequence(solution, size, startVertex);
    cout << "Shortest path: " << shortest_path << endl;
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
    cout << "Solution: " << endl;
    auto shortest_path = 0;
    for (int i = 0; i < size; i++) {
        cout << "vertex: "<<solution[i].id << " distance: " << solution[i].d_or_key << endl;
        if (i != startVertex)
            shortest_path += list->getData(solution[i].p, solution[i].id);
    }
    solutionSequence(solution, size, startVertex);
    cout << "Shortest path: " << shortest_path << endl;
    delete queue;
    delete[] solution;
}

bool DijkstraAlgorithm::inSequence(int id, const int *sequence, int size) {
    for (int i = 0; i < size; i++)
        if (sequence[i] == id)
            return true;
    return false;
}

void DijkstraAlgorithm::solutionSequence(GraphAlgorithmStructure *array, int size, int startVertex) {
    auto *sequence = new int[size];
    for (int i = 0; i < size; i++)
        sequence[i] = INT_MAX;
    auto max_d = 0, max_id = 0;
    for (int i = 0; i < size; i++) {
        if (i != startVertex && array[i].d_or_key > max_d) {
            max_id = i;
            max_d = array[i].d_or_key;
        }
    }
    sequence[0] = max_id;
    for (int i = 1; i < size;) {
        auto previous = array[max_id].p;
        for (int j = 0; j < size; j++)
            if (j != startVertex)
                if (!inSequence(j, sequence, size) && array[j].p == previous)
                    sequence[i++] = j;
        sequence[i++] = previous;
        max_id = previous;
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << sequence[i] << " ";
    }
    cout << endl;
}
