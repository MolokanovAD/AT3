#include "ConstIntMatrix.h"

ConstIntMatrix::ConstIntMatrix(const ConstIntMatrix& cim, t typ = t::CONSTINTMATRIX):Variable(typ) {
	for (auto& i : cim.matrix) {
		std::vector<int*> line;
		for (auto j : i) {
			line.push_back(new int(*j));
		}
		matrix.push_back(line);
	}
}

std::vector<int*> ConstIntMatrix::formColumn(int i) const {
	std::vector<int*> res;
	for (auto& row : matrix) {
		res.push_back(row[i]);
	}
	return res;
}

ConstInt* ConstIntMatrix::getValue(int i, int j) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new ConstInt(matrix[i][j]);
	throw std::exception("Wrong index");
}

ConstIntArray* ConstIntMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new ConstIntArray(matrix[i]);
	throw std::exception("Wrong index");
}

ConstIntArray* ConstIntMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		return new ConstIntArray(formColumn(i));
	}
	throw std::exception("Wrong index");
}

std::ostream& ConstIntMatrix::print(std::ostream& o) const {
	o << "cmint " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << *matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}

ConstIntMatrix::~ConstIntMatrix() {
	for (auto& i : matrix) {
		for (auto j : i)
			delete j;
		i.clear();
	}
	matrix.clear();
}