#pragma once
#include "../Operation.h"
#include "../Functions.h"
class And : public Operation {
public:
	And(Node* f, Node* s):Operation(f,s){}
	Node* execute() override;
};

