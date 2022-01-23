#pragma once
#include "ConstBoolArray.h"
class BoolArray : public ConstBoolArray {
public:
	BoolArray(std::vector<bool> v) : ConstBoolArray(v, t::BOOLARR) {}
	void addElement(Node* e);
	BoolArray* clone() const override { return new BoolArray(*this); }
	std::ostream& print(std::ostream& o) const override;
};

