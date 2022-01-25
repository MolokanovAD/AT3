#pragma once
#include "ConstBoolMatrix.h"
class BoolMatrix : public ConstBoolMatrix {
public:
	BoolMatrix(std::vector<std::vector<bool*>> m) : ConstBoolMatrix(m, t::BOOLMATRIX) {}
	BoolMatrix(const ConstBoolMatrix& cbm) :ConstBoolMatrix(cbm, t::BOOLMATRIX) {}
	BoolMatrix(const BoolMatrix& bm) :ConstBoolMatrix(bm, t::BOOLMATRIX) {}
	void addElement(Node* e);
	Bool* getValue(int i, int j) const override;
	BoolArray* getRow(int i) const override;
	BoolArray* getColumn(int i) const override;
	void setValue(std::vector<std::vector<bool*>> m);
	BoolMatrix* clone() const override { return new BoolMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~BoolMatrix() {}
};

