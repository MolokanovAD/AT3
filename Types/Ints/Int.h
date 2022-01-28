#pragma once
#include "ConstInt.h"
class Int : public ConstInt {
public:
	Int(int* v, int l = 0) :ConstInt(v, t::VARINT,l) {}
	//void setValue(int* v) { value = v; }
	void setValue(int v) { *value = v; }
	void inc() { *value= (*value + 1); }
	Int* clone() const override { return new Int(new int(*value),line); }
	virtual ~Int() {}
};