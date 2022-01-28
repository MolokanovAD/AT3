#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Compare : public Operation {
private:
	bool bigger;
public:
	Compare(Node* f, Node* s,bool b, int l = 0) :Operation(f, s, l),bigger(b) {}
	Node* execute() override;
	virtual Compare* clone() const override { return new Compare(*this); }
};

