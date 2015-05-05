#include "SparseVector.hh"
#include <iostream>
#include <cassert>

/* One-argument constructor */
SparseVector::SparseVector(int listSize) {
    size = listSize;
    start = 0;
}

/* Copy Constructor */
SparseVector::SparseVector(const SparseVector &sv) {
    copyList(sv);
}

/* Destructor */
SparseVector::~SparseVector() {
    clear();
}

/* Accessor methods */
int SparseVector::getSize() const {
    return size;
}

int SparseVector::getElem(int idx) const {

    node *curr = start;

    while (curr != 0 && curr->index <= idx) {
        
        // Do Something with current node
        if (curr->index == idx) {
            return curr->value;
        }
        
        // Go to next node in list
        curr = curr->next;
    }

    return 0;
}

/* Mutator method */
void SparseVector::setElem(int index, int value) {
    if (value != 0) {
        setNonzeroElem(index, value);
    } else {
        removeElem(index);
    }
}

/* Assignment Operator */
SparseVector & SparseVector::operator=(const SparseVector &sv) {

    // Avoid self-assignment
    if (this != &sv) {
        clear();
        copyList(sv);
    }

    return *this;
}

/* Private Helper Method 1 */
void SparseVector::clear() {

    node *curr = start;
    while (curr != 0) {

        // Get what is next, before deleting curr.
        node *next = curr->next;

        // Delete this node.
        delete curr;

        // Go to next node in list
        curr = next;
    }
}

/* Private Helper Method 2 */
void SparseVector::copyList(const SparseVector &other) {

    size = other.getSize();
    start = 0;

    // Get a pointer to other list's first node
    node *otherCurr = other.start;

    // Use prev and curr to create the copy
    node *prev = 0;
    while (otherCurr != 0) {
    
        // Copy other list's current node
        node *curr = new node(otherCurr->index, otherCurr->value);

        if (prev == 0)
            start = curr;             // curr is the first node in our copy!
        else
            prev->next = curr;        // Make previous node point to current

        prev = curr;                  // Done with current node!
        otherCurr = otherCurr->next;  // Move to next node to copy
   }
}

/* Private Helper Method 3 */
void SparseVector::setNonzeroElem(int index, int value) {

    assert(value != 0);
    
    // If empty list
    if (start == 0) {

        start = new node(index, value);
        size = size +1;
        return;
    }

    // Pointer to the current node
    node *curr = start;

    // Pointer to the previous node
    node *prev = 0;

    // List is not empty
    while (curr != 0) {

        // Get the next node
        node *next = curr->next;

        // Add node at front
        if (curr->index > index) {
            start = new node(index, value, curr);
            return;
        }

        // Update the existing node
        else if (curr->index == index) {
            curr->value = value;
            return;
        }

        // Add node at end
        else if (curr->index < index && curr->next == 0) {
            curr->next = new node(index, value);
            return;
        }

        // Add node in middle
        else if (curr->index < index  && index < next->index) {
            node *tempNode = new node(index, value, next);
            curr->next = tempNode;
            return;
        }

        prev = curr; // Update previous node
        curr = next; // Go to the next node in list
    }
}

/* Private Helper Method 4 */
void SparseVector::removeElem(int index) {

    // Pointer to the current node
    node *curr = start;

    // If empty list
    if (curr == 0) {
        return;
    }

    // Create prev node
    node *prev = 0;

    while (curr != 0) {

        // Get the next node
        node *next = curr->next;

        if (curr->index == index) {
            
            // Front Node
            if (prev == 0) {
                start = curr->next;
                delete curr;
                return;
            }
            
            // End Node
            else if (curr->next == 0) {
                prev->next = 0;
                delete curr;
                return;
            }

            // Middle Node
            else {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }

        prev = curr; // Update previous node
        curr = next; // Go to the next node in list
    }
}

/* Private Helper Method 5 */
void SparseVector::checkListOrder() {
    std::cout << "Printing the list:" << std::endl;
    
    // Pointer to the current node
    node *curr = start;

    // If empty list
    if (curr == 0) {
        std::cout << "    List is empty" << std::endl;
        return;
    }

    while (curr != 0) {

        // Get the next node
        node *next = curr->next;

        std::cout << "    list[" << curr->index << "] : " << curr->value << std::endl;
        // Go to next node in list
        curr = next;        
    }
}






















