#pragma once
#include "ConstIntArray.h"
class IntArray : public ConstIntArray {
public:
	IntArray(std::vector<int*> v) : ConstIntArray(v, t::INTARR) {}
	IntArray(const ConstIntArray& cia) :ConstIntArray(cia, t::INTARR) {}
	IntArray(const IntArray& ia) :ConstIntArray(ia, t::INTARR) {}
	void addElement(Node* e);
	void setValue(std::vector<int*> v);
	IntArray* clone() const override { return new IntArray(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~IntArray(){}
};

