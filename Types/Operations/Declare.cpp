#include "Declare.h"
Node* Declare::execute() {
	if (compatible(type, first->execute())) {
		if (varTable.find(*id) == varTable.end()) {
			switch (type) {
				/*case VARBOOL:
					return varTable.insert({ *id, new Bool(new bool(toInt(first))) }).first->second;
				case CONSTBOOL:
					return varTable.insert({ *id, new ConstBool(new bool(toInt(first))) }).first->second;
				case VARINT:
					return varTable.insert({ *id, new Int(new int(toInt(first))) }).first->second;
				case CONSTINT:
					return varTable.insert({ *id, new ConstInt(new int(toInt(first))) }).first->second;
				case INTARR:
					return varTable.insert({ *id, new IntArray(dynamic_cast<ConstIntArray*>(first)->pop()) }).first->second;
				case CONSTINTARR:
					return varTable.insert({ *id, new ConstIntArray(dynamic_cast<ConstIntArray*>(first)->pop()) }).first->second;
				case BOOLARR:
					return varTable.insert({ *id, new BoolArray(dynamic_cast<ConstBoolArray*>(first)->pop()) }).first->second;
				case CONSTBOOLARR:
					return varTable.insert({ *id, new ConstBoolArray(dynamic_cast<ConstBoolArray*>(first)->pop()) }).first->second;
				case INTMATRIX:
					return varTable.insert({ *id, new IntMatrix(dynamic_cast<ConstIntMatrix*>(first)->pop()) }).first->second;
				case CONSTINTMATRIX:
					return varTable.insert({ *id, new ConstIntMatrix(dynamic_cast<ConstIntMatrix*>(first)->pop()) }).first->second;
				case BOOLMATRIX:
					return varTable.insert({ *id, new BoolMatrix(dynamic_cast<ConstBoolMatrix*>(first)->pop()) }).first->second;
				case CONSTBOOLMATRIX:
					return varTable.insert({ *id, new ConstBoolMatrix(dynamic_cast<ConstBoolMatrix*>(first)->pop()) }).first->second;*/
				auto v = dynamic_cast<ConstIntArray*>(first);
				case VARBOOL:
					return varTable.insert({ *id, new Bool(new bool(toInt(first->execute()))) }).first->second;
				case CONSTBOOL:
					return varTable.insert({ *id, new ConstBool(new bool(toInt(first->execute()))) }).first->second;
				case VARINT:
					return varTable.insert({ *id, new Int(new int(toInt(first->execute()))) }).first->second;
				case CONSTINT:
					return varTable.insert({ *id, new ConstInt(new int(toInt(first->execute()))) }).first->second;
				case INTARR:
					return varTable.insert({ *id, new IntArray(*dynamic_cast<ConstIntArray*>(first->execute())) }).first->second;
				case CONSTINTARR:
					return varTable.insert({ *id, new ConstIntArray(*dynamic_cast<ConstIntArray*>(first->execute())) }).first->second;
				case BOOLARR:
					return varTable.insert({ *id, new BoolArray(*dynamic_cast<ConstBoolArray*>(first->execute())) }).first->second;
				case CONSTBOOLARR:
					return varTable.insert({ *id, new ConstBoolArray(*dynamic_cast<ConstBoolArray*>(first->execute())) }).first->second;
				case INTMATRIX:
					return varTable.insert({ *id, new IntMatrix(*dynamic_cast<ConstIntMatrix*>(first->execute())) }).first->second;
				case CONSTINTMATRIX:
					return varTable.insert({ *id, new ConstIntMatrix(*dynamic_cast<ConstIntMatrix*>(first->execute())) }).first->second;
				case BOOLMATRIX:
					return varTable.insert({ *id, new BoolMatrix(*dynamic_cast<ConstBoolMatrix*>(first->execute())) }).first->second;
				case CONSTBOOLMATRIX:
					return varTable.insert({ *id, new ConstBoolMatrix(*dynamic_cast<ConstBoolMatrix*>(first->execute())) }).first->second;
				default:
					throw std::exception("Unknown type");
			}
		}
	}
	else
		throw std::exception("Wrong type");
}