#include "SparseVector.hh"
#include <iostream>
#include <cassert>

/* One-argument constructor */
SparseVector::SparseVector(int size) {}

/* Copy Constructor */
SparseVector::SparseVector(const SparseVector &sv) {}

/* Destructor */
SparseVector::~SparseVector() {}

/* Accessor methods */
int SparseVector::getSize() const {}

int SparseVector::getElem(int idx) const {}

/* Mutator method */
void SparseVector::setElem(int index, int value) {}

/* Assignment Operator */
SparseVector & SparseVector::operator=(const SparseVector &sv) {}

/* Private Helper Method 1 */
int SparseVector::clear(int row, int col) {}

/* Private Helper Method 2 */
void SparseVector::copyList(const SparseVector &sv) {}

/* Private Helper Method 3 */
void SparseVector::setNonzeroElem(int index, int value) {}

/* Private Helper Method 4 */
void SparseVector::removeElem(int index) {}

/* Private Helper Method 5 */
void SparseVector::checkListOrder() {}