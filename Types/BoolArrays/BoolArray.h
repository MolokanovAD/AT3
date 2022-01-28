#pragma once
#include "ConstBoolArray.h"
class BoolArray : public ConstBoolArray {
public:
	BoolArray(std::vector<bool*> v, int l = 0) : ConstBoolArray(v, t::BOOLARR,l) {}
	BoolArray(const ConstBoolArray& cba, int l = 0) :ConstBoolArray(cba, t::BOOLARR,l) {}
	BoolArray(const BoolArray& ba, int l = 0) :ConstBoolArray(ba, t::BOOLARR,l) {}
	void addElement(Node* e);
	void setValue(std::vector<bool*> v);
	BoolArray* clone() const override { return new BoolArray(*this,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~BoolArray() {}
};

