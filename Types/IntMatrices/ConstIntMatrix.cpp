#include "ConstIntMatrix.h"

Int* ConstIntMatrix::getValue(int i, int j) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new Int(matrix[i][j]);
	throw std::exception("Wrong index");
}

IntArray* ConstIntMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new IntArray(matrix[i]);
	throw std::exception("Wrong index");
}

IntArray* ConstIntMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		std::vector<int> res;
		for (auto& row : matrix) {
			res.push_back(row[i]);
		}
		return new IntArray(res);
	}
	throw std::exception("Wrong index");
}

std::ostream& ConstIntMatrix::print(std::ostream& o) const {
	o << "cmint " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}