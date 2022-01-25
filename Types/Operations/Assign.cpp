#include "Assign.h"

Node* Assign::execute() {
	if (isVariable) {
		Node* expression = second->execute();
		if (isVariable) {
		auto i = varTable.find(*id);
			if (i == varTable.end())
				throw std::exception("No such variable");
			Node* variable = i->second;
			Node* v = nullptr;
			if (compatible(variable->type(), expression)) {
				switch (variable->type()) {
					case VARBOOL:
						v = new Bool(new bool(toInt(expression)));
						break;
					case VARINT:
						v = new Int(new int(toInt(expression)));
						break;
					case INTARR:
						v = new IntArray(*dynamic_cast<ConstIntArray*>(expression));
						break;
					case BOOLARR:
						v = new BoolArray(*dynamic_cast<ConstBoolArray*>(expression));
						break;
					case INTMATRIX:
						v = new IntMatrix(*dynamic_cast<ConstIntMatrix*>(expression));
						break;
					case BOOLMATRIX:
						v = new BoolMatrix(*dynamic_cast<ConstBoolMatrix*>(expression));
						break;
					default:
						throw std::exception("Cannot change value of constant");
				}
				delete i->second;
				i->second = v;
			}
			else
				throw std::exception("Wrong type");
		}
		else {
			Node* appeal = first;
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
							dynamic_cast<IntArray*>(appeal)->setValue(dynamic_cast<ConstIntArray*>(expression)->getValue());
						}
						catch (std::exception& ex) {
							throw ex;
						}
						break;
					case BOOLARR:
						try {
							dynamic_cast<BoolArray*>(appeal)->setValue(dynamic_cast<ConstBoolArray*>(expression)->getValue());
						}
						catch (std::exception& ex) {
							throw ex;
						}
						break;
					case INTMATRIX:
						try {
							dynamic_cast<IntMatrix*>(appeal)->setValue(dynamic_cast<ConstIntMatrix*>(expression)->getMatrix());
						}
						catch (std::exception& ex) {
							throw ex;
						}
						break;
					case BOOLMATRIX:
						try {
							dynamic_cast<BoolMatrix*>(appeal)->setValue(dynamic_cast<ConstBoolMatrix*>(expression)->getMatrix());
						}
						catch (std::exception& ex) {
							throw ex;
						}
						break;
					default:
						throw std::exception("Cannot change value of constant");
				}
			}
		}
	}
}