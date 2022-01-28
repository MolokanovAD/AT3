#pragma once
#include "../Operation.h"
#include "../Functions.h"
#include "Function.h"

class Declare :  public Operation {
protected:
	std::string id;
	t type;
	CallStack* callStack;
	FunStack* funStack;
public:
	Declare(int typ, std::string name, CallStack* vTable, int l = 0):Operation(l), type(t(typ)), id(name),callStack(vTable), funStack(nullptr) {}
	Declare(t typ, std::string name, Node* expr, CallStack* vTable, int l = 0) :Operation(expr,l), callStack(vTable), id(name), type(typ),funStack(nullptr) {}
	Declare(int typ, std::string name, Node* expr, CallStack* vTable, int l = 0) :Operation(expr,l), callStack(vTable), id(name), type(t(typ)), funStack(nullptr) {}
	Declare(std::string name, FunStack* fs, Node* f, int l = 0) :Operation(f,l), id(name), funStack(fs), callStack(nullptr) {}
	void setExpr(Node* e) ;
	t varType() { return type; }
	std::string getName()const { return id; }
	Node* getValue();
	bool fun()const { return callStack; }
	Node* execute() override;
	virtual Declare* clone() const override { return new Declare(*this); }
	virtual ~Declare() {}
};