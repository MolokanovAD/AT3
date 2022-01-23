#pragma once
#include "../Variable.h"
#include "../Ints/Int.h"
#include "../IntArrays/IntArray.h"
class ConstIntMatrix : public Variable {
protected:
	std::vector<std::vector<int>> matrix;
public:
	ConstIntMatrix(std::vector<std::vector<int>> m, t typ = t::CONSTINTMATRIX) : Variable(typ), matrix(m) {}
	Int* getValue(int i, int j) const;
	IntArray* getRow(int i) const;
	IntArray* getColumn(int i) const;
	std::vector<std::vector<int>> getMatrix() { return matrix; }
	ConstIntMatrix* clone() const override { return new ConstIntMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
};

