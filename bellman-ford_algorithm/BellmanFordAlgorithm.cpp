#include "BellmanFordAlgorithm.h"
#include "../dijkstra_algorithm/DijkstraAlgorithm.h"

bool BellmanFordAlgorithm::solve(AdjacencyList *list, int initialVertex) {
    auto size = list->getSize();
    auto *solution = new GraphAlgorithmStructure[size];
    for (int i = 0; i < size; i++)
        solution[i] = {i, NULL, INT_MAX};
    solution[initialVertex].d_or_key = 0;
    auto solved = false;
    for (int i = 0; i < (size - 1) && !solved; i++) {
        solved = true;
        for (int u = 0; u < size; u++)
            for (int v = 0; v < size; v++)
                if (list->getData(u, v) != INT_MAX) {
                    auto du = solution[u].d_or_key, dv = solution[v].d_or_key, w = list->getData(u, v);
                    if (dv > (du == INT_MAX ? INT_MAX : du + w)) {
                        solution[v] = {v, u, du + w};
                        solved = false;
                    }
                }
    }
    for (int u = 0; u < size; u++)
        for (int v = 0; v < size; v++)
            if (list->getData(u, v) != INT_MAX) {
                auto du = solution[u].d_or_key, dv = solution[v].d_or_key, w = list->getData(u, v);
                if (dv > du + w)
                    return false;
            }
    auto shortest_path = 0;
    for (int i = 0; i < size; i++) {
        if (i != initialVertex)
            shortest_path += list->getData(solution[i].p, solution[i].id);
    }
    DijkstraAlgorithm::solutionSequence(solution, size, initialVertex);
    cout << "Shortest path: " << shortest_path << endl;
    delete[] solution;
    return true;
}

bool BellmanFordAlgorithm::solve(AdjacencyMatrix *matrix, int initialVertex) {
    auto size = matrix->getSize();
    auto *solution = new GraphAlgorithmStructure[size];
    for (int i = 0; i < size; i++)
        solution[i] = {i, NULL, INT_MAX};
    solution[initialVertex].d_or_key = 0;
    auto solved = false;
    for (int i = 0; i < (size - 1) && !solved; i++) {
        solved = true;
        for (int u = 0; u < size; u++)
            for (int v = 0; v < size; v++)
                if (matrix->getData(u, v) != INT_MAX) {
                    auto du = solution[u].d_or_key, dv = solution[v].d_or_key, w = matrix->getData(u, v);
                    if (dv > (du == INT_MAX ? INT_MAX : du + w)) {
                        solution[v] = {v, u, du + w};
                        solved = false;
                    }
                }
    }

    for (int u = 0; u < size; u++)
        for (int v = 0; v < size; v++)
            if (matrix->getData(u, v) != INT_MAX) {
                auto du = solution[u].d_or_key, dv = solution[v].d_or_key, w = matrix->getData(u, v);
                if (dv > du + w)
                    return false;
            }

    auto shortest_path = 0;
    for (int i = 0; i < size; i++)
        if (i != initialVertex)
            shortest_path += matrix->getData(solution[i].p, solution[i].id);
    DijkstraAlgorithm::solutionSequence(solution, size, initialVertex);
    cout << "Shortest path: " << shortest_path << endl;
    delete[] solution;
    return true;
}


BellmanFordAlgorithm::~BellmanFordAlgorithm() = default;

BellmanFordAlgorithm::BellmanFordAlgorithm() = default;
