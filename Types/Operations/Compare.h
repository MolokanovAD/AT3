#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Compare : public Operation {
private:
	bool bigger;
public:
	Compare(Node* f, Node* s,bool b) :Operation(f, s),bigger(b) {}
	Node* execute() override;
};

