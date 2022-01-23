#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Shift : public Operation {
protected:
	bool dir;
public:
	Shift(Node* f, bool d) :Operation(f, nullptr), dir(d) {}
	Node* execute() override;
};

