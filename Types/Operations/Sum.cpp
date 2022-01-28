#include "Sum.h"
Node* Sum::execute() {
	Node* f = nullptr;
	try {
		f = operand[0]->execute();
	}
	catch (std::exception& ex) {
		throw ex;
	}
	//auto f = operand[0];
	if (f->type() == INTARR || f->type() == CONSTINTARR) {
		auto vec = dynamic_cast<ConstIntArray*>(f)->getValue();
		int res = 0;
		for (auto k : vec)
			res += *k;
		return new Int(new int(res),line);
	}
	if (f->type() == INTMATRIX || f->type() == CONSTINTMATRIX) {
		auto matrix = dynamic_cast<ConstIntMatrix*>(f)->getMatrix();
		int res = 0;
		for (auto& row : matrix) {
			for (auto val : row)
				res += *val;
		}
		return new Int(new int(res),line);
	}
	std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
	throw std::exception(errStr.c_str());
}