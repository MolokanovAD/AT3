#include "Declare.h"
#include "Appeal.h"

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
			if (dynamic_cast<Appeal*>(operand[0]))
				p = p->clone();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		if (compatible(type, p)) {
			if ((*callStack->top()).find(id) == (*callStack->top()).end()) {
				switch (type) {
					case VARBOOL:
						(*callStack->top()).insert({ id, new Bool(new bool(toInt(p)), line) });
						break;
					case CONSTBOOL:
						(*callStack->top()).insert({ id, new ConstBool(new bool(toInt(p)),t::CONSTBOOL, line) });
						break;
					case VARINT:
						(*callStack->top()).insert({ id, new Int(new int(toInt(p)), line) });
						break;
					case CONSTINT:
						(*callStack->top()).insert({ id, new ConstInt(new int(toInt(p)),t::CONSTINT, line) });
						break;
					case INTARR:
						(*callStack->top()).insert({ id, new IntArray(dynamic_cast<ConstIntArray*>(p)->pop(), line) });
						break;
					case CONSTINTARR:
						(*callStack->top()).insert({ id, new ConstIntArray(dynamic_cast<ConstIntArray*>(p)->pop(),t::CONSTINTARR, line) });
						break;
					case BOOLARR:
						(*callStack->top()).insert({ id, new BoolArray(dynamic_cast<ConstBoolArray*>(p)->pop(), line) });
						break;
					case CONSTBOOLARR:
						(*callStack->top()).insert({ id, new ConstBoolArray(dynamic_cast<ConstBoolArray*>(p)->pop(),t::CONSTBOOLARR, line) });
						break;
					case INTMATRIX:
						(*callStack->top()).insert({ id, new IntMatrix(dynamic_cast<ConstIntMatrix*>(p)->pop(), line) });
						break;
					case CONSTINTMATRIX:
						(*callStack->top()).insert({ id, new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(p)->pop(),t::CONSTINTMATRIX, line) });
						break;
					case BOOLMATRIX:
						(*callStack->top()).insert({ id, new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(p)->pop(), line) });
						break;
					case CONSTBOOLMATRIX:
						(*callStack->top()).insert({ id, new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(p)->pop(),t::CONSTBOOLMATRIX, line) });
						break;
				/*switch (type) {
					case VARBOOL:
						(*callStack->top()).insert({ id, new Bool(new bool(toInt(p)), line) });
						break;
					case CONSTBOOL:
						(*callStack->top()).insert({ id, new ConstBool(new bool(toInt(p)),t::CONSTBOOL, line) });
						break;
					case VARINT:
						(*callStack->top()).insert({ id, new Int(new int(toInt(p)), line) });
						break;
					case CONSTINT:
						(*callStack->top()).insert({ id, new ConstInt(new int(toInt(p)),t::CONSTINT, line) });
						break;
					case INTARR:
						(*callStack->top()).insert({ id, new IntArray(*dynamic_cast<ConstIntArray*>(p), line) });
						break;
					case CONSTINTARR:
						(*callStack->top()).insert({ id, new ConstIntArray(*dynamic_cast<ConstIntArray*>(p),t::CONSTINTARR, line) });
						break;
					case BOOLARR:
						(*callStack->top()).insert({ id, new BoolArray(*dynamic_cast<ConstBoolArray*>(p), line) });
						break;
					case CONSTBOOLARR:
						(*callStack->top()).insert({ id, new ConstBoolArray(*dynamic_cast<ConstBoolArray*>(p),t::CONSTBOOLARR, line) });
						break;
					case INTMATRIX:
						(*callStack->top()).insert({ id, new IntMatrix(*dynamic_cast<ConstIntMatrix*>(p), line) });
						break;
					case CONSTINTMATRIX:
						(*callStack->top()).insert({ id, new ConstIntMatrix(*dynamic_cast<ConstIntMatrix*>(p),t::CONSTINTMATRIX, line) });
						break;
					case BOOLMATRIX:
						(*callStack->top()).insert({ id, new BoolMatrix(*dynamic_cast<ConstBoolMatrix*>(p), line) });
						break;
					case CONSTBOOLMATRIX:
						(*callStack->top()).insert({ id, new ConstBoolMatrix(*dynamic_cast<ConstBoolMatrix*>(p),t::CONSTBOOLMATRIX, line) });
						break;*/
					default:
						std::string errStr = "Error: Unknown variable type, line " + std::to_string(line);
						throw std::exception(errStr.c_str());
				}
				return nullptr;
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
		return nullptr;
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