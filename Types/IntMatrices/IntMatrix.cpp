#include "IntMatrix.h"
#include "../Functions.h"

Int* IntMatrix::getValue(int i, int j) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new Int(matrix[i][j]);
	throw std::exception("Wrong index");
}

IntArray* IntMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new IntArray(matrix[i]);
	throw std::exception("Wrong index");
}

IntArray* IntMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		return new IntArray(formColumn(i));
	}
	throw std::exception("Wrong index");
}

void IntMatrix::addElement(Node* e) {
	Node* p = e->execute();
	if (compatible(t::CONSTINTARR, p)) {
		auto vec = dynamic_cast<ConstIntArray*>(p)->getValue();
		if (matrix.front().size() == vec.size())
			matrix.push_back(vec);
		else
			throw std::exception("Wrong size of line");
	}
	else
		throw std::exception("Wrong type");
}

void IntMatrix::setValue(std::vector<std::vector<int*>> m) {
	if (matrix.size() != m.size() || matrix.front().size() != m.front().size())
		throw std::exception("Wrong size");
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			*matrix[i][j] = *m[i][j];
		}
	}
}

std::ostream& IntMatrix::print(std::ostream& o) const {
	o << "mint " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << *matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}