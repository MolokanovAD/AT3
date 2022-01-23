#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Transposition : public Operation {
public:
	Transposition(Node* f) :Operation(f, nullptr) {}
	Node* execute() override;
};

