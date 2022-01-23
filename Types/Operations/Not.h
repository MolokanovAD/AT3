#pragma once
#include "../Operation.h"
#include "../Bools/Bool.h"
#include "../Ints/Int.h"
class Not : public Operation {
public:
	Not(Node* child) : Operation(child, nullptr) {}
	Node* execute();
};

