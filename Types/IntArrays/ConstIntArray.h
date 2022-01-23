#pragma once
#include "../Variable.h"
class ConstIntArray : public Variable {
protected:
	std::vector<int> value;
public:
	ConstIntArray(std::vector<int> v, t typ = t::CONSTINTARR) : Variable(typ), value(v) {}
	std::vector<int> getValue() const { return value; }
	ConstIntArray* clone() const override { return new ConstIntArray(*this); }
	std::ostream& print(std::ostream& o) const override;
};

