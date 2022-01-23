#pragma once
#include "Node.h"
#include "Ints/Int.h"
#include "Bools/ConstBool.h"

class Operation : public Node {
protected:
	Node* first;
	Node* second;
	int getInt(Node* p);
public:
	Operation() { first = second = nullptr; }
	Operation(Node* f, Node* s) ;
	std::ostream& print(std::ostream& o) const override { return o; }
	virtual Operation* clone() const override { return nullptr; }
};

