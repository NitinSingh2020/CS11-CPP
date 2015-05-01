#ifndef MATRIX_HH
#define MATRIX_HH

class Matrix {
    
public:
    /* Constructors */
    Matrix();                             // Default Constructor
    Matrix(int a, int b);                 // Constructor
    Matrix(const Matrix &mat);            // Copy Constructor

    /* Destructor */
    ~Matrix();
};

#endif MATRIX_HH