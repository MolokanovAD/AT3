#pragma once
#include "../Variable.h"
#include "../Bools/Bool.h"
#include "../BoolArrays/BoolArray.h"
class ConstBoolMatrix : public Variable {
protected:
	std::vector<std::vector<bool>> matrix;
public:
	ConstBoolMatrix(std::vector<std::vector<bool>> m, t typ = CONSTBOOLMATRIX) : Variable(typ), matrix(m) {}
	Bool* getValue(int i, int j) const;
	BoolArray* getRow(int i) const;
	BoolArray* getColumn(int i) const;
	std::vector<std::vector<bool>> getMatrix() { return matrix; }
	ConstBoolMatrix* clone() const override { return new ConstBoolMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
};

