#include "BoolMatrix.h"
#include "../Functions.h"

Bool* BoolMatrix::getValue(int i, int j,int l) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new Bool(matrix[i][j],l);
	throw std::exception("Wrong index");
}

BoolArray* BoolMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new BoolArray(matrix[i]);
	throw std::exception("Wrong index");
}

BoolArray* BoolMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		return new BoolArray(formColumn(i));
	}
	throw std::exception("Wrong index");
}

void BoolMatrix::addElement(Node* e, int line) {
	Node* p = e->execute();
	if (compatible(t::CONSTBOOLARR, p)) {
		auto vec = dynamic_cast<ConstBoolArray*>(p)->getValue();
		if (matrix.front().size() == vec.size())
			matrix.push_back(vec);
		else {
			std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	else
		throw std::exception("Wrong type");
}

void BoolMatrix::setValue(std::vector<std::vector<bool*>> m, int line) {
	if (matrix.size() != m.size() || matrix.front().size() != m.front().size()) {
		std::string errStr = "Error: Size mismatch, line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			*matrix[i][j] = *m[i][j];
		}
	}
}

std::ostream& BoolMatrix::print(std::ostream& o) const {
	o << "mbool " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << *matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}