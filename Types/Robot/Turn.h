#pragma once
#include "../Operation.h"
class Turn : public Operation {
private:
	bool right;
	int& dir;
public:
	Turn(bool r, int& d, int l = 0) :Operation(l), right(r), dir(d) {}
	Node* execute() override;
	virtual Turn* clone() const override { return new Turn(*this); }
};

