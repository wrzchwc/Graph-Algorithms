//
// Created by kubaw on 06.06.2021.
//

#include "KruskalAlgorithm.h"

void KruskalAlgorithm::solve(AdjacencyMatrix *matrix) {
    auto size = matrix->getSize();
    auto number = matrix->getEdges();
    auto vertexes = makeSet(size);
    auto edges = sort(getEdges(matrix), number, matrix->getMaxWeight());
    auto *solution = new Edge[size - 1];
    auto j = 0;
    for (int i = 0; j < size - 1; i++) {
        auto u = vertexes[edges[i].initialVertex];
        auto v = vertexes[edges[i].finalVertex];
        if (findSet(vertexes, u) != findSet(vertexes, v)) {
            unify(vertexes, u.id, v.id);
            solution[j++] = {u.id, v.id, matrix->getData(u.id, v.id)};
        }
    }
    matrixSolution(matrix, solution, size - 1);
    delete[] edges;
    delete[] vertexes;
    delete[] solution;
}

Kruskal *KruskalAlgorithm::makeSet(int size) {
    auto *set = new Kruskal[size];
    for (int i = 0; i < size; i++)
        set[i] = {i, i, 0};
    return set;
}

Edge *KruskalAlgorithm::getEdges(AdjacencyMatrix *matrix) {
    auto size = matrix->getSize();
    auto edges = new Edge[matrix->getEdges()];
    int i = 0;
    for (int j = 0; j < size - 1; j++)
        for (int k = j + 1; k < size; k++) {
            auto tmp = matrix->getData(j, k);
            if (tmp != INT_MAX)
                edges[i++] = {j, k, tmp};
        }
    return edges;
}

Edge *KruskalAlgorithm::sort(const Edge *array, int size, int extreme) {
    auto *countArray = new int[extreme + 1];
    auto *tmp = new Edge[size];
    for (int i = 0; i < extreme + 1; i++)
        countArray[i] = 0;

    for (int i = 0; i < size; i++)
        countArray[array[i].weight]++;

    for (int i = 1; i < extreme + 1; i++)
        countArray[i] += countArray[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        tmp[countArray[array[i].weight] - 1] = array[i];
        countArray[array[i].weight]--;
    }
    delete[] array;
    delete[] countArray;
    return tmp;
}

int KruskalAlgorithm::findSet(Kruskal *vertexes, Kruskal vertex) {
    auto set = vertexes;
    auto tmp = vertex;
    while (tmp.parent != tmp.id)
        tmp = set[tmp.parent];
    if (vertex.id != vertex.parent)
        vertexes[vertex.id].parent = tmp.parent;
    return tmp.parent;
}

void KruskalAlgorithm::unify(Kruskal *vertexes, int u, int v) {
    auto a = findSet(vertexes, vertexes[u]);
    auto b = findSet(vertexes, vertexes[v]);
    vertexes[a].rank < vertexes[b].rank ? vertexes[b].parent = a : vertexes[a].parent = b;
    if (vertexes[a].rank == vertexes[b].rank)
        vertexes[a].rank++;
}

void KruskalAlgorithm::matrixSolution(AdjacencyMatrix *matrix, Edge *solution, int size) {
    auto mst = 0;
    cout << "Solution: " << endl;
    for (int i = 0; i < size; i++) {
        cout << solution[i].initialVertex << "-" << solution[i].finalVertex << ":" << solution[i].weight << endl;
        mst += matrix->getData(solution[i].initialVertex, solution[i].finalVertex);
    }
    cout << "Minimum spanning tree: " << mst << endl;
}

void KruskalAlgorithm::solve(AdjacencyList *list) {
    auto size = list->getSize();
    auto number = list->getEdges();
    auto vertexes = makeSet(size);
    auto edges = sort(getEdges(list), number, list->getMaxWeight());
    auto *solution = new Edge[size - 1];
    auto j = 0;
    for (int i = 0; j < size - 1; i++) {
        auto u=vertexes[edges[i].initialVertex];
        auto v=vertexes[edges[i].finalVertex];
        if(findSet(vertexes,u)!= findSet(vertexes,v)){
            unify(vertexes,u.id, v.id);
            solution[j++]={u.id,v.id,list->getData(u.id, v.id)};
        }
    }
    listSolution(list,solution,size-1);
    delete [] edges;
    delete[] vertexes;
    delete[] solution;
}

Edge *KruskalAlgorithm::getEdges(AdjacencyList *list) {
    auto size = list->getSize();
    auto edges = new Edge[list->getEdges()];
    auto i = 0;
    for (int j = 0; j < size - 1; j++)
        for (int k = j + 1; k < size; k++) {
            auto tmp = list->getData(j, k);
            if (tmp != INT_MAX)
                edges[i++] = {j, k, tmp};
        }
    return edges;
}

void KruskalAlgorithm::listSolution(AdjacencyList *list, Edge *solution, int size) {
    auto mst=0;
    cout<<"Solution: "<<endl;
    for (int i = 0; i < size; i++) {
        cout << solution[i].initialVertex << "-" << solution[i].finalVertex << ":" << solution[i].weight << endl;
        mst += list->getData(solution[i].initialVertex, solution[i].finalVertex);
    }
    cout << "Minimum spanning tree: " << mst << endl;
}


