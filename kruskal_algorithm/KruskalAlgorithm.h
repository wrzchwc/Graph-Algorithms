//
// Created by kubaw on 06.06.2021.
//

#ifndef PDBFK_KRUSKALALGORITHM_H
#define PDBFK_KRUSKALALGORITHM_H

#include "../adjacency_list/AdjacencyList.h"
#include "../adjacency_matrix/AdjacencyMatrix.h"

//edge representation
struct Edge {
    int initialVertex;
    int finalVertex;
    int weight;
};
//vertex representation
struct Kruskal {
    int id;
    int parent;
    int rank;
};

class KruskalAlgorithm {
private:
    //generates set of groups with only element in each
    static Kruskal *makeSet(int size);

    //returns set in which given vertex is
    static int findSet(Kruskal *vertexes, Kruskal vertex);

    //connects two groups
    static void unify(Kruskal *vertexes, int u, int v);

    //gets edges from adjacency matrix
    static Edge *getEdges(AdjacencyMatrix *matrix);

    //gets edges from adjacency list
    static Edge *getEdges(AdjacencyList *list);

    //sorts edges using counting-sort interface
    static Edge *sort(const Edge *array, int size, int extreme);

    //prints solution for adjacency matrix
    static void matrixSolution(AdjacencyMatrix *matrix, Edge *solution, int size);

    //prints solution for adjacency list
    static void listSolution(AdjacencyList *list, Edge *solution, int size);

public:
    //solver for adjacency matrix
    static void solve(AdjacencyMatrix *matrix);

    //solver for adjacency list
    static void solve(AdjacencyList *list);


};


#endif //PDBFK_KRUSKALALGORITHM_H
