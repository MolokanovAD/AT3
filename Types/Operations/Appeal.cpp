#include "Appeal.h"

Node* Appeal::execute() {
	auto it = (*callStack->top()).find(id);
	if (it != (*callStack->top()).end()) {
		switch (type) {
			case COORDINATES:
				if (dynamic_cast<ConstIntMatrix*>(it->second)) {
					try {
						return getIntValue(it->second, operand[0]->execute(), operand[1]->execute(), line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
				}
				else if (dynamic_cast<ConstBoolMatrix*>(it->second)) {
					try {
						return getBoolValue(it->second, operand[0]->execute(), operand[1]->execute(), line);
					}
					catch (std::exception& ex) {
						throw ex;
					}
				}
				break;
			case COLUMNS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = nullptr;
					try {
						p = operand[0]->execute();
					}
					catch (std::exception& ex) {
						throw ex;
					}
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 0, line);
						}
						catch (std::exception& ex) {
							throw ex;
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 0, line);
							}
							catch (std::exception& ex) {
								throw ex;
							}
						}
					}
				}
				break;
			case ROWS:
				if (compatible(t::CONSTINTMATRIX, it->second) || compatible(t::CONSTBOOLMATRIX, it->second)) {
					Node* p = nullptr;
					try {
						p = operand[0]->execute();
					}
					catch (std::exception& ex) {
						throw ex;
					}
					if (compatible(t::CONSTINT, p)) {
						try {
							return getVec(it->second, p, 1, line);
						}
						catch (std::exception& ex) {
							throw ex;
						}
					}
					else {
						if (dynamic_cast<ConstIntArray*>(p)) {
							try {
								return getMatrix(it->second, p, 1, line);
							}
							catch (std::exception& ex) {
								throw ex;
							}
						}
					}
				}
				break;
			case LOGICAL: {
					Node* p = nullptr;
					try {
						p = operand[0]->execute();
					}
					catch (std::exception& ex) {
						throw ex;
					}
					try {
						return matrixFromLogical(it->second, p, line);
					}
					catch (std::exception& ex1) {
						try {
							return arrayFromArray(it->second, p, line);
						}
						catch (std::exception& ex2) {
							int i = 0;
							try {
								i = toInt(p);
							}
							catch (std::exception& ex) {
								throw ex2;
							}
							try {
								return valFromArray(it->second, i, line);
							}
							catch (std::exception& ex3) {
								throw ex3;
							}
						}
						throw ex1;
					}
					break;
				}
			default:
				break;
		}
	}
	else {
		std::string errStr = "Error: Unknown identificator \"" + id + "\", line " + std::to_string(line);
		throw std::exception(errStr.c_str());
	}
}