#pragma once
#include "../Operation.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class MatrixMult : public Operation {
public:
	MatrixMult(Node* f, Node* s, int l = 0) : Operation(f, s, l) {}
	Node* execute() override;
	virtual MatrixMult* clone() const override { return new MatrixMult(*this); }
};

