#pragma once
#include "../Operation.h"
#include "ExprSequence.h"
#include "Declare.h"
#include "Assign.h"
class Call : public Operation {
protected:
	std::string id;
	FunStack* funStack;
	CallStack* callStack;
	void deleteFrame();
	void formFunFrame();
public:
	Call(std::string name, Node* parsValues, CallStack* cs, FunStack* fs, int l = 0) :Operation(parsValues,l), funStack(fs), callStack(cs), id(name) {}
	Node* execute() override;
	virtual Call* clone() const override { return new Call(*this); }
	virtual ~Call() {}
};

