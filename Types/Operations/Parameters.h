#pragma once
#include "../Operation.h"
class Parameters :  public Operation {
public:
	Parameters(int l = 0):Operation(l) {}
	Parameters(Node* p, int l = 0):Operation(p,l){}
	void addParameter(Node* p) { operand.push_back(p); }
	Node* execute() override { return nullptr; }
	virtual Parameters* clone() const override { return new Parameters(*this); }
};

