#ifndef MATRIX_HH
#define MATRIX_HH

class Matrix {
    int numElems;       // Total elements in Matrix
    int numRows;        // Row size
    int numCols;        // Column size
    int *elems;
    
    /* Private Helper Method */
    int matIndex(int row, int col) const;
    void copy(const Matrix &mat);
    void cleanup();

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
    void add(const Matrix &mat);
    void subtract(const Matrix &mat);
    void multiply(const Matrix &mat);

    /* Comparison method */
    bool equals(const Matrix &mat) const;

    /* Overloaded Operators */
    Matrix & operator=(const Matrix &mat);       // Assignment
    Matrix & operator+=(const Matrix &mat);      // Compound sum
    Matrix & operator-=(const Matrix &mat);      // Compound subtraction
    Matrix & operator*=(const Matrix &mat);      // Compound Multiplication
    const Matrix operator+(const Matrix &mat);   // Sum
    const Matrix operator-(const Matrix &mat);   // Subtraction
    const Matrix operator*(const Matrix &mat);   // Multiplication
};

#endif /* MATRIX_HH */