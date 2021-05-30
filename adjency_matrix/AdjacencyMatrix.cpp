//
// Created by kubaw on 30.05.2021.
//
#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int size) {
    this->size = size;
    matrix = new int *[this->size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[this->size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = INT_MAX;
}

void AdjacencyMatrix::setData(int data, int row, int column) {
    matrix[row][column] = data;
}

void AdjacencyMatrix::show() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
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
