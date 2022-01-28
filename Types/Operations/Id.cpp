#include "Id.h"

Node* Id::execute() {
	try {
		return (*callStack->top()).at(id)->clone();
	}
	catch (...) {
		std::string errStr = "Error: Unknown identificator \"" + id + "\", line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}