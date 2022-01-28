#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Subtract : public Operation {
public:
	Subtract(Node* f, Node* s, int l = 0) :Operation(f, s, l) {}
	Node* execute() override;
	std::ostream& print(std::ostream& o) const  override { return o << "Subtract: "; }
	virtual Subtract* clone() const override { return new Subtract(*this); }
	virtual ~Subtract() {}
};

