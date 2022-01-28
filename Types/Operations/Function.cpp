#include "Function.h"

Function::Function(Node* returnVals, std::string n, Node* params, Node* sents, CallStack* vT, int l) : Operation(l), callStack(vT), name(n){
	operand.push_back(returnVals);
	operand.push_back(params);
	operand.push_back(sents);
}

size_t Function::paramsMax() const {
	Parameters* par = dynamic_cast<Parameters*>(operand[1]);
	if(par)
		return par->size();
	throw std::exception("Error in parameters");
}

Node* Function::param(int index) {
	Parameters* par = dynamic_cast<Parameters*>(operand[1]);
	if (index > -1 && index < par->size())
		return (*par)[index];
}

Node* Function::returnValue(int index) {
	Parameters* ret = dynamic_cast<Parameters*>(operand[0]);
	if (index > -1 && index < ret->size())
		return (*ret)[index];
}
