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
Int* castToInt(Node* node);
bool insertVar(t type, std::string* id, Node* expr, std::map<std::string, Node*>& varTable);
Node* assignVar(t type, Node* expr);
Node* createContainer(Node* child);
void addElementToContainer(Node* cnt, Node* e);
Int* getIntValue(Node* m, Node* f, Node* s);
Bool* getBoolValue(Node* m, Node* f, Node* s);
IntArray* getIntVec(Node* m, Node* r, bool mode);
BoolArray* getBoolVec(Node* m, Node* r, bool mode);
Node* getVec(Node* m, Node* r, bool mode);
IntMatrix* getIntMatrix(Node* m, Node* r, bool mode);
BoolMatrix* getBoolMatrix(Node* m, Node* r, bool mode);
Node* getMatrix(Node* m, Node* r, bool mode);
//bool correctLogicalMatrix(ConstBoolMatrix* lm, int l, int h);
IntMatrix* intMatrixFromLogical(Node* m, Node* r);
BoolMatrix* boolMatrixFromLogical(Node* m, Node* r);
Node* matrixFromLogical(Node* m, Node* r);
bool isMatrix(Node* n);
bool multiplicable(Node* f, Node* s);
Int* minus(Node* node);

void printVarTable(std::map<std::string, Node*>& varTable);