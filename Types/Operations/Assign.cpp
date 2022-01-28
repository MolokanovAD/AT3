#include "Assign.h"
#include "Appeal.h"

Node* Assign::execute() {
	bool isVariable = (operand.size() == 1);
	if (isVariable) {
		auto i = (*callStack->top()).find(id);
		if (i == (*callStack->top()).end())
			throw std::exception("No such variable");
		Node* expression = nullptr;
		try {
			expression = operand[0]->execute();
			if (dynamic_cast<Appeal*>(operand[0]))
				expression = expression->clone();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		Node* variable = i->second;
		Node* v = nullptr;
		if (compatible(variable->type(), expression)) {
			switch (variable->type()) {
				case VARBOOL:
					v = new Bool(new bool(toInt(expression)), line);
					break;
				case VARINT:
					v = new Int(new int(toInt(expression)), line);
					break;
				case INTARR:
					v = new IntArray(dynamic_cast<ConstIntArray*>(expression)->pop(), line);
					break;
				case BOOLARR:
					v = new BoolArray(dynamic_cast<ConstBoolArray*>(expression)->pop(), line);
					break;
				case INTMATRIX:
					v = new IntMatrix(dynamic_cast<ConstIntMatrix*>(expression)->pop(), line);
					break;
				case BOOLMATRIX:
					v = new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(expression)->pop(), line);
					break;
				/*case VARBOOL:
					v = new Bool(new bool(toInt(expression)),line);
					break;
				case VARINT:
					v = new Int(new int(toInt(expression)), line);
					break;
				case INTARR:
					v = new IntArray(*dynamic_cast<ConstIntArray*>(expression), line);
					break;
				case BOOLARR:
					v = new BoolArray(*dynamic_cast<ConstBoolArray*>(expression), line);
					break;
				case INTMATRIX:
					v = new IntMatrix(*dynamic_cast<ConstIntMatrix*>(expression), line);
					break;
				case BOOLMATRIX:
					v = new BoolMatrix(*dynamic_cast<ConstBoolMatrix*>(expression), line);
					break;*/
				default:
					std::string errStr = "Error: Cannot change value of constant, line " + std::to_string(line);
					throw std::exception(errStr.c_str());
			}
			delete i->second;
			i->second = v;
		}
		else{
			std::string errStr = "Error: type mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	else {
		Node* appeal = operand[0]->execute();
		Node* expression = nullptr;
		try {
			expression = operand[1]->execute();
			if (dynamic_cast<Appeal*>(operand[0]))
				expression = expression->clone();
		}
		catch (std::exception& ex) {
			throw ex;
		}
		if (compatible(appeal->type(), expression)) {
			switch (appeal->type()) {
				case VARBOOL:
					dynamic_cast<Bool*>(appeal)->setValue(toInt(expression));
					break;
				case VARINT:
					dynamic_cast<Int*>(appeal)->setValue(toInt(expression));
					break;
				case INTARR:
					try {
						dynamic_cast<IntArray*>(appeal)->setValue(dynamic_cast<ConstIntArray*>(expression)->getValue(), line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
					break;
				case BOOLARR:
					try {
						dynamic_cast<BoolArray*>(appeal)->setValue(dynamic_cast<ConstBoolArray*>(expression)->getValue(), line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
					break;
				case INTMATRIX:
					try {
						dynamic_cast<IntMatrix*>(appeal)->setValue(dynamic_cast<ConstIntMatrix*>(expression)->getMatrix(),line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
					break;
				case BOOLMATRIX:
					try {
						dynamic_cast<BoolMatrix*>(appeal)->setValue(dynamic_cast<ConstBoolMatrix*>(expression)->getMatrix(), line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
					break;
				default:
					std::string errStr = "Error: Cannot change value of this type, line " + std::to_string(line);
					throw std::exception(errStr.c_str());
			}
			delete expression;//!!!
		}
		else {
			std::string errStr = "Error: Type mismatch, line " + std::to_string(line);
			throw std::exception(errStr.c_str());
		}
	}
	return nullptr;
}