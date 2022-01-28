#pragma once
#include "ConstBoolMatrix.h"
class BoolMatrix : public ConstBoolMatrix {
public:
	BoolMatrix(std::vector<std::vector<bool*>> m, int l = 0) : ConstBoolMatrix(m, t::BOOLMATRIX,l) {}
	BoolMatrix(const ConstBoolMatrix& cbm, int l = 0) :ConstBoolMatrix(cbm, t::BOOLMATRIX,l) {}
	BoolMatrix(const BoolMatrix& bm, int l = 0) :ConstBoolMatrix(bm, t::BOOLMATRIX,l) {}
	void addElement(Node* e);
	Bool* getValue(int i, int j) const override;
	BoolArray* getRow(int i) const override;
	BoolArray* getColumn(int i) const override;
	void setValue(std::vector<std::vector<bool*>> m);
	BoolMatrix* clone() const override { return new BoolMatrix(*this,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~BoolMatrix() {}
};

