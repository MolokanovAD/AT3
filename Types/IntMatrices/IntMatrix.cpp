#include "IntMatrix.h"
#include "../Functions.h"
void IntMatrix::addElement(Node* e) {
	if (compatible(t::CONSTINTARR, e)) {
		auto vec = dynamic_cast<ConstIntArray*>(e)->getValue();
		if (matrix.front().size() == vec.size())
			matrix.push_back(vec);
		else
			throw std::exception("Wrong size of line");
	}
	else
		throw std::exception("Wrong type");
}

std::ostream&IntMatrix::print(std::ostream& o) const {
	o << "mint " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}