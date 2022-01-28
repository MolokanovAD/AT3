#include "Declare.h"

void Declare::setExpr(Node* e) {
	if (operand.size()) {
		delete operand[0];
		operand[0] = e;
	}
	else
		operand.push_back(e);
}

Node* Declare::getValue() {
	if (operand.size())
		return operand[0];
	throw std::exception("No value");
}

Node* Declare::execute() {
	if (!funStack) {
		Node* p = nullptr;
		try {
			p = operand[0]->execute();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		if (compatible(type, p)) {
			if ((*callStack->top()).find(id) == (*callStack->top()).end()) {
				switch (type) {
					case VARBOOL:
						return (*callStack->top()).insert({ id, new Bool(new bool(toInt(p)), line) }).first->second;
					case CONSTBOOL:
						return (*callStack->top()).insert({ id, new ConstBool(new bool(toInt(p)),t::CONSTBOOL, line) }).first->second;
					case VARINT:
						return (*callStack->top()).insert({ id, new Int(new int(toInt(p)), line) }).first->second;
					case CONSTINT:
						return (*callStack->top()).insert({ id, new ConstInt(new int(toInt(p)),t::CONSTINT, line) }).first->second;
					case INTARR:
						return (*callStack->top()).insert({ id, new IntArray(*dynamic_cast<ConstIntArray*>(p), line) }).first->second;
					case CONSTINTARR:
						return (*callStack->top()).insert({ id, new ConstIntArray(*dynamic_cast<ConstIntArray*>(p),t::CONSTINTARR, line) }).first->second;
					case BOOLARR:
						return (*callStack->top()).insert({ id, new BoolArray(*dynamic_cast<ConstBoolArray*>(p), line) }).first->second;
					case CONSTBOOLARR:
						return (*callStack->top()).insert({ id, new ConstBoolArray(*dynamic_cast<ConstBoolArray*>(p),t::CONSTBOOLARR, line) }).first->second;
					case INTMATRIX:
						return (*callStack->top()).insert({ id, new IntMatrix(*dynamic_cast<ConstIntMatrix*>(p), line) }).first->second;
					case CONSTINTMATRIX:
						return (*callStack->top()).insert({ id, new ConstIntMatrix(*dynamic_cast<ConstIntMatrix*>(p),t::CONSTINTMATRIX, line) }).first->second;
					case BOOLMATRIX:
						return (*callStack->top()).insert({ id, new BoolMatrix(*dynamic_cast<ConstBoolMatrix*>(p), line) }).first->second;
					case CONSTBOOLMATRIX:
						return (*callStack->top()).insert({ id, new ConstBoolMatrix(*dynamic_cast<ConstBoolMatrix*>(p),t::CONSTBOOLMATRIX, line) }).first->second;
					default:
						std::string errStr = "Error: Unknown variable type, line " + std::to_string(line);
						throw std::exception(errStr.c_str());
				}
			}
			else {
				std::string errStr = "Error: Redeclaration, line " + std::to_string(line);
				throw std::runtime_error(errStr.c_str());
			}
		}
		else
		{
			std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	else {
		if (!funStack->top()->insert({ id,dynamic_cast<Function*>(operand[0]) }).second) {
			std::string errStr = "Error: Redeclaration, line " + std::to_string(line);
			throw std::exception(errStr.c_str()); 
		}
		operand[0] = nullptr;
		operand.clear();
		/*try {
			funStack->top()->insert({ id,dynamic_cast<Function*>(operand[0]) });
			operand[0] = nullptr;
			operand.clear();
		}
		catch (std::exception& ex) {
			std::string errStr = "Error: Redeclaration, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}*/
	}

}