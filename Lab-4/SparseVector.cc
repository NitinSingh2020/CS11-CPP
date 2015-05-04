#include "SparseVector.hh"
#include <iostream>
#include <cassert>

/* One-argument constructor */
SparseVector::SparseVector(int listSize) {
    // std::cout << "Argument Constructor" << std::endl;
    size = listSize;
    start = 0;
    // std::cout << "List Size: " << size << std::endl;
}

/* Copy Constructor */
SparseVector::SparseVector(const SparseVector &sv) {
    // std::cout << "Copy Constructor" << std::endl;
    copyList(sv);
}

/* Destructor */
SparseVector::~SparseVector() {
    // std::cout << "          Destructor" << std::endl;
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
    // std::cout << "clear method start" << std::endl;
    // std::cout << "List size is: " << size << std::endl;
    // if (start == 0) {
    //     std::cout << "Start is indeed 0" << std::endl;
    // } else {
    //     std::cout << "Woops Bug !!" << std::endl;
    //     std::cout << "    :Index" << start->index  << std::endl;
    //     std::cout << "    :Index" << start->value  << std::endl;
    // }
    // int i = 0;
    node *curr = start;
    while (curr != 0) {
        // std::cout << "i: " << i+1 << std::endl; i++;
        // Get what is next, before deleting curr.
        node *next = curr->next;
        // std::cout << "next node assigned" << std::endl;
        // Delete this node.
        delete curr;
        // std::cout << "node deleted" << std::endl;
        // Go to next node in list
        curr = next;
    }
    // std::cout << "clear method end" << std::endl;
}

/* Private Helper Method 2 */
void SparseVector::copyList(const SparseVector &other) {
    // std::cout << "copyList method start" << std::endl;
    size = other.getSize();
    start = 0;
    // Get a pointer to other list's first node
    node *otherCurr = other.start;

    // Use prev and curr to create the copy
    node *prev = 0;
    while (otherCurr != 0) {
    	// std::cout << "    SparseVector is not empty" << std::endl;
        // Copy other list's current node
        node *curr = new node(otherCurr->index, otherCurr->value);

        if (prev == 0)
            start = curr;             // curr is the first node in our copy!
        else
            prev->next = curr;        // Make previous node point to current

        prev = curr;                  // Done with current node!
        otherCurr = otherCurr->next;  // Move to next node to copy
   }
   // std::cout << "copyList method end" << std::endl;
}

/* Private Helper Method 3 */
void SparseVector::setNonzeroElem(int index, int value) {
    //std::cout << "Top of the setNonzeroElem method" << std::endl;
    assert(value != 0);
    
    // If empty list
    if (start == 0) {
        std::cout << "Inside the empty list code" << std::endl;
        start = new node(index, value);
        size = size +1;
        return;
    }

    // Pointer to the current node
    node *curr = start;

    // Create prev node
    node *prev = 0;

    // List is not empty
    while (curr != 0) {

        // Get the next node
        node *next = curr->next;

        // At the first node
        if (prev == 0) {
            std::cout << "Adding the node 1" << std::endl;
            // Update the node if it already exists
            if (curr->index == index) {
                curr->value = value;
                return;
            }

            // Add the node if it does not exist
            if ( index < (curr->index) ) {
                start = new node(index, value, curr->next);
                size += 1;
                return;
            }

            // Add the node if it does not exist
            if ( index > (curr->index) ) {
                start = new node(index, value, curr->next);
                size += 1;
                return;
            }

        } else if (curr->next != 0) {
            std::cout << "Adding the node 2" << std::endl;
            // Update the node if it already exists
            if (curr->index == index) {
                curr->value = value;
                return;
            }

            // Add the node if it does not exist
            if ( index < (curr->index) ) {
                prev = new node(index, value, curr->next);
                size += 1;
                return;
            }
        } else if (curr->next == 0 && index > curr->index) {
            std::cout << "Adding the node 3" << std::endl;
            curr = new node(index, value);
            size += 1;
            return;
        }

        prev = curr; // Update previous node
        curr = next; // Go to the next node in list
    }
    //checkListOrder();
    //std::cout << "Bottom of the setNonzeroElem method" << std::endl;
}

/* Private Helper Method 4 */
void SparseVector::removeElem(int index) {
    //std::cout << "Top of the removeElem method" << std::endl;
    //std::cout << "        Index is: " << index << std::endl;
    // Pointer to the current node
    node *curr = start;
    // std::cout << "List[index]: " << curr->value << std::endl;
    // std::cout << "List.index: " << curr->index << std::endl;
    // std::cout << "List.next: " << curr->next << std::endl;

    // If empty list
    if (curr == 0) {
        return;
    }

    // Create prev node
    node *prev = 0;

    while (curr != 0) {
        //std::cout << "Inside the while loop" << std::endl;

        // Get the next node
        node *next = curr->next;

        // At the first node
        if (prev == 0) {
            // If node exists delete the node.
            if (curr->index == index) {
                start = curr->next;
                delete curr;
                size -= 1;
                return;
            }
        } else if (curr->next != 0) {
            // If node exists delete the node.
            if (curr->index == index) {
                prev->next = curr->next;
                delete curr;
                size -= 1;
                return;
            }
        } else if (curr->next == 0) {
            // If node exists delete the node.
            if (curr->index == index) {
                prev->next = 0;
                delete curr;
                size -= 1;
                return;
            }
        }

        prev = curr; // Update previous node
        curr = next; // Go to the next node in list
    }
    //checkListOrder();
    //std::cout << "Bottom of the removeElem method" << std::endl;
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






















