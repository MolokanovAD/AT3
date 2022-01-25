#pragma once
#include "ConstIntMatrix.h"
class IntMatrix : public ConstIntMatrix {
public:
	IntMatrix(std::vector<std::vector<int*>> m) :ConstIntMatrix(m, t::INTMATRIX) {}
	IntMatrix(const ConstIntMatrix& cim) :ConstIntMatrix(cim, t::INTMATRIX) {}
	IntMatrix(const IntMatrix& im) :ConstIntMatrix(im, t::INTMATRIX) {}
	void addElement(Node* e);
	Int* getValue(int i, int j) const override;
	IntArray* getRow(int i) const override;
	IntArray* getColumn(int i) const override;
	void setValue(std::vector<std::vector<int*>> m);
	IntMatrix* clone() const override { return new IntMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~IntMatrix() {}
};

