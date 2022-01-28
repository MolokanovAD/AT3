#pragma once
#include "../Operation.h"
#include "Parameters.h"
class Function : public Operation {
	CallStack* callStack;
	std::string name;
public:
	Function(Node* returnVals, std::string n, Node* params, Node* sents, CallStack* vT, int l = 0);
	Node* execute() override { return nullptr; }
	//size_t paramsFrom()const;
	size_t paramsMax()const;
	size_t returnValuesAmount()const { return dynamic_cast<Parameters*>(operand[0])->size(); }
	Node* param(int index);
	Node* body() { return operand[2]; }
	Node* returnValue(int index);
	std::string getName() const { return name; }
	virtual Function* clone() const override { return new Function(*this); }
	virtual ~Function();
};

typedef std::stack<std::map<std::string, Function*>*> FunStack;
