#pragma once
#include "ConstBoolArray.h"
class BoolArray : public ConstBoolArray {
public:
	BoolArray(std::vector<bool*> v) : ConstBoolArray(v, t::BOOLARR) {}
	BoolArray(const ConstBoolArray& cba) :ConstBoolArray(cba, t::BOOLARR) {}
	BoolArray(const BoolArray& ba) :ConstBoolArray(ba, t::BOOLARR) {}
	void addElement(Node* e);
	void setValue(std::vector<bool*> v);
	BoolArray* clone() const override { return new BoolArray(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~BoolArray() {}
};

