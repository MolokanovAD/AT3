#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Add : public Operation {
public:
	Add(Node* f, Node* s, int l = 0) :Operation(f,s,l) {}
	Node* execute() override;
	std::ostream& print(std::ostream& o) const  override { return o << "Add: "; }
	virtual Add* clone() const override { return new Add(*this); }
	virtual ~Add() {}
};
