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
    copy(mat);
}

/* Clean up a Matrix instance */
Matrix::~Matrix() {
    cleanup();
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

void Matrix::multiply(const Matrix &mat) {

    assert(numCols == mat.getrows());

    int n = numRows;
    int m = numCols;
    int p = mat.getcols();
    Matrix tempResult(numRows, mat.getcols());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            int sum = 0;
            for (int k = 1; k < m; k++) {
                sum =+ this->getelem(i,k) * mat.getelem(k,j);
            }
            tempResult.setelem(i,j,sum);
        }
    }

    *this = tempResult;
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

/* Assignment Operator */
Matrix & Matrix::operator=(const Matrix &mat) {
    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());
    // Avoid self-assignment
    if (this != &mat) {
        cleanup();
        copy(mat);
    }

    return *this;
}

/* Compound Sum Operator */
Matrix & Matrix::operator+=(const Matrix &mat) {
    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());
    // Avoid self-assignment
    if (this != &mat) {
        this->add(mat);
    } else {
        // First, make a copy of myself
        Matrix newCopy(*this);
        this->add(newCopy);
    }
    return *this;
}

/* Sum Operator */
const Matrix Matrix::operator+(const Matrix &mat) {
    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());
    /* More detailed implementation
    // First, make a copy of myself.
    Matrix result(*this);
    // Second, add the RHS to the result.
    result += mat;
    // All done!
    return result;
    */
    return Matrix(*this) += mat;
}

/* Compound Subtraction Operator */
Matrix & Matrix::operator-=(const Matrix &mat) {
    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());
    // Avoid self-assignment
    if (this != &mat) {
        this->subtract(mat);
    } else {
        // First, make a copy of myself
        Matrix newCopy(*this);
        this->subtract(newCopy);
    }
    return *this;
}

/* Subtraction Operator */
const Matrix Matrix::operator-(const Matrix &mat) {
    /* More detailed implementation
    // First, make a copy of myself.
    Matrix result(*this);
    // Second, subtract the RHS to the result.
    result -= mat;
    // All done!
    return result;
    */
    assert(numRows == mat.getrows());
    assert(numCols == mat.getcols());
    return Matrix(*this) -= mat;
}

/* Compound Multiplication Operator */
Matrix & Matrix::operator*=(const Matrix &mat) {
    assert(numCols == mat.getrows());
    // Avoid self-assignment
    if (this != &mat) {
        this->multiply(mat);
    } else {
        // First, make a copy of myself
        Matrix newCopy(*this);
        this->multiply(newCopy);
    }
    return *this;
}

/* Multiplication Operator */
const Matrix Matrix::operator*(const Matrix &mat) {
    assert(numCols == mat.getrows());
    /* More detailed implementation
    // First, make a copy of myself.
    Matrix result(*this);
    // Second, add the RHS to the result.
    result *= mat;
    // All done!
    return result;
    */
    return Matrix(*this) *= mat;
}

/* Helper Method 1 */
int Matrix::matIndex(int row, int col) const {
    return (row * numCols) + col;
}

/* Helper Method 2 */
void Matrix::copy(const Matrix &mat) {

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

/* Helper Method 3 */
void Matrix::cleanup() {
    delete[] elems;
}
