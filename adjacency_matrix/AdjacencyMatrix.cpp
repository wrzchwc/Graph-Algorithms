//
// Created by kubaw on 30.05.2021.
//
#include <iostream>
#include <string>
#include "AdjacencyMatrix.h"
#include "../Main.h"


using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int size) {
    this->size = size;
    this->matrix = nullptr;
    initializeMatrix(size);
}

void AdjacencyMatrix::setData(int data, int row, int column) {
    matrix[row][column] = data;
}

void AdjacencyMatrix::show() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            matrix[i][j] == INT_MAX ? cout << "X" : cout << matrix[i][j];
        cout << endl;

    }
}

int AdjacencyMatrix::getData(int row, int column) {
    return matrix[row][column];
}

AdjacencyMatrix::~AdjacencyMatrix() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    size = 0;
}

int AdjacencyMatrix::getSize() const {
    return size;
}

AdjacencyMatrix::AdjacencyMatrix(const string &filepath, const string &delimiter, bool directed) {
    //todo: directed vs undirected graph
    fstream file;
    string tmp;
    this->size = 0;
    this->matrix = nullptr;

    file.open(filepath, ios::in);
    getline(file, tmp);
    //parameters[0]-edges parameters[1]-vertexes parameters[2]-start parameters[3]-end
    int *parameters = interpret(tmp, delimiter, 4);

    initializeMatrix(parameters[1]);

    while (getline(file, tmp)) {
        //edge[0] - start edge[1] - end edge [2] - weight
        int *edge = interpret(tmp, delimiter, 3);
        setData(edge[2], edge[0], edge[1]);
        if (!directed)
            setData(edge[2], edge[1], edge[0]);
    }

    file.close();
}

void AdjacencyMatrix::initializeMatrix(int matrixSize) {
    this->size = matrixSize;
    this->matrix = new int *[this->size];
    for (int i = 0; i < matrixSize; i++)
        matrix[i] = new int[this->size];
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
            matrix[i][j] = INT_MAX;
}
