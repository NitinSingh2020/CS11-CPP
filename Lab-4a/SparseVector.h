#ifndef SPARSEVECTOR_HH
#define SPARSEVECTOR_HH

class SparseVector {

    /* A linked-list node for our sparse vector elements */
    struct node {
        int index;     // Element number, in the range [0, size)
        int value;     // The value of this element.
        node *next;    // A pointer to the next node in the linked-list.

        /* Node constructor - simply initializes the data-members */
        node(int index, int value, node *next = 0) :
            index(index), value(value), next(next) { }
    };

    int size;          // List size
    node *start;       // Node-pointer to the first nonzero element in the list

    /* Private Helper Methods */
    void clear();
    void copyList(const SparseVector &sv);
    void setNonzeroElem(int index, int value);
    void removeElem(int index);
    void checkListOrder();

public:
    /* Constructors */
    SparseVector(int size);                   // Constructor
    SparseVector(const SparseVector &sv);     // Copy Constructor

    /* Destructor */
    ~SparseVector();

    /* Accessor methods */
    int getSize() const;
    int getElem(int idx) const;

    /* Mutator method */
    void setElem(int index, int value);

    /* Overloaded Operators */
    SparseVector & operator=(const SparseVector &sv);  // Assignment
};

#endif /* SPARSEVECTOR_HH */
















