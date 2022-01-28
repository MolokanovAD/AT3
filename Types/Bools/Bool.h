#pragma once
#include "ConstBool.h"
class Bool : public ConstBool {
public:
	Bool(bool* v, int l = 0):ConstBool(v, t::VARBOOL,l){}
	//void setValue(bool* v) { value = v; }
	void setValue(bool v) { *value = v; }
	Bool* clone() const override { return new Bool(new bool(*value),line); }
	virtual ~Bool() {}
};
