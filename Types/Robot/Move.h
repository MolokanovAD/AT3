#pragma once
#include "../Operation.h"
#include "../IntArrays/ConstIntArray.h"
#include "../Functions.h"

class Move : public Operation {
private:
	int& x;
	int& y;
	int& dir;
	std::vector<std::vector<char>>& lab;
public:
	Move(Node* expr, std::vector<std::vector<char>>& labyr, int& xx, int& yy, int& d, int l = 0):Operation(expr,l), lab(labyr), x(xx), y(yy),dir(d){}
	Node* execute() override;
	virtual Move* clone() const override { return new Move(*this); }
};

