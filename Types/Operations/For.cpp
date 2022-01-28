#include "For.h"

For::For(std::string name, Node* expr1, Node* expr2, Node* sntns, CallStack* vTable, int l):Operation(l),id(name),callStack(vTable) {
	operand.push_back(expr1);
	operand.push_back(expr2);
	operand.push_back(sntns);
}

Node* For::execute() {
	int from, to;
	try {
		from = getInt(operand[0]->execute());
		to = getInt(operand[1]->execute());
		dynamic_cast<Int*>((*callStack->top()).at(id))->setValue(from);
		for (; dynamic_cast<Int*>((*callStack->top()).at(id))->getValue() < to;dynamic_cast<Int*>((*callStack->top()).at(id))->inc()) {
			operand[2]->execute();
		}
	}
	catch (std::exception& ex) {
		throw ex;
	}
	return nullptr;
}