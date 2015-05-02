#ifndef MATRIX_HH
#define MATRIX_HH

class Matrix {
    int numElems;       // Total elements in Matrix
    int numRows;        // Row size
    int numCols;        // Column size
    int *elems;

public:
    /* Constructors */
    Matrix();                             // Default Constructor
    Matrix(int a, int b);                 // Constructor
    Matrix(const Matrix &mat);            // Copy Constructor

    /* Destructor */
    ~Matrix();

    /* Accessor methods */
    int getrows() const;
    int getcols() const;
    int getelem(int i, int j) const;

    /* Mutator method */
    void setelem(int row, int col, int val);

    /* Arithmetic methods */
    void add();
    void subtract();

    /* Comparison method */
    bool equals() const;
};

#endif /* MATRIX_HH */