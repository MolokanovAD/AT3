#pragma once
#include "ConstInt.h"
class Int : public ConstInt {
public:
	Int(int* v) :ConstInt(v, t::VARINT) {}
	//void setValue(int* v) { value = v; }
	void setValue(int v) { *value = v; }
	Int* clone() const override { return new Int(new int(*value)); }
	virtual ~Int() {}
};