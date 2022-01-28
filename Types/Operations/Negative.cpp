#include "Negative.h"

Node* Negative::execute() {
	Node* n;
	try {
		n = operand[0]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
	auto i = dynamic_cast<ConstInt*>(n);
	if (i)
		return new Int(new int(-i->getValue()), i->getLine());
	auto b = dynamic_cast<ConstBool*>(n);
	if (b)
		return new Int(new int(-b->getValue()), b->getLine());
	auto ia = dynamic_cast<ConstIntArray*>(n);
	if (ia)
		return new IntArray(ia->negativeValue(), ia->getLine());
	auto im = dynamic_cast<ConstIntMatrix*>(n);
	if (im)
		return new IntMatrix(im->negativeValue(), im->getLine());
	std::string errStr = "Error: Wrong operand type, line " + std::to_string(line);
	throw std::exception(errStr.c_str());
}
