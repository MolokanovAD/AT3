#pragma once
#include "ConstBool.h"
class Bool : public ConstBool {
public:
	Bool(bool v):ConstBool(v, t::VARBOOL){}
	void setValue(bool v) { value = v; }
	Bool* clone() const override { return new Bool(*this); }
};
