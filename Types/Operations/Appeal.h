#pragma once
#include "../Operation.h"
#include "../Functions.h"
enum APPEAL {
	COORDINATES,
	COLUMNS,
	ROWS,
	LOGICAL
};

class Appeal :public Operation {
protected:
	std::string* id;
	std::map<std::string, Node*>& varTable;
	APPEAL type;
public:
	Appeal(std::string* name, Node* f, Node* s, std::map<std::string, Node*>& vTable, APPEAL t):Operation(f,s), id(name), varTable(vTable), type(t){}
	Node* execute() override;
};

