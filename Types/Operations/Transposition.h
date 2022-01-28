#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Transposition : public Operation {
public:
	Transposition(Node* f,int l = 0) :Operation(f,l) {}
	Node* execute() override;
	virtual Transposition* clone() const override { return new Transposition(*this); }
	virtual ~Transposition() {}
};

