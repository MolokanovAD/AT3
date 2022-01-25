#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Assign : public Operation {
protected:
	bool isVariable;
	std::string* id;
	std::map<std::string, Node*>& varTable;
public:
	Assign(std::string* name, Node* expr, std::map<std::string, Node*>& vTable) :Operation(nullptr, expr), varTable(vTable), id(name),isVariable(true) {}
	Assign(Node* appeal, Node* expr, std::map<std::string, Node*>& vTable) :Operation(appeal, expr), varTable(vTable), isVariable(false) {}
	Node* execute() override;
};

