#pragma once
#include "ConstIntArray.h"
class IntArray : public ConstIntArray {
public:
	IntArray(std::vector<int> v) : ConstIntArray(v, t::INTARR) {}
	void addElement(Node* e);
	IntArray* clone() const override { return new IntArray(*this); }
	std::ostream& print(std::ostream& o) const override;
};

