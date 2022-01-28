#pragma once
#include "../Variable.h"
class ConstIntArray : public Variable {
protected:
	std::vector<int*> value;
public:
	ConstIntArray(std::vector<int*> v, t typ = t::CONSTINTARR, int l = 0) : Variable(typ,l), value(v) {}
	ConstIntArray(const ConstIntArray& cia, t typ = t::CONSTINTARR, int l = 0);
	size_t size() { return value.size(); }
	std::vector<int*> getValue() const { return value; }
	int operator[](int index) const;
	std::vector<int*> pop() { std::vector<int*> v = value; value.clear(); return v; }
	virtual void dump() override { value.clear(); }
	std::vector<int*> negativeValue() const;
	ConstIntArray* clone() const override { return new ConstIntArray(*this,nodeType,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~ConstIntArray();
};

