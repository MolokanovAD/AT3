#pragma once
#include "ConstIntArray.h"
class IntArray : public ConstIntArray {
public:
	IntArray(std::vector<int*> v, int l = 0) : ConstIntArray(v, t::INTARR,l) {}
	IntArray(const ConstIntArray& cia, int l = 0) :ConstIntArray(cia, t::INTARR,l) {}
	IntArray(const IntArray& ia, int l = 0) :ConstIntArray(ia, t::INTARR,l) {}
	void addElement(Node* e, int line);
	void setValue(std::vector<int*> v, int line);
	IntArray* clone() const override { return new IntArray(*this,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~IntArray(){}
};

