#pragma once
#include "../Operation.h"
#include "../Functions.h"
class Declare :  public Operation {
protected:
	std::string* id;
	t type;
	std::map<std::string, Node*>& varTable;
public:
	Declare(t typ, std::string* name, Node* expr, std::map<std::string, Node*>& vTable) :Operation(expr, nullptr), varTable(vTable), id(name), type(typ) {}
	Node* execute() override;
};

