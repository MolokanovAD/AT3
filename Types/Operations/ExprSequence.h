#pragma once
#include "../Operation.h"
#include "../Functions.h"
class ExprSequence : public Operation {
public:
	ExprSequence(int l = 0):Operation(l) {}
	ExprSequence(Node* expr, int l = 0) :Operation(expr,l){}
	void pushExpr(Node* expr) { operand.push_back(expr); }
	Node* execute() override;
	virtual ExprSequence* clone() const override { return new ExprSequence(*this); }
	virtual ~ExprSequence() {}
};

