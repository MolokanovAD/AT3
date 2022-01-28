#include "If.h"

Node* If::execute() {
	Node* p = nullptr;
	bool expr = false;
	try {
		p = operand[0]->execute();
		expr = getInt(p);
		if (expr)
			operand[1]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
}