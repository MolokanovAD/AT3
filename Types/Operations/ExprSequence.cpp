#include "ExprSequence.h"

Node* ExprSequence::execute() {
	if (operand.size() != 0) {
		Node* res;
		Node* p = nullptr;
		try {
			p = operand[0]->execute();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		switch (p->type()) {
			case VARBOOL:
				res = new BoolArray({ dynamic_cast<ConstBool*>(p)->pop() });
				break;
			case CONSTBOOL:
				res = new BoolArray({ dynamic_cast<ConstBool*>(p)->pop() });
				break;
			case VARINT:
				res = new IntArray({ dynamic_cast<ConstInt*>(p)->pop() });
				break;
			case CONSTINT:
				res = new IntArray({ dynamic_cast<ConstInt*>(p)->pop() });
				break;
			case INTARR:
				res = new IntMatrix({ dynamic_cast<ConstIntArray*>(p)->pop() });
				break;
			case CONSTINTARR:
				res = new IntMatrix({ dynamic_cast<ConstIntArray*>(p)->pop() });
				break;
			case BOOLARR:
				res = new BoolMatrix({ dynamic_cast<ConstBoolArray*>(p)->pop() });
				break;
			case CONSTBOOLARR:
				res = new BoolMatrix({ dynamic_cast<ConstBoolArray*>(p)->pop() });
				break;
			default:
				std::string errStr = "Error: Unknown variable type, line " + std::to_string(line);
				throw std::exception(errStr.c_str());
		}
		for (int i = 1; i < operand.size(); i++) {
			try {
				Node* e = operand[i]->execute();
				switch (res->type()) {
					case INTARR:
						dynamic_cast<IntArray*>(res)->addElement(e);
						break;
					case BOOLARR:
						dynamic_cast<BoolArray*>(res)->addElement(e);
						break;
					case INTMATRIX:
						dynamic_cast<IntMatrix*>(res)->addElement(e);
						break;
					case BOOLMATRIX:
						dynamic_cast<BoolMatrix*>(res)->addElement(e);
						break;
					default:
						std::string errStr = "Error: Unknown variable type, line " + std::to_string(line);
						throw std::exception(errStr.c_str());
				}
			}
			catch (std::exception& ex) {
				throw ex;
			}
		}
		return res;
	}
}