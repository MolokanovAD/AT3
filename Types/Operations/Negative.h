#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Negative :  public Operation {
public:
	Negative(Node* expr, int l = 0) :Operation(expr, l) {}
	Node* execute() override;
	virtual Negative* clone() const override { return new Negative(*this); }
	virtual ~Negative() {}
};

