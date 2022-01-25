#include "ConstBoolMatrix.h"

ConstBoolMatrix::ConstBoolMatrix(const ConstBoolMatrix& cbm, t typ):Variable(typ) {
	for (auto& i : cbm.matrix) {
		std::vector<bool*> line;
		for (auto j : i) {
			line.push_back(new bool(*j));
		}
		matrix.push_back(line);
	}
}

std::vector<bool*> ConstBoolMatrix::formColumn(int i) const{
	std::vector<bool*> res;
	for (auto& row : matrix) {
		res.push_back(row[i]);
	}
	return res;
}

ConstBool* ConstBoolMatrix::getValue(int i, int j) const {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size())
		return new ConstBool(matrix[i][j]);
	throw std::exception("Wrong index");
}

ConstBoolArray* ConstBoolMatrix::getRow(int i) const {
	if (i >= 0 && i < matrix.size())
		return new ConstBoolArray(matrix[i]);
	throw std::exception("Wrong index");
}

ConstBoolArray* ConstBoolMatrix::getColumn(int i) const {
	if (i >= 0 && i < matrix[0].size()) {
		return new ConstBoolArray(formColumn(i));
	}
	throw std::exception("Wrong index");
}

std::ostream& ConstBoolMatrix::print(std::ostream& o) const {
	o << "cmbool " << name << " : " << std::endl;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.front().size(); j++) {
			o << *matrix[i][j] << "  ";
		}
		o << std::endl;
	}
	return o;
}

ConstBoolMatrix::~ConstBoolMatrix() {
	for (auto& i : matrix) {
		for (auto j : i)
			delete j;
		i.clear();
	}
	matrix.clear();
}