/* Default (aka no-argument) constructor */
Matrix::Matrix() {
	elems = new int[0];

	for (int i = 0;)
}

/* Two-argument constructor */
Matrix::Matrix(int m, int n) {
    numElems = m*n;
    elems = new int[numElems];

    for (int i = 0; i < numElems; i++) {
    	elems[i] = 0;
    }
}