#pragma once
#include <map>
#include <iostream>
#include "Ints/Int.h"
#include "Bools/Bool.h"
#include "IntArrays/IntArray.h"
#include "BoolArrays/BoolArray.h"
#include "IntMatrices/IntMatrix.h"
#include "BoolMatrices/BoolMatrix.h"
class IntArray;
class BoolArray;
bool compatible(Node* first, Node* second);
bool compatible(t type, Node* node);
bool compatible(t type, Node* first, Node* second);
bool addable(Node* first, Node* second);
int toInt(Node* n);
bool insertVar(t type, std::string* id, Node* expr, std::map<std::string, Node*>& varTable);
Node* assignVar(t type, Node* expr);
Node* createContainer(Node* child);
void addElementToContainer(Node* cnt, Node* e);
ConstInt* getIntValue(Node* m, Node* f, Node* s);
ConstBool* getBoolValue(Node* m, Node* f, Node* s);
ConstIntArray* getIntVec(Node* m, Node* r, bool mode);
ConstBoolArray* getBoolVec(Node* m, Node* r, bool mode);
Node* getVec(Node* m, Node* r, bool mode);
ConstIntMatrix* getIntMatrix(Node* m, Node* r, bool mode);
ConstBoolMatrix* getBoolMatrix(Node* m, Node* r, bool mode);
Node* getMatrix(Node* m, Node* r, bool mode);
//bool correctLogicalMatrix(ConstBoolMatrix* lm, int l, int h);
ConstIntMatrix* intMatrixFromLogical(Node* m, Node* r);
ConstBoolMatrix* boolMatrixFromLogical(Node* m, Node* r);
Node* matrixFromLogical(Node* m, Node* r);
bool isMatrix(Node* n);
bool isConst(Node* n);
bool multiplicable(Node* f, Node* s);
Int* minus(Node* node);

void printVarTable(std::map<std::string, Node*>& varTable);