#pragma once
#include "../Operation.h"
#include "../IntArrays/IntArray.h"
#include "../BoolArrays/BoolArray.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class Sum : public Operation {
public:
	Sum(Node* f, int l = 0) :Operation(f, l) {}
	Node* execute() override;
	virtual Sum* clone() const override { return new Sum(*this); }
	virtual ~Sum() {}
};

