#include "Call.h"

void Call::deleteFrame() {
	for (auto& i : *callStack->top())
		delete i.second;
	callStack->top()->clear();
	callStack->pop();
	for (auto& i : *funStack->top())
		delete i.second;
	funStack->top()->clear();
	funStack->pop();
}

void Call::formFunFrame() {
	auto newFrame = new std::map<std::string, Function*>();
	for (auto& i : (*funStack->top())) {
		newFrame->insert({ i.first,i.second->clone() });
	}
	funStack->push(newFrame);
}

Node* Call::execute() {
	//std::cout << "_______________________" << id << "_______________________" << std::endl;
	auto it = funStack->top()->find(id);
	if (it == funStack->top()->end()) {
		std::string errStr = "Error: Unknown identificator \"" + id + "\", line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
	Function* fun = it->second->clone();
	ExprSequence* parValues = dynamic_cast<ExprSequence*>(operand[0]);
	int parAmount = parValues->size();
	int max = fun->paramsMax();
	if (parAmount > max) {
		std::string errStr = "Error: Wrong number of parameters in function \"" + fun->getName() + "\", line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
	for (int i = 0; i < parAmount; i++) {//counting parameters' values
		Node* res;
		try {
			res = (*parValues)[i]->execute();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		Declare* p = dynamic_cast<Declare*>(fun->param(i));
		if (!compatible(p->varType(), res)) {
			std::string errStr = "Error: Parameter type mismatch in function \"" + id + "\", line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
		p->setExpr(res);
	}
	for (int i = parAmount; i < max; i++) {
		Declare* p = dynamic_cast<Declare*>(fun->param(i));
		if (!p->size()) {	//parameter is not optional
			std::string errStr = "Error: Wrong number of parameters in function \"" + id + "\", line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	callStack->push(new std::map<std::string, Node*>());
	formFunFrame();
	//funStack->push(new std::map<std::string, Function*>());
	for (int i = 0; i < max; i++) {
		try {
			fun->param(i)->execute();//declaring parameters
		}
		catch (std::exception& ex) {
			deleteFrame();
			throw ex;
		}
	}
	fun->body()->execute();
	for (int i = 0; i < fun->returnValuesAmount(); i++) {//returning values
		Declare* retVal = dynamic_cast<Declare*>(fun->returnValue(i));
		if (!retVal) {
			std::string errStr = "Error: Error in return value, line " + std::to_string(line);
			deleteFrame();
			throw std::exception(errStr.c_str());
		}
		auto it = callStack->top()->find(retVal->getName());
		if (it == callStack->top()->end()) {
			std::string errStr = "Error: Return value " + retVal->getName() + " must be declared, line " + std::to_string(line);
			deleteFrame();
			throw std::exception(errStr.c_str());
		}
		//if(!compatible(retVal->varType(), it->second)) {
		if (retVal->varType() != it->second->type()) {
			std::string errStr = "Error: Return value type mismatch, line " + std::to_string(line);
			deleteFrame();
			throw std::exception(errStr.c_str());
		}
		retVal->setExpr(it->second->clone());
	}
	deleteFrame();
	/*for (auto& i : *funStack->top())
		delete i.second;
	funStack->top()->clear();
	funStack->pop();*/
	for (int i = 0; i < fun->returnValuesAmount(); i++) {//declaring returned values
		Declare* retVal = dynamic_cast<Declare*>(fun->returnValue(i));
		try {
			retVal->execute();
		}
		catch (std::runtime_error& e) {
			Assign* as = new Assign(retVal->getName(), retVal->getValue(), callStack);
			retVal->dump();
			try {
				as->execute();
			}
			catch (std::exception& ex) {
				throw ex;
			}
			delete as;
		}
		catch (std::exception& ex) {
			throw ex;
		}
	}
	delete fun;
	return nullptr;
}