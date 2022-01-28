#pragma once
#include "../Operation.h"
class If : public Operation {
public:
	If(Node* expr, Node* sntns, int l = 0):Operation(expr,sntns,l){}
	Node* execute() override;
	virtual If* clone() const override { return new If(*this); }
	virtual ~If() {}
};

