#pragma once
#include "../Operation.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class ElemMult : public Operation{
public:
	ElemMult(Node* f, Node* s, int l = 0):Operation(f,s,l) {}
	Node* execute() override;
	virtual ElemMult* clone() const override { return new ElemMult(*this); }
	virtual ~ElemMult() {}
};

