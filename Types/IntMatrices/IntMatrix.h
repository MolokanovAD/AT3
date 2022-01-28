#pragma once
#include "ConstIntMatrix.h"
class IntMatrix : public ConstIntMatrix {
public:
	IntMatrix(std::vector<std::vector<int*>> m, int l = 0) :ConstIntMatrix(m, t::INTMATRIX,l) {}
	IntMatrix(const ConstIntMatrix& cim, int l = 0) :ConstIntMatrix(cim, t::INTMATRIX,l) {}
	IntMatrix(const IntMatrix& im, int l = 0) :ConstIntMatrix(im, t::INTMATRIX,l) {}
	void addElement(Node* e, int line);
	Int* getValue(int i, int j,int l) const override;
	IntArray* getRow(int i) const override;
	IntArray* getColumn(int i) const override;
	void setValue(std::vector<std::vector<int*>> m, int line);
	IntMatrix* clone() const override { return new IntMatrix(*this, line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~IntMatrix() {}
};

