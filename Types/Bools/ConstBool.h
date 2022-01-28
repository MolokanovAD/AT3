#pragma once
#include "../Variable.h"
class ConstBool : public Variable {
protected:
	bool* value;
public:
	ConstBool() :value(nullptr) {}
	ConstBool(bool* v, t typ = CONSTBOOL, int l = 0) : Variable(typ,l), value(v) { }
	//ConstBool(const ConstBool& cb):ConstBool(new bool(cb.value)) {}
	bool getValue() { return *value; }
	bool* pop() { bool* p = value; value = nullptr; return p; }
	virtual void dump() override { value = nullptr; }
	Node* execute() override { return this; }
	ConstBool* clone() const override { return new ConstBool(new bool(*value),nodeType,line); }
	std::ostream& print(std::ostream& o) const override { return o << *value; }
	virtual ~ConstBool() { delete value; }
};