#pragma once
#include "../Variable.h"
class ConstBoolArray : public Variable {
protected:
	std::vector<bool> value;
public:
	ConstBoolArray(std::vector<bool> v, t typ = CONSTBOOLARR) : Variable(typ), value(v) {}
	std::vector<bool> getValue() const { return value; }
	ConstBoolArray* clone() const override { return new ConstBoolArray(*this); }
	std::ostream& print(std::ostream& o) const override;
};

