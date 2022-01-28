#pragma once
#include "../Operation.h"
#include "../Functions.h"
class And : public Operation {
public:
	And(Node* f, Node* s, int l = 0):Operation(f,s,l){}
	Node* execute() override;
	virtual And* clone() const override { return new And(*this); }
};

