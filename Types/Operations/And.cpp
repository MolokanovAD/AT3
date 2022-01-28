#include "And.h"

Node* And::execute() {
    /*Node* f = first->execute();
    Node* s = second->execute();*/	
	Node* f = nullptr, * s = nullptr;
	try {
		f = operand[0]->execute();
		s = operand[1]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
    if (compatible(t::CONSTINT, f, s))
        return new Bool(new bool(getInt(f) && getInt(s)),line);
	std::string errStr = "Error: Bool expression is required " + std::to_string(line);
	throw std::exception(errStr.c_str());
}
