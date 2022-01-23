#pragma once
#include "../Operation.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class MatrixMult : public Operation {
public:
	MatrixMult(Node* f, Node* s) : Operation(f, s) {}
	Node* execute() override;
};

