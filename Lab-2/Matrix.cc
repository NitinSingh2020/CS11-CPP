#include "Matrix.hh"
#include <iostream>
#include <cassert>

/* Default (aka no-argument) constructor */
Matrix::Matrix() {
    numElems = 0;
    numRows = 0;
    numCols = 0;

    elems = new int[numElems];
}

/* Two-argument constructor */
Matrix::Matrix(int rows, int cols) {

    assert(rows > -1);
    assert(cols > -1);

    numElems = rows * cols;
    numRows = rows;
    numCols = cols;

    elems = new int[numElems];

    // Initialize all elements to 0
    for (int i = 0; i < numElems; i++) {
        elems[i] = 0;
    }
}

/* Copy Constructor */
Matrix::Matrix(const Matrix &mat) {
    numRows = mat.getrows();
    numCols = mat.getcols();

    numElems =  numRows * numCols;

    elems = new int[numElems];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int index = matIndex(i, j);
            elems[index] = mat.getelem(i, j);
        }
    }
}

/* Clean up a Matrix instance */
Matrix::~Matrix() {
    delete[] elems;
}

/* Accessor methods */
int Matrix::getrows() const {
    return numRows;
}
int Matrix::getcols() const {
    return numCols;
}
int Matrix::getelem(int row, int col) const {

    assert(row <= numRows);
    assert(col <= numCols);

    int index = matIndex(row, col);
    return elems[index];
}

/* Mutator method */
void Matrix::setelem(int row, int col, int val) {

    assert(row < numRows);
    assert(col < numCols);

    int index = matIndex(row, col);
    elems[index] = val;
}

/* Arithmetic methods */
void Matrix::add(const Matrix &mat) {

    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int index = matIndex(i, j);
            elems[index] += mat.getelem(i,j);
        }
    }
}
void Matrix::subtract(const Matrix &mat) {

    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int index = matIndex(i, j);
            elems[index] -= mat.getelem(i,j);
        }
    }
}

/* Comparison method */
bool Matrix::equals(const Matrix &mat) const {

    if (numRows == mat.getrows() && numCols == mat.getcols()) {
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int index = matIndex(i, j);
                if (elems[index] != mat.getelem(i,j)) {
                    return false;
                    break;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

int Matrix::matIndex(int row, int col) const {
    return (row * numCols) + col;
}