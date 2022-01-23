#pragma once
#include "../Variable.h"
class ConstBool : public Variable {
protected:
	bool value;
public:
	ConstBool() :value(false) {}
	ConstBool(bool v, t typ = CONSTBOOL) : Variable(typ), value(v) { }
	bool getValue() { return value; }
	Node* execute() override { return this; }
	ConstBool* clone() const override { return new ConstBool(*this); }
	std::ostream& print(std::ostream& o) const override { return o << value; }
};