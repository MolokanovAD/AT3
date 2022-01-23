#pragma once
#include "ConstIntMatrix.h"
class IntMatrix : public ConstIntMatrix {
public:
	IntMatrix(std::vector<std::vector<int>> m) :ConstIntMatrix(m, t::INTMATRIX) {}
	void addElement(Node* e);
	IntMatrix* clone() const override { return new IntMatrix(*this); }
	std::ostream& print(std::ostream& o) const override;
};

