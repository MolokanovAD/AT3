#pragma once
#include "../Operation.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class ElemMult : public Operation{
public:
	ElemMult(Node* f, Node* s):Operation(f,s) {}
	Node* execute() override;
};

