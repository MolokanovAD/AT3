#pragma once
#include "../Operation.h"
#include "../Functions.h"
enum APPEAL {
	COORDINATES,
	COLUMNS,
	ROWS,
	LOGICAL
};

class Appeal :public Operation {
protected:
	std::string id;
	CallStack* callStack;
	APPEAL type;
public:
	Appeal(std::string name, Node* f, Node* s, CallStack* vTable, APPEAL t, int l = 0):Operation(f,s,l), id(name), callStack(vTable), type(t){}
	Appeal(std::string name, Node* f, CallStack* vTable, APPEAL t, int l = 0) :Operation(f,l), id(name), callStack(vTable), type(t) {}
	Node* execute() override;
	virtual Appeal* clone() const override { return new Appeal(*this); }
};

