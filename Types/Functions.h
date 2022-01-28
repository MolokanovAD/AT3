#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include "Ints/Int.h"
#include "Bools/Bool.h"
#include "IntArrays/IntArray.h"
#include "BoolArrays/BoolArray.h"
#include "IntMatrices/IntMatrix.h"
#include "BoolMatrices/BoolMatrix.h"
#include "Operations/Function.h"
class IntArray;
class BoolArray;
bool compatible(Node* first, Node* second);
bool compatible(t type, Node* node);
bool compatible(t type, Node* first, Node* second);
bool addable(Node* first, Node* second);
int toInt(Node* n);
Node* createContainer(Node* child);
ConstInt* getIntValue(Node* m, Node* f, Node* s, int l);
ConstBool* getBoolValue(Node* m, Node* f, Node* s, int l);
ConstIntArray* getIntVec(Node* m, Node* r, bool mode, int l);
ConstBoolArray* getBoolVec(Node* m, Node* r, bool mode, int l);
Node* getVec(Node* m, Node* r, bool mode, int l);
ConstIntMatrix* getIntMatrix(Node* m, Node* r, bool mode, int l);
ConstBoolMatrix* getBoolMatrix(Node* m, Node* r, bool mode, int l);
Node* getMatrix(Node* m, Node* r, bool mode, int l);
ConstIntMatrix* intMatrixFromLogical(Node* m, Node* r, int l);
ConstBoolMatrix* boolMatrixFromLogical(Node* m, Node* r, int l);
Node* matrixFromLogical(Node* m, Node* r, int l);
ConstIntArray* intArrayFromArray(Node* m, Node* r, int l);
ConstBoolArray* boolArrayFromArray(Node* m, Node* r, int l);
Node* arrayFromArray(Node* m, Node* r, int l);
ConstInt* intFromArray(Node* arr, int i, int l);
ConstBool* boolFromArray(Node* arr, int i, int l);
Node* valFromArray(Node* arr, int i, int l);
bool isMatrix(Node* n);
bool isConst(Node* n);
bool multiplicable(Node* f, Node* s);
std::vector<std::vector<char>> parseMap(const std::string& filename, int& xx, int& yy, int& dir);
void freeStacks(CallStack* cs, FunStack* fs);
void printVarTable(std::map<std::string, Node*>* varTable);
//void printFunTable(std::map<std::string, Function*>& functionTable);
bool isDirection(ConstIntArray* vec);