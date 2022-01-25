#pragma once
#include "Node.h"
class Variable : public Node {
protected:
	std::string name;
public:
	Variable(){}
	Variable(t typ): Node(typ) {}
	Variable(const std::string n):name(n) {}
	virtual Node* execute() override { return this; }
	virtual ~Variable() {}
};

