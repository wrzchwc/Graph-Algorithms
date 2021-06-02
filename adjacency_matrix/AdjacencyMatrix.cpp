//
// Created by kubaw on 30.05.2021.
//
#include <iostream>
#include <string>
#include "AdjacencyMatrix.h"
#include "../Main.h"


using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int size, bool random, bool directed, double density, int maxWeight) {
    this->size = size;
    this->matrix = nullptr;
    initializeMatrix(size);
    auto edges_max = ((double) size * ((double) size - 1.0)) / 2.0;
    auto edges_min = (double) size - 1.0;
    double tmp = directed ? (edges_min * 0.5) / edges_max : edges_min / edges_max;
    if (density >= edges_min / edges_max && random) {
        //consistent graph
        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                if (column - row == 1) {
                    auto randomNumber = random_number(0, maxWeight);
                    matrix[row][column] = randomNumber;
                    if (!directed)
                        matrix[column][row] = randomNumber;
                }
            }
        }
        //achieving density
        while (tmp  < density) {
            int random_row = random_number(0, size - 1);
            int random_column = random_number(0, size - 1);
            if (random_row != random_column && matrix[random_row][random_column] == INT_MAX) {
                auto random_weight = random_number(0, maxWeight);
                setData(random_weight, random_row, random_column);
                tmp += 0.5 / edges_max;
                if (!directed) {
                    tmp += 0.5 / edges_max;
                    setData(random_weight, random_column, random_row);
                }
            }
        }
    } else
        cout << "Impossible to achieve density of " << density << " with number of vertexes equal " << size << endl;

}

void AdjacencyMatrix::setData(int data, int row, int column) {
    matrix[row][column] = data;
}

void AdjacencyMatrix::show() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            matrix[i][j] == INT_MAX ? cout << "X " : cout << matrix[i][j] << " ";
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

AdjacencyMatrix::AdjacencyMatrix() {
    size = 0;
    matrix = nullptr;
}
