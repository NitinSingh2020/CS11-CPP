#include <iostream>
#include "SparseVector.hh"

int main() {

    SparseVector a(10), b(10);

	a.setElem(7, 5);
	a.setElem(2, 8);
	std::cout << "+++++++++++++++ List A +++++++++++++" << std::endl;
	a.checkListOrder();


	b.setElem(6, 2);
	b.setElem(0, 5);
	b.setElem(7, -3);
	b.setElem(9, 1);
	b.setElem(2, 4);
	std::cout << "+++++++++++++++ List B +++++++++++++" << std::endl;
	b.checkListOrder();


	a += b;
	std::cout << "+++++++++++++++ Current After Adding +++++++++++++" << std::endl;
	a.checkListOrder();
}