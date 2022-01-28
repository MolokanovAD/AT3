#pragma once
#include "../Operation.h"
#include "../Bools/Bool.h"
#include "../Ints/Int.h"
class Not : public Operation {
public:
	Not(Node* child, int l = 0) : Operation(child,l) {}
	Node* execute();
	virtual Not* clone() const override { return new Not(*this); }
};

