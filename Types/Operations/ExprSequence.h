#pragma once
#include "../Operation.h"
#include "../Functions.h"
class ExprSequence : public Operation {
protected:
	std::vector<Node*> exprs;
public:
	ExprSequence(Node* expr) { exprs.push_back(expr); }
	void pushExpr(Node* expr) { exprs.push_back(expr); }
	Node* execute() override;
};

