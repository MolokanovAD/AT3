#pragma once
#include "../Variable.h"
class ConstBoolArray : public Variable {
protected:
	std::vector<bool*> value;
public:
	ConstBoolArray(std::vector<bool*> v, t typ = CONSTBOOLARR, int l = 0) : Variable(typ,l), value(v) {}
	ConstBoolArray(const ConstBoolArray& cba, t typ = t::CONSTBOOLARR, int l = 0);
	size_t size() { return value.size(); }
	std::vector<bool*> getValue() const { return value; }
	std::vector<bool*> pop() { std::vector<bool*> v = value; value.clear(); return v; }
	bool* getVal(int i);
	virtual void dump() override { value.clear(); }
	ConstBoolArray* clone() const override { return new ConstBoolArray(*this,nodeType,line); }
	std::ostream& print(std::ostream& o) const override;
	virtual ~ConstBoolArray();
};

