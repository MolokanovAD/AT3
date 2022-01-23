#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Subtract : public Operation {
public:
	Subtract(Node* f, Node* s) :Operation(f, s) {}
	Node* execute() override;
	std::ostream& print(std::ostream& o) const  override { return o << "Subtract: "; }
};

