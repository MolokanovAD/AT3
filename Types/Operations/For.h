#pragma once
#include "../Operation.h"
class For : public Operation {
protected:
	std::string id;
	CallStack* callStack;
public:
	For(std::string name, Node* expr1, Node* expr2, Node* sntns, CallStack* vTable, int l = 0);
	Node* execute() override;
	virtual For* clone() const override { return new For(*this); }
};

