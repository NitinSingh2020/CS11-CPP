#include <iostream>
#include "SparseVector.hh"

int main() {
	// SparseVector sv(20);
	// sv.setElem(12, 234);
	// int k = sv.getElem(12);
	// std::cout << "Elem : " << k << std::endl;

	// sv.setElem(14, 0);
	// k = sv.getElem(14);
	// std::cout << "Elem : " << k << std::endl;

	// SparseVector sv1(43);
	// std::cout << "Test Elem 3: "<< sv1.getElem(2) << std::endl;

	SparseVector svNew(40);
	for (int i = 0; i < 2; i++)
	{
        int idx = i * 4 + i % 3;

        svNew.setElem(idx, 100 - 3 * i);
        std::cout << "Set List[" << idx << "] = " << 	100 - 3 * i << std::endl;
	}

	std::cout << std::endl;
	svNew.checkListOrder();
}