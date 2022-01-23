#include "ConstBoolMatrix.h"

Bool* ConstBoolMatrix::getValue(int i, int j) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new Bool(matrix[i][j]);
	throw std::exception("Wrong index");
}

BoolArray* ConstBoolMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new BoolArray(matrix[i]);
	throw std::exception("Wrong index");
}

BoolArray* ConstBoolMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		std::vector<bool> res;
		for (auto& row : matrix) {
			res.push_back(row[i]);
		}
		return new BoolArray(res);
	}
	throw std::exception("Wrong index");
}

std::ostream& ConstBoolMatrix::print(std::ostream& o) const {
	o << "cmbool " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}