#pragma once
#include "../Operation.h"
class Id : public Operation {
	std::string id; 
	CallStack* callStack;
public:
	Id(std::string name, CallStack* vTable, int l = 0):Operation(l),callStack(vTable),id(name){}
	Node* execute() override;
	virtual Id* clone() const override { return new Id(*this); }
	virtual ~Id() {}
};

