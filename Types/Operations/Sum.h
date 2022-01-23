#pragma once
#include "../Operation.h"
#include "../IntArrays/IntArray.h"
#include "../BoolArrays/BoolArray.h"
#include "../IntMatrices/IntMatrix.h"
#include "../BoolMatrices/BoolMatrix.h"
class Sum : public Operation {
public:
	Sum(Node* f) :Operation(f, nullptr) {}
	Node* execute() override;
};

