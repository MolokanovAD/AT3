#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Shift : public Operation {
protected:
	bool dir;
public:
	Shift(Node* f, bool d, int l = 0) :Operation(f,l), dir(d) {}
	Node* execute() override;
	virtual Shift* clone() const override { return new Shift(*this); }
	virtual ~Shift() {}
};

