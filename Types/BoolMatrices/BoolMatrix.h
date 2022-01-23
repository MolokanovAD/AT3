#pragma once
#include "ConstBoolMatrix.h"
class BoolMatrix : public ConstBoolMatrix {
public:
	BoolMatrix(std::vector<std::vector<bool>> m) : ConstBoolMatrix(m, t::BOOLMATRIX) {}
	void addElement(Node* e);
	BoolMatrix* clone() const override { return new BoolMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
};

