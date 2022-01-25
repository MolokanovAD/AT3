#pragma once
#include "../Variable.h"
#include "../Ints/Int.h"
#include "../IntArrays/IntArray.h"
class ConstIntMatrix : public Variable {
protected:
	std::vector<std::vector<int*>> matrix;
	std::vector<int*> formColumn(int i) const;
public:
	ConstIntMatrix(std::vector<std::vector<int*>> m, t typ = t::CONSTINTMATRIX) : Variable(typ), matrix(m) {}
	ConstIntMatrix(const ConstIntMatrix& cim, t typ = t::CONSTINTMATRIX);
	virtual ConstInt* getValue(int i, int j) const;
	virtual ConstIntArray* getRow(int i) const;
	virtual ConstIntArray* getColumn(int i) const;
	std::vector<std::vector<int*>> getMatrix() { return matrix; }
	std::vector<std::vector<int*>> pop() { std::vector<std::vector<int*>> m = matrix; matrix.clear(); return m; }
	virtual void dump() override { matrix.clear(); }
	ConstIntMatrix* clone() const override { return new ConstIntMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~ConstIntMatrix();
};
