#pragma once
#include "../Variable.h"
class ConstInt : public Variable {
protected:
	int* value;
public:
	ConstInt():value(0){}
	ConstInt(int* v, t typ = t::CONSTINT,int l = 0) : Variable(typ,l), value(v) {}
	int getValue() const { return *value; }
	int* pop() { int* p = value; value = nullptr; return p; }
	virtual void dump() override { value = nullptr; }
	Node* execute() override { return this; }
	ConstInt* clone() const override { return new ConstInt(new int(*value), nodeType, line); }
	std::ostream& print(std::ostream& o) const override { return o << *value; }
	virtual ~ConstInt() { delete value; }
};