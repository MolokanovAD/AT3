#pragma once
#include "../Variable.h"
class ConstIntArray : public Variable {
protected:
	std::vector<int*> value;
public:
	ConstIntArray(std::vector<int*> v, t typ = t::CONSTINTARR) : Variable(typ), value(v) {}
	ConstIntArray(const ConstIntArray& cia, t typ = t::CONSTINTARR);
	size_t size() { return value.size(); }
	std::vector<int*> getValue() const { return value; }
	std::vector<int*> pop() { std::vector<int*> v = value; value.clear(); return v; }
	virtual void dump() override { value.clear(); }
	ConstIntArray* clone() const override { return new ConstIntArray(*this); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~ConstIntArray();
};

