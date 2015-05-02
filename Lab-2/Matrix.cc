#include "Matrix.hh"
#include <iostream>

/* Default (aka no-argument) constructor */
Matrix::Matrix() {
	numElems = 0;
	numRows = 0;
	numCols = 0;

	elems = new int[numElems];
}

/* Two-argument constructor */
Matrix::Matrix(int m, int n) {
    numElems = m*n;
    numRows = m;
    numCols = n;

    elems = new int[numElems];

    // Initialize all elements to 0
    for (int i = 0; i < numElems; i++) {
        elems[i] = 0;
    }
}

/* Copy Constructor */
Matrix::Matrix(const Matrix &mat) {
    std::cout << "Copy constructor called" << std::endl;
    numRows = mat.getrows();
    numCols = mat.getcols();

    numElems =  numRows * numCols;

    elems = new int[numElems];
    for (int i = 0; i < numRows; i++) {
    	for (int j = 0; j < numCols; j++) {
    		int index = (i * numCols) + j; 
            elems[index] = mat.getelem(i,j);
    	}
    }
}

/* Clean up a Matrix instance */
Matrix::~Matrix() {
    std::cout << "Destructor called" << std::endl;
    delete[] elems;
}

/* Accessor methods */
int Matrix::getrows() const {
    return numRows;
}
int Matrix::getcols() const {
    return numCols;
}
int Matrix::getelem(int i, int j) const {
	int index = (i * numCols) + j;
    return elems[index];
}

/* Mutator method */
void Matrix::setelem(int row, int col, int val) {
	int index = (row * numCols) + col;
	elems[index] = val;
}

/* Arithmetic methods */
void Matrix::add() {}
void Matrix::subtract() {}

/* Comparison method */
bool Matrix::equals() const {}











