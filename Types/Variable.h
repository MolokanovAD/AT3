#pragma once
#include "Node.h"
class Variable : public Node {
protected:
	std::string name;
public:
	Variable(int l = 0): Node(l){}
	Variable(t typ,int l = 0): Node(typ,l) {}
	Variable(const std::string n):name(n) {}
	virtual Node* execute() override { return this; }
	virtual ~Variable() {}
};

