#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Add : public Operation {
public:
	Add(Node* f, Node* s) :Operation(f,s) {}
	Node* execute() override;
	std::ostream& print(std::ostream& o) const  override { return o << "Add: "; }
};
