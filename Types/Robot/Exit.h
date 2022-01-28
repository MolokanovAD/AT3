#pragma once
#include "../Operation.h"
class Exit : public Operation {
private:
	int& x;
	int& y;
	int& dir;
	std::vector<std::vector<char>>& lab;
public:
	Exit(std::vector<std::vector<char>>& labyr, int& xx, int& yy, int& d, int l = 0) :Operation(l), lab(labyr), x(xx), y(yy), dir(d) {}
	Node* execute() override;
	virtual Exit* clone() const override { return new Exit(*this); }
};

