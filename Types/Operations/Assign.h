#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Assign : public Operation {
protected:
	std::string id;
	CallStack* callStack;
public:
	Assign(std::string name, Node* expr, CallStack* vTable, int l = 0) :Operation(expr,l), callStack(vTable), id(name){}
	Assign(Node* appeal, Node* expr, CallStack* vTable, int l = 0) :Operation(appeal, expr, l), callStack(vTable){}
	Node* execute() override;
	virtual Assign* clone() const override { return new Assign(*this); }
};

