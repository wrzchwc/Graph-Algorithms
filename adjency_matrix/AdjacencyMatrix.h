//
// Created by kubaw on 30.05.2021.
//

#ifndef PDBFK_ADJACENCYMATRIX_H
#define PDBFK_ADJACENCYMATRIX_H

#include <iostream>
#include <fstream>

using namespace std;

class AdjacencyMatrix {
private:
    //dynamic two-dimensional array containing id
    int **matrix;
    //size*size is the actual size of matrix
    int size;

    //initialises matrix
    void initializeMatrix(int matrixSize);

public:
    //constructor
    //todo: constructor which generates random graph directed or undirected
    explicit AdjacencyMatrix(int size);

    //constructor loading graph from file
    explicit AdjacencyMatrix(const string &filepath, const string& delimiter);

    //destructor
    virtual ~AdjacencyMatrix();

    //sets id in a specified row and column
    void setData(int data, int row, int column);

    //returns id stored in a specified row and column
    int getData(int row, int column);

    //returns square root of the size
    [[nodiscard]] int getSize() const;

    //displays content of the martrix
    void show();


};


#endif //PDBFK_ADJACENCYMATRIX_H
